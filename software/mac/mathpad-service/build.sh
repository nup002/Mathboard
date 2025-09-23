#!/bin/bash
# Build script for Mathpad Service
# Also builds the installer app
set -e  # Exit on any error

DMG_NAME="Mathpad Service"
INSTALLER_NAME="Install"
APP_NAME="mathpad-service.app"

echo "MATHPAD SERVICE BUILD SCRIPT"

# Clean previous builds
echo "Cleaning previous builds..."
rm -rf build/
mkdir -p build/

# Clean previous dist
echo "Cleaning previous dist..."
rm -rf dist/
mkdir -p dist/

# Compile mathpad-service
# Create app bundle structure
mkdir -p "build/${APP_NAME}/Contents/MacOS"
mkdir -p "build/${APP_NAME}/Contents/Resources"

# Compile the executable
echo "Compiling mathpad-service..."
swiftc \
    -sdk /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk \
    -framework Foundation \
    -framework IOKit \
    -framework CoreGraphics \
    -framework AppKit \
    MathpadService.swift \
    -o "build/${APP_NAME}/Contents/MacOS/mathpad-service"

# Create Info.plist
echo "Creading Info.plist..."
cat > "build/${APP_NAME}/Contents/Info.plist" << EOF
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleExecutable</key>
    <string>mathpad-service</string>
    <key>CFBundleIconFile</key>
    <string>applet</string>
    <key>CFBundleIdentifier</key>
    <string>com.mathpad.mathpad-service</string>
    <key>CFBundleName</key>
    <string>Mathpad Service</string>
    <key>CFBundlePackageType</key>
    <string>APPL</string>
    <key>CFBundleVersion</key>
    <string>1.0.0</string>
    <key>LSBackgroundOnly</key>
    <true/>
    <key>LSUIElement</key>
    <true/>
</dict>
</plist>
EOF

# Copy icon
cp "../applet.icns" "build/${APP_NAME}/Contents/Resources/"

echo "Mathpad Service compiled successfully."

echo "Creating installer app bundle..."

# Export installer script to an app bundle
osacompile -o "./dist/${INSTALLER_NAME}.app" "${INSTALLER_NAME}.applescript"

# Set the installer app icon
cp ../applet.icns "dist/${INSTALLER_NAME}.app/Contents/Resources/applet.icns"

# Copy app bundle to installer
cp -R "build/${APP_NAME}" "dist/Install.app/Contents/Resources/"

echo "All done."