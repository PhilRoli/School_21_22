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

Frac Frac::add(Frac b)
{
    return add(*this, b);
}

Frac Frac::add(Frac a, Frac b)
{
    int gDen = a.mDen * b.mDen;
    int num = a.mNum * b.mDen + b.mNum * a.mDen;
    return Frac(num, gDen);
}
