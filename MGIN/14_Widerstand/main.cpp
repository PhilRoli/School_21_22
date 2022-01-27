#include <QCoreApplication>
#include <QDebug>
#include "res.h"

int main(int argc, char *argv[])
{
    Res r1(100);
    Res r2(100);
    Res r3(100);

    Res r4 = Res::par(r1, r2).par(r3);
    Res r5 = Res::ser(r1, r2).par(r3);

    qDebug().noquote() << "(r1 || r2) || r3 => " << r4.toString();
    qDebug().noquote() << "(r1 + r2) || r3 => " << r5.toString();

    return 0;
}
