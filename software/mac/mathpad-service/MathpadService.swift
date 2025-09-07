import Foundation
import IOKit
import IOKit.hid
import CoreGraphics
import AppKit
import Carbon.HIToolbox
// Add this to the top of your Swift file, after the imports

struct ServiceInfo {
    static let version = "1.0.0"
    static let buildDate = "2025-01-01"
    static let identifier = "com.mathpad.unicode-service"

    static var fullVersionString: String {
        return "\(version) (built \(buildDate))"
    }
}

// Add this function to handle version command
func handleVersionCommand() {
    print("Mathpad Unicode Service v\(ServiceInfo.version)")
    print("Build date: \(ServiceInfo.buildDate)")
    print("Identifier: \(ServiceInfo.identifier)")
    exit(0)
}

// Modify your main function to handle command line arguments
// Add this before your existing code in main or wherever you start the service

// Handle command line arguments
if CommandLine.arguments.count > 1 {
    let argument = CommandLine.arguments[1].lowercased()
    switch argument {
    case "--version", "-v", "version":
        handleVersionCommand()
    case "--help", "-h", "help":
        print("Mathpad Unicode Service v\(ServiceInfo.version)")
        print("Usage:")
        print("  mathpad-service           Start the service")
        print("  mathpad-service --version Show version information")
        print("  mathpad-service --help    Show this help")
        exit(0)
    default:
        print("Unknown argument: \(argument)")
        print("Use --help for usage information")
        exit(1)
    }
}

class HybridUnicodeService {
    private var hidManager: IOHIDManager?
    private let vendorID: Int = 0x1209      // Mathpad VID
    private let productID: Int = 0x2211     // Mathpad PID
    private let customUsagePage: Int = 0xFF60  // QMK Raw HID usage page
    private let unicodeUsage: Int = 0x61       // QMK Raw HID usage ID
    private let pidFilePath: String

    init() {
        // Create PID file path in temp directory
        let tempDir = NSTemporaryDirectory()
        self.pidFilePath = "\(tempDir)mathpad_service.pid"

        // Check for existing instance before proceeding
        guard checkSingleInstance() else {
            print("[ERROR] Another instance of MathpadService is already running")
            print("[ERROR] PID file exists at: \(pidFilePath)")
            exit(1)
        }

        // Create PID file
        createPIDFile()

        // Setup signal handlers for cleanup
        setupSignalHandlers()

        // Request permissions on first run to make service appear in privacy settings
        requestPermissions()

        setupHIDManager()
    }

    private func setupHIDManager() {
        hidManager = IOHIDManagerCreate(kCFAllocatorDefault, IOOptionBits(kIOHIDOptionsTypeNone))

        guard let manager = hidManager else {
            print("Failed to create HID manager")
            return
        }

        // Set up device matching for Mathpad
        let deviceMatch: [String: Any] = [
            kIOHIDVendorIDKey: vendorID,
            kIOHIDProductIDKey: productID,
            kIOHIDPrimaryUsagePageKey: customUsagePage,
            kIOHIDPrimaryUsageKey: unicodeUsage
        ]

        IOHIDManagerSetDeviceMatching(manager, deviceMatch as CFDictionary)

        // Set up callbacks
        let deviceMatchingCallback: IOHIDDeviceCallback = { context, result, sender, device in
            let service = Unmanaged<HybridUnicodeService>.fromOpaque(context!).takeUnretainedValue()
            service.deviceConnected(device: device)
        }

        let deviceRemovalCallback: IOHIDDeviceCallback = { context, result, sender, device in
            let service = Unmanaged<HybridUnicodeService>.fromOpaque(context!).takeUnretainedValue()
            service.deviceDisconnected(device: device)
        }

        let selfPtr = Unmanaged.passUnretained(self).toOpaque()
        IOHIDManagerRegisterDeviceMatchingCallback(manager, deviceMatchingCallback, selfPtr)
        IOHIDManagerRegisterDeviceRemovalCallback(manager, deviceRemovalCallback, selfPtr)

        // Schedule with run loop
        IOHIDManagerScheduleWithRunLoop(manager, CFRunLoopGetCurrent(), CFRunLoopMode.defaultMode.rawValue)

        // Open the manager
        let openResult = IOHIDManagerOpen(manager, IOOptionBits(kIOHIDOptionsTypeNone))
        if openResult != kIOReturnSuccess {
            print("Failed to open HID manager")
        }
    }

