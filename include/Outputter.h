#ifndef OUTPUTTER_H
#define OUTPUTTER_H
#include <iostream>

class Outputter{
    public:
        virtual void printInfo(std::ostream& out) const = 0;
};

#endif