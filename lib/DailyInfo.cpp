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

DailyInfo::DailyInfo(Nutrition n){
   allMeals = std::vector<Meal>(4, Meal());      // meals : breakfast, lunch, dinner, snack
   dailyTarget = n;
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
   std::vector<double> percs;
   Nutrition totalNutrition = calcTotalNutrition();

   percs.push_back((std::min(1.0, totalNutrition.getCal()/(double)(dailyTarget.getCal()))));
   percs.push_back(std::min(1.0, totalNutrition.getCarb()/(double)(dailyTarget.getCarb())));
   percs.push_back(std::min(1.0, totalNutrition.getProtein()/(double)(dailyTarget.getProtein())));
   percs.push_back(std::min(1.0, totalNutrition.getFat()/(double)(dailyTarget.getFat())));

   return percs;
}

bool DailyInfo::dailyTargetReached() const{
   Nutrition total = calcTotalNutrition();
   return (total.getCal() >= dailyTarget.getCal() && 
           total.getCarb() >= dailyTarget.getCarb() &&
           total.getProtein() >= dailyTarget.getProtein() &&
           total.getFat() >= dailyTarget.getFat());
}