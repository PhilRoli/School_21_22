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
    return (a * currentX) % n;
}

int PseudoRandom::nextIntRand(int NO_SIDES)
{
}
