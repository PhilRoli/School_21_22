#include "frac.h"

Frac::Frac(int n, int d)
{
    mNum = n;
    mDen = d;
}

Frac Frac::mult(Frac a, Frac b)
{
    int num = a.mNum * b.mNum;
    int den = a.mDen * b.mDen;
    return Frac(num, den);
}

QString Frac::toString()
{
    QString str;
    str += QString::number(mNum) + "/" + QString::number(mDen);
    return str;
}
