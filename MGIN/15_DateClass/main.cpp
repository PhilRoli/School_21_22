#include <QCoreApplication>
#include "date.h"

#include <iostream>

using namespace std;

int main()
{
    Date d1(3, 2, 2022);
    cout << d1.toString() << endl;
    d1.currentDate();
    cout << d1.toString() << endl;
    d1.inc();
    cout << d1.toString() << endl;
    d1.dec();
    cout << d1.toString() << endl;
    d1.add(50);
    cout << d1.toString() << endl;
    d1.sub(365);
    cout << d1.toString() << endl;
    return 0;
}
