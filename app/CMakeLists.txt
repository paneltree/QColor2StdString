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

# Deploy Qt DLLs for Windows
if(WIN32)
    # Add custom command to run windeployqt after build
    add_custom_command(TARGET colorapp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Running windeployqt..."
        COMMAND ${WINDEPLOYQT_EXECUTABLE} --no-compiler-runtime
                --no-translations --no-system-d3d-compiler
                $<TARGET_FILE:colorapp>
        COMMENT "Deploying Qt dependencies for colorapp..."
    )
endif() 