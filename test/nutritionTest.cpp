#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/Nutrition.h"

TEST(NutritionTests, constructorWorks){
    EXPECT_NO_THROW(new Nutrition(3,52,12,3));
}
TEST(NutritionTests, defaultConstructorWorks){
    EXPECT_NO_THROW(new Nutrition());
}
TEST(NutritionTests, constructorsAssigningProperValues){
    Nutrition n1(200, 20, 8, 10);
    EXPECT_EQ(n1.getCal(), 200);
    EXPECT_EQ(n1.getCarb(), 20);
    EXPECT_EQ(n1.getProtein(), 8);
    EXPECT_EQ(n1.getFat(), 10);

    Nutrition n2;
    EXPECT_EQ(n2.getCal(), 0);
    EXPECT_EQ(n2.getCarb(), 0);
    EXPECT_EQ(n2.getProtein(), 0);
    EXPECT_EQ(n2.getFat(), 0);
}
TEST(NutritionTests, settersWorking){
    Nutrition n;
    n.setCal(80);
    n.setCarb(20);
    n.setProtein(5);
    n.setFat(2);
    EXPECT_EQ(n.getCal(), 80);
    EXPECT_EQ(n.getCarb(), 20);
    EXPECT_EQ(n.getProtein(), 5);
    EXPECT_EQ(n.getFat(), 2);
}