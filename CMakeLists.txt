cmake_minimum_required(VERSION 3.16)
project(QColor2StdString VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Set the path to deployment tools
if(WIN32)
    get_target_property(_qmake_executable Qt6::qmake IMPORTED_LOCATION)
    get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")

    if(WINDEPLOYQT_EXECUTABLE)
        message(STATUS "Found windeployqt: ${WINDEPLOYQT_EXECUTABLE}")
    else()
        message(FATAL_ERROR "windeployqt not found")
    endif()
elseif(APPLE)
    get_target_property(_qmake_executable Qt6::qmake IMPORTED_LOCATION)
    get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
    find_program(MACDEPLOYQT_EXECUTABLE macdeployqt HINTS "${_qt_bin_dir}")

    if(MACDEPLOYQT_EXECUTABLE)
        message(STATUS "Found macdeployqt: ${MACDEPLOYQT_EXECUTABLE}")
    else()
        message(FATAL_ERROR "macdeployqt not found")
    endif()
endif()

# Option to build tests
option(BUILD_TESTS "Build the test suite" OFF)

# Add subdirectories
add_subdirectory(lib)
add_subdirectory(app)

# Only build tests if requested
if(BUILD_TESTS)
    add_subdirectory(test)
endif() 