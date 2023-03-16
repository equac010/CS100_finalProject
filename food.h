#ifndef FOOD_H
#define FOOD_H

#include <QString>

class Food {
    private:
        QString name;
        int servings;
        int servingSize;
        int carbsPerServing;
        int proteinPerServing;
        int fatPerServing;
        int calPerServing;

    public:
        Food(QString name = "", int servings = 0, int servingSize = 0, int carbsPerServing = 0, int proteinPerServing = 0, int fatPerServing = 0, int calPerServing = 0);

        const QString& getName() const {return name;}
        const int& getServings() const {return servings;}
        const int& getServingSize() const {return servingSize;}
        const int& getCarbsPerServing() const {return carbsPerServing;}
        const int& getProteinPerServing() const {return proteinPerServing;}
        const int& getFatPerServing() const {return fatPerServing;}
        const int& getCalPerServing() const {return calPerServing;}

        float getTotalCarbs() const {return servings / servingSize * carbsPerServing;}
        float getTotalProtein() const {return servings / servingSize * proteinPerServing;}
        float getTotalFat() const {return servings / servingSize * fatPerServing;}
        float getTotalCal() const {return servings / servingSize * calPerServing;}

        void setName(QString input){name = input;}
        void setServings(int input) {servings = input;}
        void setServingSize(int input){servingSize = input;}
        void setCarbsPerServing(int input){carbsPerServing = input;}
        void setProteinPerServing(int input){proteinPerServing = input;}
        void setFatPerServing(int input){fatPerServing = input;}
        void setCalPerServing(int input){calPerServing = input;}
};

#endif
