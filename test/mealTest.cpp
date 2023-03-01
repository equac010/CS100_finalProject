#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/Nutrition.h"
#include "../include/Food.h"
#include "../include/Meal.h"
#include <vector>
#include <iterator>

TEST(MealTests, canCalcTotalNutrition){
    std::vector<Food> foods = {Food("ramen",2,Nutrition(500,40,10,25)),
                               Food("steak",1,Nutrition(1000,80,25,30)),
                               Food("cake",2,Nutrition(250,50,5,50))};
    Meal m(foods);
    Nutrition total(2500,260,55,180);
    EXPECT_TRUE(m.calcTotalNutrition() == total);
}