#!/bin/bash
# Build script for Mathpad Service

set -e  # Exit on any error

APP_NAME="MathpadServiceInstaller"
SERVICE_NAME="mathpad-service"

echo "MATHPAD SERVICE BUILD SCRIPT"

# Clean previous builds
echo "Cleaning previous builds..."
rm -rf build/
mkdir -p build/

# Compile Swift service
echo "Compiling Mathpad Service..."
swiftc \
    -sdk /Library/Developer/CommandLineTools/SDKs/MacOSX11.3.sdk \
    -framework Foundation \
    -framework IOKit \
    -framework CoreGraphics \
    -framework AppKit \
    MathpadService.swift \
    -o "build/${SERVICE_NAME}"

# Copy the compiled binary to the app bundle
echo "Removing old binary..."
rm -f "dist/${APP_NAME}.app/Contents/Resources/${SERVICE_NAME}"
echo "Copying compiled binary to app bundle..."
cp "build/${SERVICE_NAME}" "dist/${APP_NAME}.app/Contents/Resources"

echo "Mathpad Service compiled successfully."