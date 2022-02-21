#include <QCoreApplication>
#include <QDebug>
#include "rectangle.h"

int main(int argc, char *argv[])
{
    // Creates Rectangle r (Object)
    // From type Rectangle (Class)
    Rectangle r(2, 4);

    r.setMl(-17);

    qDebug() << r.toString();
    qDebug() << "Area:" << r.calcA();
    qDebug() << "Circumference:" << r.calcU();
    qDebug() << r.draw('*');

    return 0;
}
