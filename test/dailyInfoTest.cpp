#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/DailyInfo.h"
#include "../include/Nutrition.h"
#include "../include/Food.h"
#include "../include/Meal.h"
#include <vector>

TEST(DailyInfoTests, defaultConstructorWorks){
    EXPECT_NO_THROW(DailyInfo());
    DailyInfo d = DailyInfo();
    std::vector<Meal> m = d.getMeal();
    EXPECT_EQ(m.size(), 4);
    EXPECT_EQ(m.at(0).getAllFood().size(), 0);
}
TEST(DailyInfoTests, canCalcTotalNutrition){
    DailyInfo empty;
    EXPECT_TRUE(empty.calcTotalNutrition()==Nutrition());

    DailyInfo d;
    d.addFood(1,Food("ramen",2,Nutrition(500,40,10,25)));
    d.addFood(2,Food("steak",1,Nutrition(1000,80,25,30)));
    d.addFood(2,Food("steak",1,Nutrition(1000,80,25,30)));
    d.addFood(3,Food("cake",2,Nutrition(250,50,5,50)));
    Nutrition totalCheck(3500,340,80,210);
    EXPECT_TRUE(totalCheck == d.calcTotalNutrition());
}


