#include "../include/IOutputter.h"
#include "../include/DailyInfo.h"
#include "../include/DailyInfoOutputter.h"
#include "../include/Nutrition.h"
#include "../include/Food.h"
#include "../include/Meal.h"
#include <iomanip>
#include <vector>
#include <iterator>
#include <iostream>
#include <string>

void DailyInfoOutputter::printInfo(std::ostream& out) const{
    Nutrition target = dailyInfo.getDailyTarget();
    Nutrition total = dailyInfo.calcTotalNutrition();
    bool goalAchieved = dailyInfo.dailyTargetReached();
    std::vector<double> nutritionPercentages = dailyInfo.getNutritionPercentages();
    std::vector<int> targetValues = {target.getCal(), target.getCarb(), target.getProtein(), target.getFat()};
    std::vector<int> totalValues = {total.getCal(), total.getCarb(), total.getProtein(), total.getFat()};
    std::vector<std::string> nutritionNames = {"Calories", "Carb", "Protein","Fat"};
    std::vector<std::string> mealNames = {"Breakfast", "Lunch", "Dinner", "Snack"};
    out << "\n\n-------------------------------------------------------------\n";
    out << "-------------------------------------------------------------\n";

    for(unsigned int i = 0; i < 4; i++){
        out << std::setw(10) << nutritionNames.at(i) << ": " << std::string(nutritionPercentages.at(i)*10, '*');
        out << std::string(10-(nutritionPercentages.at(i)*10), '-') << " ";
        out << totalValues.at(i) << "/" << targetValues.at(i) << "g\n";
    }

    if(goalAchieved){
        out << "\nDaily Goal ACHIEVED :D\n";
    }else{
        out << "\nDaily Goal NOT ACHIEVED )):<\n";
    }

    out << "\n";

    for(unsigned int i = 0; i < 4; i++){
        out << mealNames.at(i) << ":\n";
        printMeal(out, dailyInfo.getMeal().at(i));
    }

    out << "-------------------------------------------------------------\n";
    out << "-------------------------------------------------------------\n\n";
}
void DailyInfoOutputter::printMeal(std::ostream& out, Meal& m) const{
   std::vector<Food> allFoods = m.getAllFood();
   for(unsigned int i = 0; i < allFoods.size(); i++){
      Food f = allFoods.at(i);
      out << "    " << i+1 << ". ";
      printFood(out, f);
   }
}
void DailyInfoOutputter::printFood(std::ostream& out, Food& f) const{
    out << f.getName() << " (" << f.getServingsTaken() << ") : ";
    Nutrition n = f.calcTotalNutrition();
    printNutrition(out, n);
}
void DailyInfoOutputter::printNutrition(std::ostream& out, Nutrition& n) const{
    out << "cal " << n.getCal() << "g  " << "carb " << n.getCarb() << "g  " << "protein " << n.getProtein() << "g  " << "fat " << n.getFat() << "g\n";
}