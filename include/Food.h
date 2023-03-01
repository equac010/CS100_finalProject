#ifndef FOOD_H
#define FOOD_H

#include "Nutrition.h"
#include <string>

class Food{
    private:
        std::string name;
        int servingsTaken;
        Nutrition nutritionPerServing;

    public:
        Food();
        Food(std::string, int, const Nutrition&);

        Nutrition calcTotalNutrition() const;

        std::string getName() const{return name;}
        int getServingsTaken() const{return servingsTaken;}
        Nutrition getNutritionPerServing() const{return nutritionPerServing;}

        void setName(std::string s){name=s;}
        void setServingsTaken(int n){servingsTaken = n;}
        void setName(const Nutrition& n){nutritionPerServing = n;}
};

#endif