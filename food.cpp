#include "food.h"
#include <string>

Food::Food(QString name, int servings, int servingSize, int carbsPerServing, int proteinPerServing, int fatPerServing, int calPerServing)
{
    name = name;
    servings = servings;
    servingSize = servingSize;
    carbsPerServing = carbsPerServing;
    proteinPerServing = proteinPerServing;
    fatPerServing = fatPerServing;
    calPerServing = calPerServing;
}
