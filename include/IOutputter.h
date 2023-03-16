#ifndef IOUTPUTTER_H
#define IOUTPUTTER_H
#include <iostream>

class IOutputter{
    public:
        virtual void printInfo(std::ostream& out) const = 0;
};

#endif