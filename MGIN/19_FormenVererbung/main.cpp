#include <QCoreApplication>
#include <iostream>
#include <sstream> // StringStream
#include "shape.h"

class Rectangle : public Shape
{
    // Only derived classes cann acces
protected:
    int length;
    int width;

public:
    // Default Constructor
    // Rectangle() {}
    Rectangle(int aLength, int aWidth)
    {
        length = aLength;
        width = aWidth;
    }
    Rectangle(int aLength, int aWidth, int aColor)
    {
        length = aLength;
        width = aWidth;
        color = aColor;
    }

    int getArea()
    {
        return length * width;
    }

    virtual std::string toString()
    {
        std::ostringstream os;
        os << "Rectangle \t length=" << length << " width=" << width << " area=" << getArea();
        return os.str();
    }
};

// Square is derived of Rectangle
// Rectangle is basis class
// Square inherits everything from Rectangle
class Square : public Rectangle
{
public:
    Square(int aSide) : Rectangle(aSide, aSide){};
    Square(int aSide, int aColor) : Rectangle(aSide, aSide, aColor){};

    std::string toString()
    {
        std::ostringstream os;
        os << "Square \t side=" << length << " area=" << getArea();
        return os.str();
    }
};

class Triangle : public Shape
{
protected:
    int side1;
    int side2;
    int side3;

public:
    Triangle(int aSide1, int aSide2, int aSide3)
    {
        side1 = aSide1;
        side2 = aSide2;
        side3 = aSide3;
    }

    int getArea()
    {
        return 0;
    }

    virtual std::string toString()
    {
        std::ostringstream os;
        os << "Triangle \t side1=" << side1 << " side2=" << side2 << " side3=" << side3 << " area=" << getArea();
        return os.str();
    }
};

class sameTriangle : public Triangle
{
public:
    sameTriangle(int side) : Triangle(side, side, side){};

    std::string toString()
    {
        std::ostringstream os;
        os << "sTriangle \t side=" << side1 << " area=" << getArea();
        return os.str();
    }
};

int main()
{
    Rectangle r1(3, 2);
    Rectangle r2(3, 2, 9);

    Square s1(2);
    Square s2(2, 6);

    Rectangle r3 = s2;

    Triangle t1(2, 2, 3);
    sameTriangle t2(2);

    // Polymorphismus
    Shape *shapeList[] = {&r1, &r2, &r3, &s1, &s2, &t1, &t2};

    for (int i = 0; i < 7; i++)
    {
        std::cout << i << " : " << shapeList[i]->toString() << std::endl;
    }
    return 0;
}
