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
    // static: Methode gehört zur Klasse (nicht zum Objekt)
    static Frac mult(Frac a, Frac b);

    // non-static: Jedes Object der Klasse hat eine eigene add-Funktion
    Frac add(Frac b);

    static Frac add(Frac a, Frac b);

    QString toString();
};

#endif // FRAC_H
