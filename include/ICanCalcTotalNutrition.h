#ifndef ICANCALCTOTALNUTRITION_H
#define ICANCALCTOTALNUTRITION_H
#include "Nutrition.h"

class ICanCalcTotalNutrition{
    public:
        virtual Nutrition calcTotalNutrition() const = 0;
};

#endif