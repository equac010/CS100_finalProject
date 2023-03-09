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

    Meal m2;
    EXPECT_TRUE(m2.calcTotalNutrition() == Nutrition());
}

TEST(MealTests, canAddFood){
    std::vector<Food> foods;
    Meal m(foods);
    
    m.addFood(Food("ramen",2,Nutrition(500,40,10,25)));
    Nutrition total1(1000,80,20,50);

    EXPECT_TRUE(m.calcTotalNutrition() == total1);

    m.addFood(Food("steak",1,Nutrition(1000,80,25,30)));
    m.addFood(Food("cake",2,Nutrition(250,50,5,50)));

    Nutrition total2(2500,260,55,180);
    EXPECT_TRUE(m.calcTotalNutrition() == total2);
}

TEST(MealTests, canRemoveFood){
    std::vector<Food> foods;
    Meal m(foods);

    m.addFood(Food("ramen",2,Nutrition(500,40,10,25)));
    m.addFood(Food("steak",1,Nutrition(1000,80,25,30)));
    m.addFood(Food("cake",2,Nutrition(250,50,5,50)));
    m.removeFood(0);
    EXPECT_DEATH(m.removeFood(5), "");
    EXPECT_TRUE(m.calcTotalNutrition() == Nutrition(1500,180,35,130));

    m.removeFood();
    m.addFood(Food("ramen",2,Nutrition(500,40,10,25)));
    EXPECT_TRUE(m.calcTotalNutrition() == Nutrition(2000,160,45,80));

    m.removeFood(1);
    m.removeFood();
    EXPECT_TRUE(m.calcTotalNutrition() == Nutrition());


}