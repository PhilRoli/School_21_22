#include <QCoreApplication>
#include <QDebug>
#include "frac.h"

int main(int, char **)
{

    Frac f1(1, 3); // f1 ist ein Objekt der Klasse Frac, f1
                   // ist ein Bruch 1/3
    Frac f2(1, 4);

    Frac f3 = Frac::mult(f1, f2);

    Frac f4 = f1.add(f2).add(f3);

    Frac f5 = Frac::add(f1, f2);

    f1.add(f2);

    qDebug().noquote() << f1.toString() << " * " << f2.toString() << " = " << f3.toString();
    qDebug().noquote() << f1.toString() << " + " << f2.toString() << " + " << f3.toString() << " = " << f4.toString();
    qDebug().noquote() << f1.toString() << " + " << f2.toString() << " = " << f5.toString();


    return 0;
}
