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
)

# Add tests to be run by CTest
add_test(NAME qcolor_converter_test COMMAND qcolor_converter_test) 