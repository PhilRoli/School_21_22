#include "pseudorandom.h"

PseudoRandom::PseudoRandom()
{
    currentX = 123L;
}

PseudoRandom::PseudoRandom(long seed)
{
    this->currentX = seed;
}

double PseudoRandom::nextRand()
{
    currentX = ((a * currentX) % n);
    return (double)currentX / n;
}

unsigned long PseudoRandom::nextIntRand(unsigned int NO_SIDES)
{
    return nextRand() * NO_SIDES;
}
