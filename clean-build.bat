@echo off
echo Setting up Visual Studio environment...
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

echo Cleaning previous build...
if exist build (
    echo Removing build directory...
    rmdir /s /q build
)

echo Creating build directory...
mkdir build

echo Running CMake...
cd build
cmake .. -DCMAKE_PREFIX_PATH=C:/Qt/6.8.3/msvc2022_64

echo Building project...
cmake --build . --config Release

cd ..
echo.
echo Clean build completed. You can run:
echo - Demo App: .\build\app\Release\colorapp.exe
echo - Tests: .\build\test\Release\qcolor_converter_test.exe
echo.
echo Qt dependencies have been deployed to the executable directories. 