#ifndef MEAL_H
#define MEAL_H

#include "Nutrition.h"
#include "Food.h"
#include "ICanCalcTotalNutrition.h"
#include "ISerializable.h"
#include <vector>
#include <string>

class Meal: public ICanCalcTotalNutrition, public ISerializable{
    private: 
        std::vector<Food> allFood;

    public:
        Meal(){std::vector<Food> allFood;};
        Meal(std::vector<Food> allFood): allFood(allFood){}

        std::vector<Food> getAllFood() const{return allFood;}
        void addFood(Food f){allFood.push_back(f);}
        void removeFood(int i=-1);

        Nutrition calcTotalNutrition() const override;

};

#endif