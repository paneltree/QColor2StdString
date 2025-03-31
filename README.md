# QColor2StdString

A Qt-based library for converting between QColor and std::string representation.

## Features

- Convert QColor to std::string in rgba format
- Convert QColor to std::string in hex format
- Convert std::string in rgba or hex format to QColor
- Demo application to show the conversion in action
- Unit tests using Google Test

## Building

### Prerequisites

#### Windows
- Qt 6.8.3 (installed at `C:\Qt\6.8.3`)
- Visual Studio 2022 Community (MSVC 2022)
- CMake 3.16 or higher

#### macOS
- Qt 6.8.3 (installed at `/Users/paneltree/Qt/6.8.3`)
- CMake 3.16 or higher
- Xcode Command Line Tools

### Setup

#### Windows
You can use the provided batch scripts to build and run the project:

1. Quick build:
   ```
   build.bat
   ```

2. Clean and rebuild:
   ```
   clean-build.bat
   ```

3. Run the application:
   ```
   run-app.bat
   ```

4. Run the tests:
   ```
   run-tests.bat
   ```

#### macOS
You can use the provided shell scripts to build and run the project:

1. Quick build:
   ```
   ./build.sh
   ```

2. Clean and rebuild:
   ```
   ./clean-build.sh
   ```

3. Run the application:
   ```
   ./run-app.sh
   ```

4. Run the tests:
   ```
   ./run-tests.sh
   ```

### Manual Building

#### Windows
1. Set up the MSVC environment:
   ```
   call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
   ```

2. Build the project:
   ```
   mkdir build
   cd build
   cmake .. -DCMAKE_PREFIX_PATH=C:/Qt/6.8.3/msvc2022_64
   cmake --build . --config Release
   ```

3. Run the demo application:
   ```
   .\build\app\Release\colorapp.exe
   ```

4. Run the tests:
   ```
   .\build\test\Release\qcolor_converter_test.exe
   ```

#### macOS
1. Build the project:
   ```
   mkdir -p build
   cd build
   cmake .. -DCMAKE_PREFIX_PATH=/Users/paneltree/Qt/6.8.3/macos
   cmake --build . --config Release
   ```

2. Run the demo application:
   ```
   ./build/app/colorapp.app/Contents/MacOS/colorapp
   ```

3. Run the tests:
   ```
   ./build/test/qcolor_converter_test
   ```

## Project Structure

- `/lib` - QColor to std::string conversion library
- `/app` - Demo application for the library
- `/test` - Unit tests using Google Test

## Library Usage

```cpp
#include "qcolor2stdstring.h"

// Convert QColor to std::string
QColor color(255, 0, 0);
std::string rgbaStr = ColorConversion::qColorToStdString(color);
std::string hexStr = ColorConversion::qColorToHexString(color, true);

// Convert std::string to QColor
QColor fromRgba = ColorConversion::stdStringToQColor("rgba(255,0,0,1)");
QColor fromHex = ColorConversion::stdStringToQColor("#ff0000");
```

## License

MIT 