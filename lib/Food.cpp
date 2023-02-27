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
Nutrition Food::calcTotalNutrition() const{
    Nutrition total;
    total.setCal(servingsTaken * nutritionPerServing.getCal());
    total.setCarb(servingsTaken * nutritionPerServing.getCarb());
    total.setProtein(servingsTaken * nutritionPerServing.getProtein());
    total.setFat(servingsTaken * nutritionPerServing.getFat());
    return total;
} 