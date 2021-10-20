project(QtSample)

find_package(Qt5 COMPONENTS
    Core
    Widgets
REQUIRED)

set(CMAKE_AUTOMOC ON)  # Automatically run the meta-object-compiler from Qt on all required files
set(CMAKE_AUTOUIC OFF) # Reason for being turned off: AutoUIC will prevent VS from detecting changes in .ui files
set(CMAKE_AUTORCC OFF) # Reason for being turned off: AutoRCC will create an entirely new project in VS which clutters the solution appearance. Additionally, we cannot assign a source group to the generated .cpp files which will clutter the project.
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(source_files
    src/main.cpp
    src/sample_gui.cpp
    src/sample_gui.h
)

set(qt_resource_files
    resources/resources.qrc
)


set(ui_files
    src/sample_gui.ui
)

# compile qt resource files and ui files
qt5_add_resources(autogen_resources ${qt_resource_files})
qt5_wrap_ui      (autogen_ui        ${ui_files})

# Add all files. The resource files and ui files are not necessary, but we want them to show up in the IDE
add_executable(${PROJECT_NAME} 
    ${source_files}
    ${qt_resource_files}
    ${ui_files}

    ${autogen_resources}
    ${autogen_ui}
)
target_link_libraries (${PROJECT_NAME}
    Qt5::Widgets
)

target_include_directories(${PROJECT_NAME} PRIVATE src)

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)

if(MSVC)
    set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "/wd4127 /wd4714")
ENDIF(MSVC)

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_options(${PROJECT_NAME} PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/ignore:4098,4099>)

if(WIN32)
    include(${CMAKE_CURRENT_LIST_DIR}/cmake/qt_windeployqt.cmake)
    # Deploy Qt DLLs in the binary folder. This is necessary for starting the application from whithin the IDE without having to copy QtCore.dll, QtWidgets.dll etc. by hand each time
    qt_add_windeployqt_postbuild(--no-system-d3d-compiler --no-compiler-runtime --no-opengl-sw --pdb "$<TARGET_FILE:${PROJECT_NAME}>")
endif()
