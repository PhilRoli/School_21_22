#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QString>

class Rectangle
{
private:
    int mL;
    int mW;

public:
    Rectangle(int l, int w);
    QString toString();
    void setMl(int l);
    void setMw(int w);
    int getMl();
    int getMw();
    int calcA();
    int calcU();
    QString draw(char symbol);
};

#endif // RECTANGLE_H
