#include "food.h"
#include <Qstring>

Food::Food(){
    name = "";
    servingsTaken = 0;
    nutritionPerServing = Nutrition();
}
Food::Food(QString name, int s, const Nutrition& n){
    name = name;
    servingsTaken = s;
    nutritionPerServing = n;
}
Nutrition Food::calcTotalNutrition() const {
    return nutritionPerServing * servingsTaken;
}
