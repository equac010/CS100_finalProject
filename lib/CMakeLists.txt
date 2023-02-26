add_library(simpleLibrary 
    DailyInfo.cpp 
    Food.cpp 
    Meal.cpp 
    Nutrition.cpp 
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})