cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(googletest)

add_executable(runAllTests 
    ../lib/DailyInfo.cpp
    dailyInfoTest.cpp
    ../lib/Food.cpp
    foodTest.cpp
    ../lib/Meal.cpp
    mealTest.cpp
    ../lib/Nutrition.cpp
    nutritionTest.cpp
)

target_link_libraries(runAllTests gmock gtest gtest_main)
target_link_libraries(runAllTests simpleLibrary)