#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/Food.h"
#include "../include/Nutrition.h"

TEST(FoodTests, constructorNoFail){
    EXPECT_NO_THROW(Food());
    Nutrition n;
    EXPECT_NO_THROW(Food("steak", 1, n));
}

TEST(FoodTests, calcTotalNutritionTest){
    Nutrition n(500, 40, 10, 25);
    Food f("ramen", 3, n);
    Nutrition total = f.calcTotalNutrition();
    Nutrition check = Nutrition(1500, 120, 30, 75);
    EXPECT_TRUE(total == check);
}