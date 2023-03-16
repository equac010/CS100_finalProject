#include "../include/DailyInfoOutputter.h"
#include "../include/DailyInfo.h"
#include "../include/Nutrition.h"
#include "../include/Food.h"
#include "../include/Meal.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, char* argv[]) { 
    DailyInfo d;
    DailyInfoOutputter dOutputter = DailyInfoOutputter(d);

    char userInput = ' ';
    while(userInput != 'q'){
        dOutputter = DailyInfoOutputter(d);
        dOutputter.printInfo(std::cout);

        std::cout<<"a (Add Food)  |  r (Remove Food)  |  q (Quit): ";
        std::cin>>userInput;
        std::cout<<"\n";


        std::string name;
        int amount = 1;
        int cal, carb, protein, fat = 0;
        int meal = 0;
        int foodIndex = 0;
        Food f;
        switch(userInput){
            case 'a':
                std::cout<<"ADDING FOOD....\n";
                std::cout<<"Enter food name: ";
                std::cin>>name;
                std::cout<<"Enter servings taken: ";
                std::cin>>amount;
                std::cout<<"\n";
                std::cout<<"Enter calories(g) per serving: ";
                std::cin>>cal;
                std::cout<<"\n";
                std::cout<<"Enter carbohydrates(g) per serving: ";
                std::cin>>carb;
                std::cout<<"\n";
                std::cout<<"Enter protein(g) per serving: ";
                std::cin>>protein;
                std::cout<<"\n";
                std::cout<<"Enter fat(g) per serving: ";
                std::cin>>fat;
                std::cout<<"\n";
                std::cout<<"Select Meal  0 (breakfast), 1 (lunch), 2 (dinner), 3 (snack): ";
                std::cin>>meal;
                std::cout<<"\n";
                
                f = Food(name, std::max(1,amount), Nutrition(std::max(0,cal), std::max(0,carb), std::max(0,protein),std::max(0,fat)));
                f.setName(name);
                if(meal < 0 || meal > 3){
                    meal = 0;
                }
                d.addFood(meal, f);
                break;

            case 'r':
                std::cout<<"REMOVING FOOD....\n";
                std::cout<<"Which meal to Edit  0 (breakfast), 1 (lunch), 2 (dinner), 3 (snack): ";
                std::cin>>meal;
                std::cout<<"Enter the number of the food item you'd like to remove: ";
                std::cin>>foodIndex;
                foodIndex--;

                d.removeFood(meal, foodIndex);
                break;

        }


    }
}