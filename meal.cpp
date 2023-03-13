#include "../include/nutrition.h"
#include "../include/food.h"
#include "../include/meal.h"
#include <vector>
#include <iterator>

Nutrition Meal::calcTotalNutrition() const{
   Nutrition total;
   std::vector<const Food>::iterator it;
   for(it = allFood.begin(); it != allFood.end(); it++){
      total = total + (*it).calcTotalNutrition();
   }
   return total;
}

void Meal::removeFood(int i){
   if(i==-1){
      allFood.pop_back();
      return;
   }
   allFood.erase(allFood.begin()+i);
   return;
}
