@echo off
echo Setting up Visual Studio environment...
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

echo Creating build directory...
if not exist build mkdir build

echo Running CMake...
cd build
echo Current directory: %cd%
cmake .. -DCMAKE_PREFIX_PATH=C:/Qt/6.8.3/msvc2022_64

echo Building project...
cmake --build . --config Release

"C:\Qt\6.8.3\msvc2022_64\bin\windeployqt.exe"  app\Release\colorapp.exe
"C:\Qt\6.8.3\msvc2022_64\bin\windeployqt.exe" test\Release\qcolor_converter_test.exe

cd .. 
echo.
echo Build completed. You can run:
echo Current directory: %cd%
echo - Demo App: .\build\app\Release\colorapp.exe
echo - Tests: .\build\test\Release\qcolor_converter_test.exe
