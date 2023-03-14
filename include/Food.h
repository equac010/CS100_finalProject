#ifndef FOOD_H
#define FOOD_H

#include "Nutrition.h"
#include "ICanCalcTotalNutrition.h"
#include "ISerializable.h"
#include <string>

class Food: public ICanCalcTotalNutrition, public ISerializable{
    private:
        std::string name;
        int servingsTaken;
        Nutrition nutritionPerServing;

    public:
        Food();
        Food(std::string, int, const Nutrition&);

        Nutrition calcTotalNutrition() override;

        std::string getName() const{return name;}
        int getServingsTaken() const{return servingsTaken;}
        Nutrition getNutritionPerServing() const{return nutritionPerServing;}

        void setName(std::string s){name=s;}
        void setServingsTaken(int n){servingsTaken = n;}
        void setName(const Nutrition& n){nutritionPerServing = n;}
};

#endif