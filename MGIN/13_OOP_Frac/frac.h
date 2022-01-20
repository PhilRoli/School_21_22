#ifndef FRAC_H
#define FRAC_H
#include <QString>

class Frac
{
private:
    int mNum;
    int mDen;

public:
    Frac(int n, int d); // Konstruktor
    static Frac mult(Frac a, Frac b);

    QString toString();
};

#endif // FRAC_H
