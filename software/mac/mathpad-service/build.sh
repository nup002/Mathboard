#!/bin/bash
# Build script for Mathpad Service
# Also builds the installer app and converts it to a DMG
set -e  # Exit on any error

DMG_NAME="Mathpad Service"
INSTALLER_NAME="Install"
SERVICE_NAME="mathpad-service"

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
echo "Compiling Mathpad Service..."
swiftc \
    -sdk /Library/Developer/CommandLineTools/SDKs/MacOSX11.3.sdk \
    -framework Foundation \
    -framework IOKit \
    -framework CoreGraphics \
    -framework AppKit \
    MathpadService.swift \
    -o "build/${SERVICE_NAME}"

# Set the custom executable icon (requires fileicon. Install with 'brew install fileicon')
fileicon set "build/${SERVICE_NAME}" ../applet.icns

echo "Mathpad Service compiled successfully."

echo "Creating installer app bundle..."

# Export installer script to app bundle
osacompile -o "./dist/${INSTALLER_NAME}.app" "${INSTALLER_NAME}.applescript"

# Copy the compiled binary to the app bundle
echo "Copying compiled binary to app bundle..."
cp "build/${SERVICE_NAME}" "dist/${INSTALLER_NAME}.app/Contents/Resources/"

# Set the installer app icon
cp ../applet.icns "dist/${INSTALLER_NAME}.app/Contents/Resources/applet.icns"

echo "All done."