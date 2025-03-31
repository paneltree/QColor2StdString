set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(colorapp
    main.cpp
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui
)

target_link_libraries(colorapp PRIVATE
    qcolor2stdstring
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
) 