    private func deviceConnected(device: IOHIDDevice) {
        print("Mathpad connected")

        // Set up input value callback for Raw HID
        let inputCallback: IOHIDValueCallback = { context, result, sender, value in
            let service = Unmanaged<HybridUnicodeService>.fromOpaque(context!).takeUnretainedValue()
            service.handleInputValue(value: value)
        }

        let selfPtr = Unmanaged.passUnretained(self).toOpaque()
        IOHIDDeviceRegisterInputValueCallback(device, inputCallback, selfPtr)

        // Also try registering for input reports with a proper buffer
        let reportCallback: IOHIDReportCallback = { context, result, sender, type, reportID, report, reportLength in
            let service = Unmanaged<HybridUnicodeService>.fromOpaque(context!).takeUnretainedValue()
            service.handleInputReport(data: report, length: reportLength)
        }

        // Allocate a buffer for 32-byte reports
        let reportBuffer = UnsafeMutablePointer<UInt8>.allocate(capacity: 32)
        IOHIDDeviceRegisterInputReportCallback(device, reportBuffer, 32, reportCallback, selfPtr)
    }

    private func deviceDisconnected(device: IOHIDDevice) {
        print("Mathpad disconnected")
    }

    private func handleInputValue(value: IOHIDValue) {
        let element = IOHIDValueGetElement(value)
        let usage = IOHIDElementGetUsage(element)
        let usagePage = IOHIDElementGetUsagePage(element)
        let integerValue = IOHIDValueGetIntegerValue(value)

        print("HID Value - Usage Page: 0x\(String(usagePage, radix: 16)), Usage: 0x\(String(usage, radix: 16)), Value: \(integerValue)")
    }

    private func handleInputReport(data: UnsafePointer<UInt8>, length: CFIndex) {
        guard length >= 5 else {
            print("Report too short: \(length) bytes")
            return
        }

        // Debug: Print raw report data
        let rawBytes = Array(UnsafeBufferPointer(start: data, count: min(10, length)))
        let hexString = rawBytes.map { String(format: "%02x", $0) }.joined(separator: " ")
        print("Raw HID report: \(hexString)")

        // Check command byte
        let commandByte = data[0]
        guard commandByte == 0x01 else {
            print("Ignoring report with command byte: 0x\(String(format: "%02x", commandByte))")
            return
        }

        // Extract Unicode hex digits
        let unicodeBytes = Array(UnsafeBufferPointer(start: data.advanced(by: 1), count: 4))

        guard let hexString = String(bytes: unicodeBytes, encoding: .utf8),
              let codepoint = UInt32(hexString, radix: 16) else {
            print("Failed to parse Unicode from bytes: \(unicodeBytes)")
            return
        }

        print("Parsed Unicode: '\(hexString)' -> U+\(String(codepoint, radix: 16, uppercase: true))")

        // Inject the character directly
        injectUnicodeCharacter(codepoint: codepoint)
    }

