#ifndef PSEUDORANDOM_H
#define PSEUDORANDOM_H

class PseudoRandom
{
private:
    unsigned long a = 16807;
    unsigned long n = 2147483647;
    unsigned long currentX;

public:
    PseudoRandom();
    PseudoRandom(long seed);
    double nextRand();
    static int nextIntRand(int NO_SIDES);
};

#endif // PSEUDORANDOM_H
