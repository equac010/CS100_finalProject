#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/Nutrition.h"

TEST(NutritionTests, constructorWorks){
    EXPECT_NO_THROW(Nutrition(3,52,12,3));
    EXPECT_NO_THROW(Nutrition(-3,-52,-12,-3));
}
TEST(NutritionTests, defaultConstructorWorks){
    EXPECT_NO_THROW(Nutrition());
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
TEST(NutritionTests, canAdd){
    Nutrition n1(250, 20, 15, 40);
    Nutrition n2(400, 15, 30, 60);
    Nutrition n3 = n1 + n2;
    EXPECT_EQ(n3.getCal(), 650);
    EXPECT_EQ(n3.getCarb(), 35);
    EXPECT_EQ(n3.getProtein(), 45);
    EXPECT_EQ(n3.getFat(), 100);
}
TEST(NutritionTets, canAddWithDefault){
    Nutrition n1(250, 20, 15, 40);
    Nutrition n2;
    Nutrition n3 = n1 + n2;
    EXPECT_EQ(n3.getCal(), 250);
    EXPECT_EQ(n3.getCarb(), 20);
    EXPECT_EQ(n3.getProtein(), 15);
    EXPECT_EQ(n3.getFat(), 40);
}
TEST(NutritionTests, canMultiply){
    Nutrition n1(250, 20, 15, 40);
    Nutrition n3 = n1 * 2;
    EXPECT_EQ(n3.getCal(), 500);
    EXPECT_EQ(n3.getCarb(), 40);
    EXPECT_EQ(n3.getProtein(), 30);
    EXPECT_EQ(n3.getFat(), 80);
}
TEST(NutritionTests, equalWorks){
    Nutrition n1(250, 20, 15, 40);
    Nutrition n2(250, 20, 15, 40);
    Nutrition n3(400, 15, 30, 60);
    EXPECT_TRUE(n1 == n2);
    EXPECT_FALSE(n2 == n3);
}