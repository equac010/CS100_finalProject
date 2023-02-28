#ifndef DAILYINFO_H
#define DAILYINFO_H

#include "Nutrition.h"
#include "Food.h"
#include "Meal.h"

class DailyInfo{
    private:
        Meal breakfast;
        Meal lunch;
        Meal dinner;
        Meal snack;
        Nutrition dailyTarget;

    public:
        Nutrition calcTotalNutrition() const;
        bool dailyTargetReached() const;
        void addFood(Meal m, Food f){m.addFood(f);}
        void removeFood(Meal m, int n){m.removeFood(n);}
};


#endif