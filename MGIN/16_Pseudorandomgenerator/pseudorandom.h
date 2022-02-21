#ifndef PSEUDORANDOM_H
#define PSEUDORANDOM_H

class PseudoRandom
{
private:
    unsigned long a = 16807L;
    unsigned long n = 2147483647UL;
    unsigned long currentX;

public:
    PseudoRandom();
    PseudoRandom(long seed);
    double nextRand();
    unsigned long nextIntRand(unsigned int NO_SIDES);
};

#endif // PSEUDORANDOM_H
