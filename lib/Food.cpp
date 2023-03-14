#include "../include/Food.h"
#include <string>

Food::Food(){
    name = "";
    servingsTaken = 0;
    nutritionPerServing = Nutrition();
}
Food::Food(std::string name, int s, const Nutrition& n){
    name = name;
    servingsTaken = s;
    nutritionPerServing = n;
}
Nutrition Food::calcTotalNutrition(){
    return nutritionPerServing * servingsTaken;
} 