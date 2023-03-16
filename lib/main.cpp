#include "../include/DailyInfoOutputter.h"
#include "../include/DailyInfo.h"
#include "../include/Nutrition.h"
#include "../include/Food.h"
#include "../include/Meal.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) { 
    DailyInfo d;
    DailyInfoOutputter dOutput = DailyInfoOutputter(d);
    dOutput.printInfo(std::cout);
}