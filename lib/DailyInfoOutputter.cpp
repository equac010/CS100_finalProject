#include "../include/IOutputter.h"
#include "../include/DailyInfo.h"
#include "../include/Nutrition.h"
#include "../include/Food.h"
#include "../include/Meal.h"
#include <vector>
#include <iterator>
#include <iostream>

class DailyInfoOutputter: IOutputter{
    private: 
        DailyInfo dailyInfo;
    public:
        DailyInfoOutputter(DailyInfo& d): dailyInfo(d){}
        void printInfo(std::ostream& out) const;
        void printMeal(std::ostream& out) const;
        void printFood(std::ostream& out, Food& const f) const;
        void printNutrition(std::ostream& out, Nutrition& const n) const;
};

void DailyInfoOutputter::printInfo(std::ostream& out) const{

}
void DailyInfoOutputter::printMeal(std::ostream& out) const{

}
void DailyInfoOutputter::printFood(std::ostream& out, Food& const f) const{
    out << "(" << f.getServingsTaken() << ") " << f.getName() << ": ";
    printNutrition(out, f.calcTotalNutrition());
}
void DailyInfoOutputter::printNutrition(std::ostream& out, Nutrition& const n) const{
    out << "Calories: " << n.getCal() << "g  " << "Carbs: " << n.getCarb() << "g  " << "Protein: " << n.getProtein() << "g  " << "Fat: " << n.getFat() << "g\n";
}