#include <QCoreApplication>
#include <QDebug>
#include "frac.h"

int main(int, char **)
{

    Frac f1(1, 3); // f1 ist ein Objekt der Klasse Frac, f1
                   // ist ein Bruch 1/3
    Frac f2(1, 4);

    Frac f3 = Frac::mult(f1, f2);

    qDebug().noquote() << f1.toString() << " * " << f2.toString() << " = " << f3.toString();

    return 0;
}
