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

