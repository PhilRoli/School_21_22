#include "rectangle.h"

Rectangle::Rectangle(int l, int w)
{
    mL = l;
    mW = w;
}

QString Rectangle::toString()
{
    QString str;
    str = "Rechteck with (l=" + QString::number(mL) + ", w=" + QString::number(mW) + ")";
    return str;
};

void Rectangle::setMl(int l)
{
    if (l <= 0)
    {
        mL = -l;
    }
    else
    {
        mL = l;
    }
};

void Rectangle::setMw(int w)
{
    if (w <= 0)
    {
        mW = -w;
    }
    else
    {
        mW = w;
    }
};

int Rectangle::getMl()
{
    return mL;
};
int Rectangle::getMw()
{
    return mW;
};

int Rectangle::calcA()
{
    return mW * mL;
}

int Rectangle::calcU()
{
    return 2 * mW + 2 * mL;
}

QString Rectangle::draw(char symbol)
{
    QString drawing;
    for (int i = 1; i <= mL; i++)
    {
        for (int j = 1; j <= mW; j++)
        {
            drawing += symbol;
        }
        drawing += "\n";
    }
    return drawing;
}
