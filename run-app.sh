#!/bin/bash

if [ -d "./build/app/colorapp.app" ]; then
  echo "Running colorapp..."
  ./build/app/colorapp.app/Contents/MacOS/colorapp
else
  echo "Error: Application not found. Please build the project first."
fi 