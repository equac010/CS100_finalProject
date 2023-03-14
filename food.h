#ifndef FOOD_H
#define FOOD_H

#include "nutrition.h"
#include "ICanCalcTotalNutrition.h"
#include "ISerializable.h"
#include <QString>

class Food: public ICanCalcTotalNutrition, public ISerializable{
    private:
        QString name;
        int servingsTaken;
        Nutrition nutritionPerServing;

    public:
        Food();
        Food(QString, int, const Nutrition&);

        Nutrition calcTotalNutrition() const override;

        QString getName() const{return name;}
        int getServingsTaken() const{return servingsTaken;}
        Nutrition getNutritionPerServing() const{return nutritionPerServing;}

        void setName(QString s){name=s;}
        void setServingsTaken(int n){servingsTaken = n;}
        void setNutrition(const Nutrition& n){nutritionPerServing = n;}
};

#endif
