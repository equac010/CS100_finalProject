#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/Food.h"
#include "../include/Nutrition.h"

TEST(FoodTests, constructorNoFail){
    EXPECT_NO_THROW(new Food());
    Nutrition n;
    EXPECT_NO_THROW(new Food("steak", 1, n));
}

TEST(FoodTests, calcTotalNutritionTest){
    Nutrition n(500, 40, 10, 25);
    Food f("ramen", 3, n);
    Nutrition total = f.calcTotalNutrition();
    EXPECT_EQ(total.getCal(), 1500);
    EXPECT_EQ(total.getCarb(), 120);
    EXPECT_EQ(total.getProtein(), 30);
    EXPECT_EQ(total.getFat(), 75);
}