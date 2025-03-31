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

- Qt 6.8.3 (installed at `C:\Qt\6.8.3`)
- Visual Studio 2022 Community (MSVC 2022)
- CMake 3.16 or higher

### Setup

1. Set up the MSVC environment:
   ```
   call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
   ```

2. Build the project:
   ```
   mkdir build
   cd build
   cmake .. -DCMAKE_PREFIX_PATH=C:/Qt/6.8.3/msvc2022_64
   cmake --build .
   ```

### Running

1. Run the demo application:
   ```
   .\app\colorapp.exe
   ```

2. Run the tests:
   ```
   ctest
   ```

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