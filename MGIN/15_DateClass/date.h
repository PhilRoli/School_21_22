#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <time.h>

class Date
{
private:
    int mD;
    int mM;
    int mY;

public:
    Date(int d, int m, int y);
    static bool isLeap(int y); // Is Leap Year
    std::string toString();
    Date inc(); // Increase Date for 1 day
    Date dec(); // Decrease Date for 1 day
    std::string weekDay();
    Date add(int d); // Increase Date for d days
    Date sub(int d); // Decrease Date for d days
    static Date currentDate();
};

#endif // DATE_H
