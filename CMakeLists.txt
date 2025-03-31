cmake_minimum_required(VERSION 3.16)
project(QColor2StdString VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Add subdirectories
add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(test) 