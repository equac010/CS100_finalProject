#ifndef DAILYINFO_H
#define DAILYINFO_H

#include "nutrition.h"
#include "food.h"
#include "meal.h"
#include "ICanCalcTotalNutrition.h"
#include "ISerializable.h"
#include <vector>

class DailyInfo: public ICanCalcTotalNutrition, public ISerializable{
    private:
        std::vector<Meal> allMeals;
        Nutrition dailyTarget;

    public:
        DailyInfo();
        DailyInfo(Nutrition n);
        Nutrition calcTotalNutrition() ;
        bool dailyTargetReached();
        bool dailyCaloricGoalReached() {return (calcTotalNutrition().getCal() >= dailyTarget.getCal());}
        std::vector<double> getNutritionPercentages();
        void addFood(int mealIndex, Food f){allMeals.at(mealIndex).addFood(f);}
        void removeFood(int mealIndex, int n=-1){allMeals.at(mealIndex).removeFood(n);}

        std::vector<Meal> getMeal() const{return allMeals;}
        Meal getBreakfast() const{return allMeals.at(0);}
        Meal getLunch() const{return allMeals.at(1);}
        Meal getDinner() const{return allMeals.at(2);}
        Meal getSnack() const{return allMeals.at(3);}
};


#endif
