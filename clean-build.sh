#!/bin/bash

echo "Cleaning build directory..."
if [ -d "build" ]; then
  rm -rf build
  echo "Build directory removed."
else
  echo "Build directory not found, nothing to clean."
fi

echo "Creating fresh build directory..."
mkdir build

echo "Running CMake..."
cd build
echo "Current directory: $(pwd)"
cmake .. -DCMAKE_PREFIX_PATH=/Users/paneltree/Qt/6.8.3/macos

echo "Building project..."
cmake --build . --config Release

cd ..
echo ""
echo "Clean build completed. You can run:"
echo "Current directory: $(pwd)"
echo "- Demo App: ./build/app/colorapp.app/Contents/MacOS/colorapp"
echo "- Tests: ./build/test/qcolor_converter_test" 