#!/bin/bash

echo "Creating build directory..."
mkdir -p build

echo "Running CMake..."
cd build
echo "Current directory: $(pwd)"
cmake .. -DCMAKE_PREFIX_PATH=/Users/paneltree/Qt/6.8.3/macos/lib/cmake

echo "Building project..."
cmake --build . --config Release

cd ..
echo ""
echo "Build completed. You can run:"
echo "Current directory: $(pwd)"
echo "- Demo App: ./build/app/colorapp.app/Contents/MacOS/colorapp"
echo "- Tests: ./build/test/qcolor_converter_test" 