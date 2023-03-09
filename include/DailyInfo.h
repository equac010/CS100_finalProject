#ifndef DAILYINFO_H
#define DAILYINFO_H

#include "Nutrition.h"
#include "Food.h"
#include "Meal.h"
#include "ICanCalcTotalNutrition.h"
#include <vector>

class DailyInfo: public ICanCalcTotalNutrition{
    private:
        std::vector<Meal> allMeals;
        Nutrition dailyTarget;

    public:
        DailyInfo();
        Nutrition calcTotalNutrition() const override;
        bool dailyTargetReached() const;
        bool dailyCaloricGoalReached() const;
        void addFood(int mealIndex, Food f){allMeals.at(mealIndex).addFood(f);}
        void removeFood(int mealIndex, int n){allMeals.at(mealIndex).removeFood(n);}

        std::vector<Meal> getMeal() const{return allMeals;}
        Meal getBreakfast() const{return allMeals.at(0);}
        Meal getLunch() const{return allMeals.at(1);}
        Meal getDinner() const{return allMeals.at(2);}
        Meal getSnack() const{return allMeals.at(3);}
};


#endif