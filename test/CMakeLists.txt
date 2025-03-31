enable_testing()

# Find GTest package
find_package(GTest REQUIRED)

# Add test executable
add_executable(qcolor_converter_test
    qcolor2stdstring_test.cpp
)

# Link against GoogleTest and our library
target_link_libraries(qcolor_converter_test
    qcolor2stdstring
    GTest::GTest
    GTest::Main
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

# Deploy Qt DLLs for Windows
if(WIN32)
    # Add custom command to run windeployqt after build
    add_custom_command(TARGET qcolor_converter_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Running windeployqt for test..."
        COMMAND ${WINDEPLOYQT_EXECUTABLE} --no-compiler-runtime
                --no-translations --no-system-d3d-compiler
                $<TARGET_FILE:qcolor_converter_test>
        COMMENT "Deploying Qt dependencies for qcolor_converter_test..."
    )
endif()

# Add tests to be run by CTest
add_test(NAME qcolor_converter_test COMMAND qcolor_converter_test) 