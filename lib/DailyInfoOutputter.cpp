#include "../include/IOutputter.h"
#include "../include/DailyInfo.h"
#include "../include/Nutrition.h"
#include "../include/Food.h"
#include "../include/Meal.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <string>

class DailyInfoOutputter: IOutputter{
    private: 
        DailyInfo dailyInfo;
    public:
        DailyInfoOutputter(DailyInfo& d): dailyInfo(d){}
        void printInfo(std::ostream& out) const;
        void printMeal(std::ostream& out, Meal& m) const;
        void printFood(std::ostream& out, Food& f) const;
        void printNutrition(std::ostream& out, Nutrition& n) const;
};

void DailyInfoOutputter::printInfo(std::ostream& out) const{
    Nutrition target = dailyInfo.getDailyTarget();
    Nutrition total = dailyInfo.calcTotalNutrition();
    bool goalAchieved = dailyInfo.dailyTargetReached();
    std::vector<double> nutritionPercentages = dailyInfo.getNutritionPercentages();
    std::vector<int> targetValues = {target.getCal(), target.getCarb(), target.getProtein(), target.getFat()};
    std::vector<int> totalValues = {total.getCal(), total.getCarb(), total.getProtein(), total.getFat()};
    std::vector<std::string> nutritionNames = {"Calories", "Carb", "Protein","Fat"};
    std::vector<std::string> mealNames = {"Breakfast", "Lunch", "Dinner", "Snack"};
    out << "--------------------------------------------------\n";
    out << "--------------------------------------------------\n\n";

    for(unsigned int i = 0; i < 4; i++){
        out << nutritionNames.at(i) << ": " << std::string('*', nutritionPercentages.at(i)*10) << " ";
        out << totalValues.at(i) << "/" << targetValues.at(i) << "g\n";
    }

    if(goalAchieved){
        out << "Daily Goal ACHIEVED :D\n";
    }else{
        out << "Daily Goal NOT ACHIEVED )):<\n";
    }

    out << "--------------------------------------------------";

    for(unsigned int i = 0; i < 4; i++){
        out << mealNames.at(i) << ":\n";
        printMeal(out, dailyInfo.getMeal().at(i));
    }

    out << "\n\n--------------------------------------------------\n";
    out << "--------------------------------------------------";
}
void DailyInfoOutputter::printMeal(std::ostream& out, Meal& m) const{
   std::vector<Food>::const_iterator it;
   std::vector<Food> allFoods = m.getAllFood();
   for(it = allFoods.begin(); it != allFoods.end(); it++){
      Food f = *it;
      printFood(out, f);
   }
}
void DailyInfoOutputter::printFood(std::ostream& out, Food& f) const{
    out << "     (" << f.getServingsTaken() << ") " << f.getName() << ": ";
    Nutrition n = f.calcTotalNutrition();
    printNutrition(out, n);
}
void DailyInfoOutputter::printNutrition(std::ostream& out, Nutrition& n) const{
    out << "Calories: " << n.getCal() << "g  " << "Carbs: " << n.getCarb() << "g  " << "Protein: " << n.getProtein() << "g  " << "Fat: " << n.getFat() << "g\n";
}