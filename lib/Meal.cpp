#include "../include/Nutrition.h"
#include "../include/Food.h"
#include "../include/Meal.h"
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

void Meal::removeFood(int i=-1){
   if(i==-1){
      allFood.pop_back();
      return;
   }
   allFood.erase(allFood.begin()+i);
   return;
}
