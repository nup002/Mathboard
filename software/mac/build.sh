#!/bin/bash
# Build script for Hybrid Unicode Keypad Service

set -e  # Exit on any error

APP_NAME="UnicodeKeypadService"
BUNDLE_ID="com.summacogni.mathpad.unicode"
VERSION="1.0.0"

echo "Building Hybrid Unicode Keypad Service..."

# Clean previous builds
rm -rf build/
mkdir -p build/

# Create app bundle structure
mkdir -p "build/${APP_NAME}.app/Contents/MacOS"
mkdir -p "build/${APP_NAME}.app/Contents/Resources"

# Compile Swift service
echo "Compiling Swift service..."
swiftc \
    -framework Foundation \
    -framework IOKit \
    -framework CoreGraphics \
    -framework AppKit \
    -o "build/${APP_NAME}.app/Contents/MacOS/${APP_NAME}" \
    HybridService.swift

# Copy Python injector
echo "Copying Python injector..."
cp unicode_injector.py "build/${APP_NAME}.app/Contents/MacOS/"
chmod +x "build/${APP_NAME}.app/Contents/MacOS/unicode_injector.py"

# Create Info.plist
echo "Creating Info.plist..."
cat > "build/${APP_NAME}.app/Contents/Info.plist" << EOF
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleExecutable</key>
    <string>${APP_NAME}</string>
    <key>CFBundleIdentifier</key>
    <string>${BUNDLE_ID}</string>
    <key>CFBundleName</key>
    <string>Unicode Keypad Service</string>
    <key>CFBundleDisplayName</key>
    <string>Mathpad Unicode Service</string>
    <key>CFBundleVersion</key>
    <string>${VERSION}</string>
    <key>CFBundleShortVersionString</key>
    <string>${VERSION}</string>
    <key>LSBackgroundOnly</key>
    <true/>
    <key>LSMinimumSystemVersion</key>
    <string>10.14</string>
    <key>NSHumanReadableCopyright</key>
    <string>Copyright © 2025 Summa Cogni. All rights reserved.</string>
    <key>NSHighResolutionCapable</key>
    <true/>
</dict>
</plist>
EOF

# Create LaunchAgent plist
echo "Creating LaunchAgent..."
mkdir -p build/LaunchAgent/
cat > "build/LaunchAgent/com.summacogni.mathpad.unicode.plist" << EOF
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>Label</key>
    <string>com.summacogni.mathpad.unicode</string>
    <key>ProgramArguments</key>
    <array>
        <string>/Applications/${APP_NAME}.app/Contents/MacOS/${APP_NAME}</string>
    </array>
    <key>RunAtLoad</key>
    <true/>
    <key>KeepAlive</key>
    <dict>
        <key>SuccessfulExit</key>
        <false/>
    </dict>
    <key>StandardErrorPath</key>
    <string>/tmp/mathpad-unicode.err</string>
    <key>StandardOutPath</key>
    <string>/tmp/mathpad-unicode.out</string>
</dict>
</plist>
EOF

# Create installer script
echo "Creating installer script..."
cat > "build/install.sh" << 'EOF'
#!/bin/bash
# Mathpad Unicode Service Installer

set -e

APP_NAME="UnicodeKeypadService"
LAUNCH_AGENT="com.summacogni.mathpad.unicode.plist"

echo "Installing Mathpad Unicode Service..."

# Check for Python dependencies
echo "Checking Python dependencies..."
if ! python3 -c "import AppKit, Quartz" 2>/dev/null; then
    echo "Installing required Python modules..."
    pip3 install pyobjc-framework-Cocoa pyobjc-framework-Quartz
fi

# Copy app to Applications
echo "Installing application..."
sudo cp -R "${APP_NAME}.app" /Applications/

# Install LaunchAgent
echo "Installing auto-start service..."
cp "LaunchAgent/${LAUNCH_AGENT}" "$HOME/Library/LaunchAgents/"
launchctl load "$HOME/Library/LaunchAgents/${LAUNCH_AGENT}"

echo ""
echo "✅ Installation complete!"
echo ""
echo "⚠️  IMPORTANT: You need to grant permissions:"
echo "1. Go to System Preferences > Security & Privacy > Privacy"
echo "2. Select 'Accessibility' and add 'UnicodeKeypadService'"
echo "3. The service will start automatically on next login"
echo ""
echo "To start now: launchctl start com.summacogni.mathpad.unicode"
echo "To check status: launchctl list | grep mathpad"
echo "To view logs: tail -f /tmp/mathpad-unicode.out"
EOF

chmod +x build/install.sh

# Create uninstaller script
echo "Creating uninstaller script..."
cat > "build/uninstall.sh" << 'EOF'
#!/bin/bash
# Mathpad Unicode Service Uninstaller

APP_NAME="UnicodeKeypadService"
LAUNCH_AGENT="com.summacogni.mathpad.unicode.plist"

echo "Uninstalling Mathpad Unicode Service..."

# Stop and unload service
launchctl unload "$HOME/Library/LaunchAgents/${LAUNCH_AGENT}" 2>/dev/null || true
rm -f "$HOME/Library/LaunchAgents/${LAUNCH_AGENT}"

# Remove application
sudo rm -rf "/Applications/${APP_NAME}.app"

# Clean up logs
rm -f /tmp/mathpad-unicode.out /tmp/mathpad-unicode.err

echo "✅ Uninstallation complete!"
EOF

chmod +x build/uninstall.sh

# Create simple test script
echo "Creating test script..."
cat > "build/test.py" << 'EOF'
#!/usr/bin/env python3
"""
Test script to verify Unicode injection works
"""

import sys
import subprocess

def test_unicode_injection(codepoint):
    """Test injecting a specific Unicode character"""
    print(f"Testing Unicode injection for U+{codepoint:04X}")

    try:
        result = subprocess.run([
            'python3', 'unicode_injector.py', str(codepoint)
        ], capture_output=True, text=True, timeout=5.0)

        if result.returncode == 0:
            print("✅ Injection successful")
        else:
            print(f"❌ Injection failed: {result.stderr}")

    except Exception as e:
        print(f"❌ Test failed: {e}")

if __name__ == '__main__':
    print("Unicode Injection Test")
    print("Make sure you have a text editor open and focused")
    print("")

    # Test a few common characters
    test_characters = [
        0x03B1,  # α (alpha)
        0x00B0,  # ° (degree)
        0x03C0,  # π (pi)
        0x221E,  # ∞ (infinity)
    ]

    for codepoint in test_characters:
        test_unicode_injection(codepoint)
        time.sleep(1)

    print("\nTest complete. Check your text editor for: α°π∞")
EOF

chmod +x build/test.py

echo ""
echo "✅ Build complete!"
echo ""
echo "Generated files:"
echo "  build/${APP_NAME}.app/          - Main application bundle"
echo "  build/install.sh                - User installation script"
echo "  build/uninstall.sh              - Uninstallation script"
echo "  build/test.py                   - Test script"
echo ""
echo "For development testing:"
echo "  1. cd build/"
echo "  2. python3 test.py"
echo "  3. ./${APP_NAME}.app/Contents/MacOS/${APP_NAME}"
echo ""
echo "For distribution:"
echo "  1. Give users the entire 'build' folder"
echo "  2. User runs: ./install.sh"
echo "  3. User grants accessibility permissions when prompted"