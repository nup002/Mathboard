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

# Extract version info from Swift file
VERSION=$(grep 'static let version = ' MathpadService.swift | sed 's/.*= "\(.*\)".*/\1/')
BUILD_DATE=$(grep 'static let buildDate = ' MathpadService.swift | sed 's/.*= "\(.*\)".*/\1/')

echo "Version: $VERSION"
echo "Build Date: $BUILD_DATE"

# Compile mathpad-service
# Create app bundle structure
mkdir -p "build/${APP_NAME}/Contents/MacOS"
mkdir -p "build/${APP_NAME}/Contents/Resources"

# Compile the executable (universal), using the runner's active SDK.
#  - x86_64 supports Intel Macs back to macOS 10.14.4 (Swift ABI/runtime floor)
#  - arm64 floor is macOS 11.0 (Apple Silicon did not exist earlier)
echo "Compiling mathpad-service..."
SDK_PATH="$(xcrun --show-sdk-path --sdk macosx)"
SWIFT_FLAGS=(
    -sdk "$SDK_PATH"
    -framework Foundation
    -framework IOKit
    -framework CoreGraphics
    -framework AppKit
)

swiftc "${SWIFT_FLAGS[@]}" -target arm64-apple-macos11 \
    MathpadService.swift -o "build/mathpad-service-arm64"
swiftc "${SWIFT_FLAGS[@]}" -target x86_64-apple-macos10.14.4 \
    MathpadService.swift -o "build/mathpad-service-x86_64"

lipo -create -output "build/${APP_NAME}/Contents/MacOS/mathpad-service" \
    "build/mathpad-service-arm64" "build/mathpad-service-x86_64"

rm -f "build/mathpad-service-arm64" "build/mathpad-service-x86_64"

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
    <string>$VERSION</string>
    <key>LSMinimumSystemVersion</key>
    <string>10.14.4</string>
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