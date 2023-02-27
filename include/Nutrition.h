#ifndef NUTRITION_H
#define NUTRITION_H

class Nutrition{
    private:
        // values all in grams
        int carb;
        int protein;
        int fat;
        int cal;

    public:
        Nutrition() : cal(0), carb(0), protein(0), fat(0){}
        Nutrition(int cal, int carb, int protein, int fat) : cal(cal), carb(carb), protein(protein), fat(fat){}

        int getCarb() const {return carb;}
        int getProtein() const {return protein;}
        int getFat() const {return fat;}
        int getCal() const {return cal;}

        void setCarb(int n){carb = n;}
        void setProtein(int n){protein = n;}
        void setFat(int n){fat = n;}
        void setCal(int n){cal = n;}

};

#endif