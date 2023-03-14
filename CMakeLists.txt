cmake_minimum_required(VERSION 3.5)

project(final-project-surfin-and-mergin VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/charts/piechart")

find_package(Qt6 REQUIRED COMPONENTS Charts Core Gui)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Charts REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Charts REQUIRED)



set(PROJECT_SOURCES
    inputform.cpp
    inputform.h
    main.cpp
    mainwindow.cpp
    mainwindow.h
    inputform.ui
    mainwindow.ui
    dailyinfo.cpp
    dailyinfo.h
    food.cpp
    food.h
    ICanCalcTotalNutrition.h
    ISerializable.h
    meal.cpp
    meal.h
    nutrition.cpp
    nutrition.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(final-project-surfin-and-mergin
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET final-project-surfin-and-mergin APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(final-project-surfin-and-mergin SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(final-project-surfin-and-mergin
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(final-project-surfin-and-mergin PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries (final-project-surfin-and-mergin PRIVATE Qt${QT_VERSION_MAJOR}::Charts)
target_link_libraries(final-project-surfin-and-mergin PUBLIC
    Qt::Charts
    Qt::Core
    Qt::Gui
)

set_target_properties(final-project-surfin-and-mergin PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS final-project-surfin-and-mergin
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(TARGETS final-project-surfin-and-mergin
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)




if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(final-project-surfin-and-mergin)
endif()
