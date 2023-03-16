cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_BUILD_TYPE Debug)

add_library(simpleLibrary 
    DailyInfo.cpp 
    Food.cpp 
    Meal.cpp 
    Nutrition.cpp 
)

add_executable(main
    main.cpp
    DailyInfo.cpp
    Food.cpp
    Meal.cpp
    Nutrition.cpp
    DailyInfoOutputter.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})