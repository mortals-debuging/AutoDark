cmake_minimum_required(VERSION 3.5)

project(AutoDark VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools DBus)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools DBus)
find_package(Qt6 REQUIRED COMPONENTS Widgets LinguistTools DBus)

#qt_add_dbus_adaptor(GENERATED_SOURCES org.example.chat.xml chat.h ChatMainWindow)

set(TS_FILES AutoDark_zh_CN.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        themeswitcher.cpp
        themeswitcher.h
        ${TS_FILES}
        images.qrc
)

qt_add_executable(AutoDark
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)
qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

target_link_libraries(AutoDark PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::DBus)

set_target_properties(AutoDark PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS AutoDark
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(AutoDark)
endif()
