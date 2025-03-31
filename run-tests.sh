#!/bin/bash

if [ -f "./build/test/qcolor_converter_test" ]; then
  echo "Running tests..."
  ./build/test/qcolor_converter_test
else
  echo "Error: Test executable not found. Please build the project with tests enabled."
fi 