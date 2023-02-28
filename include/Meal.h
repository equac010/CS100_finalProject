#ifndef MEAL_H
#define MEAL_H

#include "Nutrition.h"
#include "Food.h"
#include <vector>
#include <string>

class Meal{
    private: 
        std::vector<Food> allFood;

    public:
        Meal(){std::vector<Food> allFood;};
        Meal(std::vector<Food> allFood): allFood(allFood){}

        std::vector<Food> getAllFood() const{return allFood;}
        void addFood(Food f);
        void removeFood(int i);
        void removeFood(std::string name);

        Nutrition calcTotalNutrition() const;

};

#endif