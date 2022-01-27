#include "res.h"

Res::Res(double value)
{
    rValue = value;
}

Res Res::ser(Res r1, Res r2)
{
    return r1.rValue + r2.rValue;
}

Res Res::par(Res r1, Res r2)
{
    return (r1.rValue * r2.rValue) / (r1.rValue + r2.rValue);
}

Res Res::par(Res r2)
{
    this->rValue = (this->rValue * r2.rValue) / (this->rValue + r2.rValue);
}

QString Res::toString()
{
    return QString::number(rValue) + " Ohm";
}
