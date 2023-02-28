#include "../include/DailyInfo.h"
#include "../include/Nutrition.h"
#include "../include/Food.h"
#include "../include/Meal.h"
#include <vector>

DailyInfo::DailyInfo(){
   allMeals = std::vector<Meal>(4, Meal());      // meals : breakfast, lunch, dinner, snack
   dailyTarget = Nutrition(2000,130,50,40);    // values predetermined for now
}