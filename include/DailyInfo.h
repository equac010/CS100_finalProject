#ifndef DAILYINFO_H
#define DAILYINFO_H

#include "Nutrition.h"
#include "Food.h"
#include "Meal.h"
#include <vector>

class DailyInfo{
    private:
        std::vector<Meal> allMeals;
        Nutrition dailyTarget;

    public:
        DailyInfo();
        Nutrition calcTotalNutrition() const;
        bool dailyTargetReached() const;
        bool dailyCaloricGoalReached() const;
        void addFood(int mealIndex, Food f){allMeals.at(mealIndex).addFood(f);}
        void removeFood(int mealIndex, int n){allMeals.at(mealIndex).removeFood(n);}
};


#endif