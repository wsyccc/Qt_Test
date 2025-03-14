cmake_minimum_required(VERSION 3.16)

project(WebTest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Quick QuickWidgets WebEngineWidgets)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appWebTest
        main.cpp
        Model/BaseWidget/BaseWidget.cpp
        Model/BaseWidget/BaseWidget.h
        Model/QuickWidget/QuickWidget.cpp
        Model/QuickWidget/QuickWidget.h
        Model/WebWidget/WebWidget.cpp
        Model/WebWidget/WebWidget.h
        Model/Canvas/Canvas.cpp
        Model/Canvas/Canvas.h
        Widgets/QtQuickView/Rectangle/Rectangle.cpp
        Widgets/QtQuickView/Rectangle/Rectangle.h
        Managers/CanvasManager/CanvasManager.cpp
        Managers/CanvasManager/CanvasManager.h
)

qt_add_qml_module(appWebTest
        URI WebTest
        VERSION 1.0
        QML_FILES
        Main.qml
        Model/Canvas/Canvas.qml
        Widgets/QtQuickView/Rectangle/Rectangle.qml
)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appWebTest PROPERTIES
        #    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appWebTest
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(appWebTest
        PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Quick
        Qt6::QuickWidgets
        Qt6::WebEngineWidgets
)

include(GNUInstallDirs)
install(TARGETS appWebTest
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
