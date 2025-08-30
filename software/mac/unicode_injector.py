#!/usr/bin/env python3
"""
Unicode Character Injector
Called by Swift service to inject Unicode characters into active applications
"""

import sys
import time
import subprocess
from typing import Optional

try:
    from AppKit import NSPasteboard, NSStringPboardType, NSWorkspace
    from Quartz import (
        CGEventCreateKeyboardEvent, CGEventPost, kCGHIDEventTap,
        CGEventSourceCreate, kCGEventSourceStateHIDSystemState,
        CGEventSetFlags, kCGEventFlagMaskCommand
    )

    MAC_MODULES_AVAILABLE = True
except ImportError:
    MAC_MODULES_AVAILABLE = False


class UnicodeInjector:
    def __init__(self):
        self.last_pasteboard_content = None

    def inject_via_pasteboard(self, character: str) -> bool:
        """Inject character using pasteboard + Cmd+V method"""
        if not MAC_MODULES_AVAILABLE:
            print(f"Missing Mac modules. Character: {character}")
            return False

        try:
            # Save current pasteboard content
            pasteboard = NSPasteboard.generalPasteboard()
            old_content = pasteboard.stringForType_(NSStringPboardType)

            # Set our character
            pasteboard.clearContents()
            pasteboard.setString_forType_(character, NSStringPboardType)

            # Create Cmd+V event
            event_source = CGEventSourceCreate(kCGEventSourceStateHIDSystemState)

            # V key is keycode 9
            v_down = CGEventCreateKeyboardEvent(event_source, 9, True)
            v_up = CGEventCreateKeyboardEvent(event_source, 9, False)

            # Add Command modifier
            CGEventSetFlags(v_down, kCGEventFlagMaskCommand)
            CGEventSetFlags(v_up, kCGEventFlagMaskCommand)

            # Post the events
            CGEventPost(kCGHIDEventTap, v_down)
            time.sleep(0.01)
            CGEventPost(kCGHIDEventTap, v_up)

            # Restore pasteboard content after a delay
            def restore_pasteboard():
                time.sleep(0.1)
                if old_content:
                    pasteboard.clearContents()
                    pasteboard.setString_forType_(old_content, NSStringPboardType)

            # Schedule restoration (simple approach - just wait)
            time.sleep(0.05)
            if old_content:
                pasteboard.clearContents()
                pasteboard.setString_forType_(old_content, NSStringPboardType)

            return True

        except Exception as e:
            print(f"Pasteboard injection failed: {e}")
            return False

    def inject_via_applescript(self, character: str) -> bool:
        """Alternative method using AppleScript (slower but more compatible)"""
        try:
            # Escape the character for AppleScript
            escaped_char = character.replace('"', '\\"').replace('\\', '\\\\')

            applescript = f'''
            tell application "System Events"
                keystroke "{escaped_char}"
            end tell
            '''

            result = subprocess.run([
                'osascript', '-e', applescript
            ], capture_output=True, text=True, timeout=2.0)

            return result.returncode == 0

        except Exception as e:
            print(f"AppleScript injection failed: {e}")
            return False

    def inject_character(self, codepoint: int) -> bool:
        """Main injection method with fallbacks"""
        try:
            character = chr(codepoint)
            print(f"Injecting: U+{codepoint:04X} -> '{character}'")

            # Try pasteboard method first (fastest)
            if self.inject_via_pasteboard(character):
                return True

            # Fallback to AppleScript
            print("Pasteboard failed, trying AppleScript...")
            if self.inject_via_applescript(character):
                return True

            print("All injection methods failed")
            return False

        except ValueError:
            print(f"Invalid Unicode codepoint: {codepoint}")
            return False


def main():
    if len(sys.argv) != 2:
        print("Usage: unicode_injector.py <codepoint>")
        print("Example: unicode_injector.py 945  # for α (U+03B1)")
        sys.exit(1)

    try:
        codepoint = int(sys.argv[1])
    except ValueError:
        print(f"Invalid codepoint: {sys.argv[1]}")
        sys.exit(1)

    injector = UnicodeInjector()
    success = injector.inject_character(codepoint)

    sys.exit(0 if success else 1)


if __name__ == '__main__':
    main()