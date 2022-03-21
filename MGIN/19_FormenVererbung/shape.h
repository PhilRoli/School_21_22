#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
protected:
    int color = 0;

public:
    // Abstract function -> Makes complete Function Abstract
    // If complete class is abstract -> No object can be made of it
    // Every derived class HAS to implement toString()
    virtual std::string toString() = 0;
    int getColor();
};

#endif // SHAPE_H
