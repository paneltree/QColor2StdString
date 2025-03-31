@echo off
echo Setting up Visual Studio environment...
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

echo Creating build directory...
if not exist build mkdir build

echo Running CMake...
cd build
cmake .. -DCMAKE_PREFIX_PATH=C:/Qt/6.8.3/msvc2022_64

echo Building project...
cmake --build . --config Release

echo.
echo Build completed. You can run:
echo - Demo App: .\app\Release\colorapp.exe
echo - Tests: .\test\Release\qcolor_converter_test.exe

cd .. 