    private func injectUnicodeCharacter(codepoint: UInt32) {
        print("[DEBUG] Starting Unicode injection for codepoint: U+\(String(codepoint, radix: 16, uppercase: true))")

        guard let character = UnicodeScalar(codepoint) else {
            print("[ERROR] Invalid Unicode codepoint: \(codepoint)")
            return
        }

        let characterString = String(character)
        print("[DEBUG] Character to inject: '\(characterString)'")

        // Try direct Unicode keystroke first (no pasteboard interference)
        if injectViaKeystroke(character: characterString) {
            print("[SUCCESS] Character injected via direct keystroke")
            return
        }

        // Fallback to Input Method approach
        print("[DEBUG] Direct keystroke failed, trying Input Method...")
        if injectViaInputMethod(character: characterString) {
            print("[SUCCESS] Character injected via Input Method")
            return
        }

        // Last resort: CGEventKeyboardSetUnicodeString
        print("[DEBUG] Input Method failed, trying CGEventKeyboardSetUnicodeString...")
        if injectViaUnicodeEvent(character: characterString) {
            print("[SUCCESS] Character injected via Unicode event")
            return
        }

        print("[ERROR] All injection methods failed")
    }

    private func injectViaPasteboard(character: String) -> Bool {
        print("[DEBUG] Attempting pasteboard injection...")

        let pasteboard = NSPasteboard.general

        // Save current pasteboard content
        let oldContent = pasteboard.string(forType: .string)
        print("[DEBUG] Saved current pasteboard content: \(oldContent?.prefix(50) ?? "nil")")

        // Clear and set our character
        pasteboard.clearContents()
        let success = pasteboard.setString(character, forType: .string)

        if !success {
            print("[ERROR] Failed to set pasteboard content")
            return false
        }

        print("[DEBUG] Set pasteboard to: '\(character)'")

        // Create Cmd+V event
        let eventSource = CGEventSource(stateID: .hidSystemState)

        guard let vKeyDown = CGEvent(keyboardEventSource: eventSource, virtualKey: 9, keyDown: true),
              let vKeyUp = CGEvent(keyboardEventSource: eventSource, virtualKey: 9, keyDown: false) else {
            print("[ERROR] Failed to create keyboard events")
            return false
        }

        // Add Command modifier
        vKeyDown.flags = .maskCommand
        vKeyUp.flags = .maskCommand

        print("[DEBUG] Posting Cmd+V events...")

        // Post the events
        vKeyDown.post(tap: .cghidEventTap)
        Thread.sleep(forTimeInterval: 0.01)
        vKeyUp.post(tap: .cghidEventTap)

        print("[DEBUG] Posted Cmd+V events")

        // Restore pasteboard content after a short delay
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.1) {
            if let oldContent = oldContent {
                pasteboard.clearContents()
                pasteboard.setString(oldContent, forType: .string)
                print("[DEBUG] Restored pasteboard content")
            }
        }

