#include "food.h"
#include <string>

Food::Food(QString name, double servings, int carbsPerServing, int proteinPerServing, int fatPerServing, int calPerServing)
{
    name = name;
    servings = servings;
    carbsPerServing = carbsPerServing;
    proteinPerServing = proteinPerServing;
    fatPerServing = fatPerServing;
    calPerServing = calPerServing;
}
