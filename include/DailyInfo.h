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
        Nutrition calcTotalNutrition() const;
        bool dailyTargetReached() const;
        void addFood(Meal m, Food f){m.addFood(f);}
        void removeFood(Meal m, int n){m.removeFood(n);}
};


#endif