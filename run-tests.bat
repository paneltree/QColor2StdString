@echo off
echo Running QColor Converter tests...
cd build\test\Release
qcolor_converter_test.exe --gtest_color=yes
cd ..\..\..
echo Tests completed. 