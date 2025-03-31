add_library(qcolor2stdstring STATIC
    qcolor2stdstring.h
    qcolor2stdstring.cpp
)

target_include_directories(qcolor2stdstring PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(qcolor2stdstring PRIVATE Qt6::Core Qt6::Gui) 