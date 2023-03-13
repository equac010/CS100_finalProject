#include "../include/nutrition.h"

Nutrition Nutrition::operator+(const Nutrition& n) const{
    return Nutrition(getCal()+n.getCal(),getCarb()+n.getCarb(),getProtein()+n.getProtein(),getFat()+n.getFat());
}

Nutrition Nutrition::operator*(int n) const{
    return Nutrition(getCal()*n,getCarb()*n,getProtein()*n,getFat()*n);
}

bool Nutrition::operator==(const Nutrition& n) const{
    return (getCal()==n.getCal())&&(getCarb()==n.getCarb())&&(getProtein()==n.getProtein())&&(getFat()==n.getFat());
}
