#include "../include/DailyInfo.h"
#include "../include/Nutrition.h"
#include "../include/Food.h"
#include "../include/Meal.h"
#include <vector>
#include <iterator>

DailyInfo::DailyInfo(){
   allMeals = std::vector<Meal>(4, Meal());      // meals : breakfast, lunch, dinner, snack
   dailyTarget = Nutrition(2000,130,50,40);    // values predetermined for now
}

Nutrition DailyInfo::calcTotalNutrition() const{
   Nutrition total;
   std::vector<const Meal>::iterator it;
   for(it = allMeals.begin(); it != allMeals.end(); it++){
      total = total + (*it).calcTotalNutrition();
   }
   return total;
}

std::vector<double> DailyInfo::getNutritionPercentages() const{
   // order: calories, carb, protein, fat
   std::vector<double> percs(4);
   Nutrition totalNutrition = calcTotalNutrition();

   percs.push_back(std::min(1.0, dailyTarget.getCal()/(double)(dailyTarget.getCal())));
   percs.push_back(std::min(1.0, dailyTarget.getCarb()/(double)(dailyTarget.getCarb())));
   percs.push_back(std::min(1.0, dailyTarget.getProtein()/(double)(dailyTarget.getProtein())));
   percs.push_back(std::min(1.0, dailyTarget.getFat()/(double)(dailyTarget.getFat())));

   return percs;
}
