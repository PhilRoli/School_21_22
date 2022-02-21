#ifndef RES_H
#define RES_H

#include <QString>

class Res
{
private:
    double rValue;

public:
    Res(double value);
    static Res ser(Res r1, Res r2);
    static Res par(Res r1, Res r2);
    Res par(Res r2);

    QString toString();
};

#endif // RES_H
