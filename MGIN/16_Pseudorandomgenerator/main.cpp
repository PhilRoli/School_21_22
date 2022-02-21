#include <QCoreApplication>
#include <iostream>

using namespace std;

#include "pseudorandom.h"
int main()
{
    int i;
    cout << endl;
    //-------------------------------
    // Wuerfel
    const unsigned int NO_SIDES = 6;
    int no_rolls = 12000;
    int rollCount[NO_SIDES + 1];
    long seed;
    for (i = 1; i <= NO_SIDES; i++)
    {
        rollCount[i] = 0;
    }
    // prompt for number of rolls
    cout << "Anzahl der Wuerfe: ";
    cin >> no_rolls;
    // prompt for seed
    cout << "Anfangszahl (Seed) >= 1 angeben: ";
    cin >> seed;
    PseudoRandom rollRnd(seed);
    // wuerfeln
    for (i = 1; i <= no_rolls; i++)
    {
        int index = rollRnd.nextIntRand(NO_SIDES) + 1;
        rollCount[index]++;
    }
    cout << "WURF\tHAEUFIGKEIT\trelative HAEUFIGKEIT" << endl;
    for (i = 1; i <= NO_SIDES; i++)
    {
        cout << i << "\t" << rollCount[i];
        cout << "\t\t" << rollCount[i] / (double)no_rolls << endl;
    }
    cout << endl
         << endl;
    return 0;
}
