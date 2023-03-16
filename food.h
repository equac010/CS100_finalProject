#ifndef FOOD_H
#define FOOD_H

#include <QString>

class Food {
    private:
        QString name;
        double servings;
        int carbsPerServing;
        int proteinPerServing;
        int fatPerServing;
        int calPerServing;

    public:
        Food(QString name = "", double servings = 0, int carbsPerServing = 0, int proteinPerServing = 0, int fatPerServing = 0, int calPerServing = 0);

        const QString& getName() const {return name;}
        const double& getServings() const {return servings;}
        const int& getCarbsPerServing() const {return carbsPerServing;}
        const int& getProteinPerServing() const {return proteinPerServing;}
        const int& getFatPerServing() const {return fatPerServing;}
        const int& getCalPerServing() const {return calPerServing;}

        float getTotalCarbs() const {return servings * carbsPerServing;}
        float getTotalProtein() const {return servings * proteinPerServing;}
        float getTotalFat() const {return servings * fatPerServing;}
        float getTotalCal() const {return servings * calPerServing;}

        void setName(QString input){name = input;}
        void setServings(int input) {servings = input;}
        void setCarbsPerServing(int input){carbsPerServing = input;}
        void setProteinPerServing(int input){proteinPerServing = input;}
        void setFatPerServing(int input){fatPerServing = input;}
        void setCalPerServing(int input){calPerServing = input;}
};

#endif
