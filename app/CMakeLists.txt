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

# Set macOS bundle properties
if(APPLE)
    set_target_properties(colorapp PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.paneltree.colorapp"
        MACOSX_BUNDLE_BUNDLE_NAME "ColorApp"
        MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
    )
endif()

# Deploy Qt dependencies
if(WIN32)
    # Add custom command to run windeployqt after build
    add_custom_command(TARGET colorapp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Running windeployqt..."
        COMMAND ${WINDEPLOYQT_EXECUTABLE} --no-compiler-runtime
                --no-translations --no-system-d3d-compiler
                $<TARGET_FILE:colorapp>
        COMMENT "Deploying Qt dependencies for colorapp..."
    )
elseif(APPLE)
    # Add custom command to run macdeployqt after build
    add_custom_command(TARGET colorapp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Running macdeployqt..."
        COMMAND ${MACDEPLOYQT_EXECUTABLE}
                $<TARGET_BUNDLE_DIR:colorapp>
                -verbose=1
        COMMENT "Deploying Qt dependencies for colorapp..."
    )
endif() 