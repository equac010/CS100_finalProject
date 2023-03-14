#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/Food.h"
#include "../include/Nutrition.h"

TEST(FoodTests, constructorNoFail){
    EXPECT_NO_THROW(Food());
    Nutrition n;
    EXPECT_NO_THROW(Food("steak", 1, n));
}
TEST(FoodTests, defaultConstrucWorks){
    Nutrition emptyNutrition;
    Food f;
    EXPECT_EQ(f.getName(), "");
    EXPECT_EQ(f.getServingsTaken(), 0);
    EXPECT_TRUE(f.getNutritionPerServing() == emptyNutrition);
}
TEST(FoodTests, calcTotalNutritionTest){
    Nutrition n(500, 40, 10, 25);
    Food f("ramen", 3, n);
    Nutrition total = f.calcTotalNutrition();
    Nutrition check = Nutrition(1500, 120, 30, 75);
    EXPECT_TRUE(total == check);
}
TEST(FoodTests, zeroTotalNutrition){
    Food f1;
    Food f2 = Food("apple", 5, Nutrition());
    Nutrition f1TotalNutrition = f1.calcTotalNutrition();
    Nutrition f2TotalNutrition = f2.calcTotalNutrition();
    EXPECT_TRUE(f1TotalNutrition == Nutrition());
    EXPECT_TRUE(f2TotalNutrition == Nutrition());
}