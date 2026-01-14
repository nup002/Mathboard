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
mkdir -p "build/${APP_NAME}/Contents/Frameworks"

# Compile the executable with deployment target for older macOS
echo "Compiling mathpad-service..."
swiftc \
    -target x86_64-apple-macosx10.13 \
    -framework Foundation \
    -framework IOKit \
    -framework CoreGraphics \
    -framework AppKit \
    MathpadService.swift \
    -o "build/${APP_NAME}/Contents/MacOS/mathpad-service"

# Embed Swift runtime libraries for older macOS versions
echo "Embedding Swift runtime libraries..."

# Find Swift library path from Xcode toolchain
SWIFT_LIB_PATH="/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/swift/macosx"

if [ ! -d "$SWIFT_LIB_PATH" ]; then
    # Try xcode-select path as fallback
    SWIFT_LIB_PATH="$(xcode-select -p)/Toolchains/XcodeDefault.xctoolchain/usr/lib/swift/macosx"
fi

if [ ! -f "$SWIFT_LIB_PATH/libswiftCore.dylib" ]; then
    echo "ERROR: Could not find Swift libraries at $SWIFT_LIB_PATH"
    echo "Make sure Xcode is installed and selected with: xcode-select --switch /Applications/Xcode.app"
    exit 1
fi

echo "Found Swift libraries at: $SWIFT_LIB_PATH"

# Automatically detect and copy Swift libraries the binary depends on
echo "Detecting and copying required Swift libraries..."
otool -L "build/${APP_NAME}/Contents/MacOS/mathpad-service" | \
    grep '@rpath/libswift' | \
    awk '{print $1}' | \
    sed 's/@rpath\///' | \
    while read lib; do
        if [ -f "$SWIFT_LIB_PATH/$lib" ]; then
            echo "  Copying $lib"
            cp "$SWIFT_LIB_PATH/$lib" "build/${APP_NAME}/Contents/Frameworks/"
        else
            echo "  ERROR: Required library $lib not found!"
            exit 1
        fi
    done

# Verify rpath is set correctly
echo "Verifying rpath..."
if ! otool -l "build/${APP_NAME}/Contents/MacOS/mathpad-service" | grep -q "@executable_path/../Frameworks"; then
    echo "Adding rpath..."
    install_name_tool -add_rpath "@executable_path/../Frameworks" "build/${APP_NAME}/Contents/MacOS/mathpad-service"
fi

# Create Info.plist
echo "Creating Info.plist..."
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

# Verify the embedded libraries
echo ""
echo "Embedded Swift libraries:"
ls -lh "build/${APP_NAME}/Contents/Frameworks/"
echo ""
echo "Total app size:"
du -sh "build/${APP_NAME}"

echo ""
echo "Creating installer app bundle..."
# Export installer script to an app bundle
osacompile -o "./dist/${INSTALLER_NAME}.app" "${INSTALLER_NAME}.applescript"

# Set the installer app icon
cp ../applet.icns "dist/${INSTALLER_NAME}.app/Contents/Resources/applet.icns"

# Copy app bundle to installer
cp -R "build/${APP_NAME}" "dist/Install.app/Contents/Resources/"

echo "All done."