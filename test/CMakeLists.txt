enable_testing()

# Add GoogleTest
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Add test executable
add_executable(qcolor_converter_test
    qcolor2stdstring_test.cpp
)

# Link against GoogleTest and our library
target_link_libraries(qcolor_converter_test
    qcolor2stdstring
    gtest
    gtest_main
    Qt6::Core
    Qt6::Gui
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