#ifndef DAILYINFOOUTPUTTER_H
#define DAILYINFOOUTPUTTER_H

#include "../include/IOutputter.h"
#include "../include/DailyInfo.h"
#include "../include/Nutrition.h"
#include "../include/Food.h"
#include "../include/Meal.h"
#include <iostream>

class DailyInfoOutputter: IOutputter{
    private: 
        DailyInfo dailyInfo;
    public:
        DailyInfoOutputter(DailyInfo& d): dailyInfo(d){}
        void printInfo(std::ostream& out) const;
        void printMeal(std::ostream& out, Meal& m) const;
        void printFood(std::ostream& out, Food& f) const;
        void printNutrition(std::ostream& out, Nutrition& n) const;
};

#endif