        return true
    }

    private func injectViaKeystroke(character: String) -> Bool {
        print("[DEBUG] Attempting direct Unicode keystroke injection...")

        // Convert string to UTF-16 for CGEvent
        let utf16String = Array(character.utf16)

        if utf16String.isEmpty {
            print("[ERROR] Empty UTF-16 string")
            return false
        }

        print("[DEBUG] UTF-16 representation: \(utf16String.map { String(format: "0x%04X", $0) }.joined(separator: " "))")

        // Try creating a pure Unicode event without any virtual key
        let eventSource = CGEventSource(stateID: .hidSystemState)

        // Create event with type kCGEventKeyDown but no virtual key
        guard let unicodeEvent = CGEvent(source: eventSource) else {
            print("[ERROR] Failed to create base event")
            return false
        }

        // Set event type to keyboard
        unicodeEvent.type = .keyDown

        // Set the Unicode string directly without any virtual key
        unicodeEvent.keyboardSetUnicodeString(stringLength: utf16String.count, unicodeString: utf16String)

        // Ensure no flags are set
        unicodeEvent.flags = []

        print("[DEBUG] Posting pure Unicode event for: '\(character)' (UTF-16 length: \(utf16String.count))")

        // Post the Unicode event
        unicodeEvent.post(tap: .cghidEventTap)

        return true
    }

    private func injectViaInputMethod(character: String) -> Bool {
        print("[DEBUG] Attempting AppleScript injection...")

        // Use AppleScript as a reliable fallback
        let escapedChar = character.replacingOccurrences(of: "\"", with: "\\\"")
                                  .replacingOccurrences(of: "\\", with: "\\\\")

        let script = """
        tell application "System Events"
            keystroke "\(escapedChar)"
        end tell
        """

        let task = Process()
        task.executableURL = URL(fileURLWithPath: "/usr/bin/osascript")
        task.arguments = ["-e", script]

        do {
            try task.run()
            task.waitUntilExit()

            if task.terminationStatus == 0 {
                print("[DEBUG] AppleScript injection successful")
                return true
            } else {
                print("[DEBUG] AppleScript injection failed with status: \(task.terminationStatus)")
                return false
            }
        } catch {
            print("[DEBUG] AppleScript execution failed: \(error)")
            return false
        }
    }

    private func injectViaUnicodeEvent(character: String) -> Bool {
        print("[DEBUG] Attempting CGEventKeyboardSetUnicodeString injection...")

        let utf16String = Array(character.utf16)

        if utf16String.isEmpty {
            print("[ERROR] Empty UTF-16 string")
            return false
        }

        let eventSource = CGEventSource(stateID: .hidSystemState)

        // Create a generic keyboard event
        guard let keyEvent = CGEvent(keyboardEventSource: eventSource, virtualKey: CGKeyCode(kVK_Space), keyDown: true) else {
            print("[ERROR] Failed to create base keyboard event")
            return false
        }

        // Override with Unicode string
        keyEvent.keyboardSetUnicodeString(stringLength: utf16String.count, unicodeString: utf16String)

        // Clear any flags to make it a pure Unicode event
        keyEvent.flags = []

        print("[DEBUG] Posting modified keyboard event with Unicode: '\(character)'")

        keyEvent.post(tap: .cghidEventTap)

        // Also post key up event
        guard let keyUpEvent = CGEvent(keyboardEventSource: eventSource, virtualKey: CGKeyCode(kVK_Space), keyDown: false) else {
            print("[ERROR] Failed to create key up event")
            return true // Still return true since we posted the down event
        }

        keyUpEvent.keyboardSetUnicodeString(stringLength: utf16String.count, unicodeString: utf16String)
        keyUpEvent.flags = []
        keyUpEvent.post(tap: .cghidEventTap)

        return true
    }

    private func checkSingleInstance() -> Bool {
        print("[DEBUG] Checking for existing instance...")

        // Check if PID file exists
        guard FileManager.default.fileExists(atPath: pidFilePath) else {
            print("[DEBUG] No existing PID file found")
            return true
        }

        // Read existing PID
        guard let pidString = try? String(contentsOfFile: pidFilePath, encoding: .utf8),
              let existingPID = Int32(pidString.trimmingCharacters(in: .whitespacesAndNewlines)) else {
            print("[DEBUG] Invalid PID file, removing...")
            try? FileManager.default.removeItem(atPath: pidFilePath)
            return true
        }

        // Check if process with that PID is still running
        let result = kill(existingPID, 0)
        if result == 0 {
            // Process is still running
            print("[ERROR] Process with PID \(existingPID) is still running")
            return false
        } else {
            // Process is not running, remove stale PID file
            print("[DEBUG] Stale PID file found (PID \(existingPID) not running), removing...")
            try? FileManager.default.removeItem(atPath: pidFilePath)
            return true
        }
    }

    private func createPIDFile() {
        let currentPID = getpid()
        print("[DEBUG] Creating PID file with PID: \(currentPID)")

        do {
            try String(currentPID).write(toFile: pidFilePath, atomically: true, encoding: .utf8)
            print("[DEBUG] PID file created at: \(pidFilePath)")
        } catch {
            print("[ERROR] Failed to create PID file: \(error)")
            exit(1)
        }
    }

    private func setupSignalHandlers() {
        print("[DEBUG] Setting up signal handlers for cleanup...")

        // Handle SIGINT (Ctrl+C)
        signal(SIGINT) { _ in
            print("\n[INFO] Received SIGINT, shutting down gracefully...")
            HybridUnicodeService.cleanup()
            exit(0)
        }

        // Handle SIGTERM
        signal(SIGTERM) { _ in
            print("\n[INFO] Received SIGTERM, shutting down gracefully...")
            HybridUnicodeService.cleanup()
            exit(0)
        }
    }

    private func requestPermissions() {
        print("[INFO] Requesting macOS permissions to appear in Privacy settings...")

        // Request Input Monitoring permission by creating a listen-only event tap
        requestInputMonitoringPermission()

        // Request Accessibility permission by creating a default event tap
        requestAccessibilityPermission()
    }

    private func requestInputMonitoringPermission() {
        print("[DEBUG] Requesting Input Monitoring permission...")

        // Create a listen-only event tap to trigger Input Monitoring permission
        let eventTap = CGEvent.tapCreate(
            tap: .cgSessionEventTap,
            place: .headInsertEventTap,
            options: .listenOnly,  // This triggers Input Monitoring permission
            eventsOfInterest: CGEventMask(1 << CGEventType.keyDown.rawValue),
            callback: { (proxy, type, event, refcon) in
                // This callback will never be called since we immediately disable the tap
                return Unmanaged.passUnretained(event)
            },
            userInfo: nil
        )

        if let tap = eventTap {
            print("[DEBUG] Input Monitoring event tap created successfully")
            // Immediately disable the tap - we only needed to create it
            CGEvent.tapEnable(tap: tap, enable: false)
        } else {
            print("[DEBUG] Input Monitoring permission may already be granted or denied")
        }
    }

    private func requestAccessibilityPermission() {
        print("[DEBUG] Requesting Accessibility permission...")

        // Create a default event tap to trigger Accessibility permission
        let eventTap = CGEvent.tapCreate(
            tap: .cgSessionEventTap,
            place: .headInsertEventTap,
            options: .defaultTap,  // This triggers Accessibility permission
            eventsOfInterest: CGEventMask(1 << CGEventType.keyDown.rawValue),
            callback: { (proxy, type, event, refcon) in
                // This callback will never be called since we immediately disable the tap
                return Unmanaged.passUnretained(event)
            },
            userInfo: nil
        )

        if let tap = eventTap {
            print("[DEBUG] Accessibility event tap created successfully")
            // Immediately disable the tap - we only needed to create it
            CGEvent.tapEnable(tap: tap, enable: false)
        } else {
            print("[DEBUG] Accessibility permission may already be granted or denied")
        }
    }

    private static func cleanup() {
        print("[DEBUG] Performing cleanup...")
        let tempDir = NSTemporaryDirectory()
        let pidFilePath = "\(tempDir)mathpad_service.pid"

        if FileManager.default.fileExists(atPath: pidFilePath) {
            do {
                try FileManager.default.removeItem(atPath: pidFilePath)
                print("[DEBUG] PID file removed")
            } catch {
                print("[ERROR] Failed to remove PID file: \(error)")
            }
        }
    }

    func start() {
        print("[INFO] Unicode Keypad Service started (PID: \(getpid()))")
        print("[INFO] Using direct Swift Unicode injection (no Python dependency)")
        print("[INFO] PID file: \(pidFilePath)")

        CFRunLoopRun()
    }

    deinit {
        print("[DEBUG] Service deinitializing...")
        if let manager = hidManager {
            IOHIDManagerClose(manager, IOOptionBits(kIOHIDOptionsTypeNone))
        }

        // Clean up PID file
        HybridUnicodeService.cleanup()
    }
}

// MARK: - Main
let service = HybridUnicodeService()
service.start()