import Foundation
import IOKit
import IOKit.hid

class HybridUnicodeService {
    private var hidManager: IOHIDManager?
    private let vendorID: Int = 0x1209      // Mathpad VID
    private let productID: Int = 0x2211     // Mathpad PID
    private let customUsagePage: Int = 0xFF60  // QMK Raw HID usage page
    private let unicodeUsage: Int = 0x61       // QMK Raw HID usage ID
    private let pythonScriptPath: String

    init() {
        // Get the path to the Python script (should be in the same directory)
        let executablePath = Bundle.main.executablePath ?? ""
        let executableDir = (executablePath as NSString).deletingLastPathComponent
        self.pythonScriptPath = "\(executableDir)/unicode_injector.py"

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

        // Set up input report callback
        let inputCallback: IOHIDReportCallback = { context, result, sender, type, reportID, report, reportLength in
            let service = Unmanaged<HybridUnicodeService>.fromOpaque(context!).takeUnretainedValue()
            service.handleInputReport(data: report, length: reportLength)
        }

        let selfPtr = Unmanaged.passUnretained(self).toOpaque()
        IOHIDDeviceRegisterInputReportCallback(device, nil, 0, inputCallback, selfPtr)
    }

    private func deviceDisconnected(device: IOHIDDevice) {
        print("Mathpad disconnected")
    }

    private func handleInputReport(data: UnsafePointer<UInt8>, length: CFIndex) {
        guard length >= 5 else { return }

        // Check command byte
        let commandByte = data[0]
        guard commandByte == 0x01 else { return }

        // Extract Unicode hex digits
        let unicodeBytes = Array(UnsafeBufferPointer(start: data.advanced(by: 1), count: 4))

        guard let hexString = String(bytes: unicodeBytes, encoding: .utf8),
              let codepoint = UInt32(hexString, radix: 16) else {
            print("Failed to parse Unicode from HID report")
            return
        }

        print("Received Unicode: \(hexString) -> U+\(String(codepoint, radix: 16, uppercase: true))")

        // Call Python script to inject the character
        callPythonInjector(codepoint: codepoint)
    }

    private func callPythonInjector(codepoint: UInt32) {
        let task = Process()
        task.executableURL = URL(fileURLWithPath: "/usr/bin/python3")
        task.arguments = [pythonScriptPath, String(codepoint)]

        do {
            try task.run()
        } catch {
            print("Failed to call Python injector: \(error)")
        }
    }

    func start() {
        print("Unicode Keypad Service started")
        print("Python script path: \(pythonScriptPath)")

        // Check if Python script exists
        if !FileManager.default.fileExists(atPath: pythonScriptPath) {
            print("Warning: Python script not found at \(pythonScriptPath)")
        }

        CFRunLoopRun()
    }

    deinit {
        if let manager = hidManager {
            IOHIDManagerClose(manager, IOOptionBits(kIOHIDOptionsTypeNone))
        }
    }
}

// MARK: - Main
let service = HybridUnicodeService()
service.start()