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

TEST(DailyInfoTests, oneParamConstructorWorks){
    EXPECT_NO_THROW(DailyInfo(Nutrition(200,30,20,10)));
}

TEST(DailyInfoTests, addFoodWorks){
    DailyInfo d;
    d.addFood(0,Food("ramen",2,Nutrition(500,40,10,25)));
    d.addFood(1,Food("steak",1,Nutrition(1000,80,25,30)));
    d.addFood(1,Food("steak",1,Nutrition(1000,80,25,30)));

    Meal m0 = d.getMeal().at(0);
    Meal m1 = d.getMeal().at(1);
    Meal m2 = d.getMeal().at(2);

    EXPECT_EQ(m0.getAllFood().size(), 1);
    EXPECT_EQ(m1.getAllFood().size(), 2);
    EXPECT_EQ(m2.getAllFood().size(), 0);
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

TEST(DailyInfoTests, removeFoodWorks){
    DailyInfo d;
    d.addFood(1,Food("ramen",2,Nutrition(500,40,10,25)));
    d.addFood(2,Food("steak",1,Nutrition(1000,80,25,30)));
    d.addFood(2,Food("steak",1,Nutrition(1000,80,25,30)));
    d.addFood(3,Food("cake",2,Nutrition(250,50,5,50)));
    d.addFood(3,Food("ramen",1,Nutrition(500,40,10,25)));
    d.removeFood(3,1);

    Meal m = d.getMeal().at(3);
    EXPECT_EQ(m.calcTotalNutrition(), Nutrition(500,100,10,100));

    d.removeFood(2,0);
    m = d.getMeal().at(2);
    EXPECT_EQ(m.calcTotalNutrition(), Nutrition(1000,80,25,30));
}

TEST(DailyInfoTests, oneParamRemoveFoodWorks){
    DailyInfo d;
    d.addFood(1,Food("ramen",2,Nutrition(500,40,10,25)));
    d.addFood(2,Food("steak",1,Nutrition(1010,80,25,30)));
    d.addFood(2,Food("steak",1,Nutrition(1000,80,25,30)));
    d.addFood(3,Food("cake",2,Nutrition(250,50,5,50)));
    d.addFood(3,Food("ramen",1,Nutrition(500,40,10,25)));
    d.removeFood(3);
    d.removeFood(3);
    d.removeFood(2);
    d.removeFood(1);
    EXPECT_EQ(d.calcTotalNutrition(), Nutrition(1010,80,25,30));
}

TEST(DailyInfoTests, DailyTargetReachedWorks){
    DailyInfo d(Nutrition(2000,130,50,40));
    d.addFood(0,Food("steak",1,Nutrition(1000,100,10,30)));
    d.addFood(3,Food("ramen",1,Nutrition(1000,50,10,25)));
    EXPECT_FALSE(d.dailyTargetReached());

    d.addFood(2, Food("candy",1,Nutrition(10,10,40,10)));
    EXPECT_TRUE(d.dailyTargetReached());
}

TEST(DailyInfoTests, getNutritionPercentagesWorks){
    DailyInfo d(Nutrition(2500, 200, 100, 100));
    d.addFood(0,Food("steak",1,Nutrition(1000,50,50,100)));
    d.addFood(3,Food("ramen",1,Nutrition(1000,50,50,1)));

    std::vector<double> expectedPercs = {0.8,0.5,1,1};
    std::vector<double> percs = d.getNutritionPercentages();
    for(unsigned int i = 0; i<expectedPercs.size(); i++){
        EXPECT_NEAR(expectedPercs.at(i), percs.at(i), 0.00001);
    }
}


