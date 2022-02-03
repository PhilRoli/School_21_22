#include "date.h"

Date::Date(int d, int m, int y)
{
    mY = y;

    mM = m;
    if (m < 1)
        mM = 1;
    if (m > 12)
        mM = 12;

    int lenMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeap(mY))
        lenMonth[1] = 29;

    mD = d;
    if (d < 1)
        mD = 1;
    if (d > lenMonth[mM - 1])
        mD = lenMonth[mM - 1];
}

bool Date::isLeap(int y)
{
    if (y % 400 == 0)
        return true;
    if (y % 100 == 0)
        return false;
    if (y % 4 == 0)
        return true;
    return false;
}

std::string Date::toString()
{
    std::string year = std::to_string(this->mY);
    std::string month = std::to_string(this->mM);
    std::string day = std::to_string(this->mD);

    if (this->mM < 10)
        month.insert(0, "0");
    if (this->mD < 10)
        day.insert(0, "0");

    if (this->mY < 1000)
        year.insert(0, "0");
    if (this->mY < 100)
        year.insert(0, "00");
    if (this->mY < 10)
        year.insert(0, "000");

    return year + "-" + month + "-" + day + " - " + weekDay();
}

Date Date::inc()
{
    mD++;

    int lenMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeap(mY))
        lenMonth[1] = 29;

    if (mD > lenMonth[mM - 1])
    {
        mD = 1;
        mM++;

        if (mM > 12)
        {
            mM = 1;
            mY++;
        }
    }

    return *this;
}

Date Date::dec()
{
    mD--;

    int lenMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeap(mY))
        lenMonth[1] = 29;

    if (mD < 1)
    {
        mM--;
        if (mM < 1)
        {
            mY--;
            mM = 12;
        }
        mD = lenMonth[mM - 1];
    }

    return *this;
}

Date Date::add(int d)
{
    for (int i = 0; i < d; i++)
    {
        inc();
    }
    return *this;
}

Date Date::sub(int d)
{
    for (int i = 0; i < d; i++)
    {
        dec();
    }
    return *this;
}

std::string Date::weekDay()
{
    std::string weekday[7] = {"Mon", "Tue", "Wen", "Thu", "Fri", "Sat", "Sun"};
    Date ref(3, 2, 2022);
    int w = 3;

    if ((ref.mY > mY) ||
        ((ref.mY == mY) && (ref.mM > mM)) ||
        (((ref.mY == mY) && (ref.mM == mM) && (ref.mD >= mD))))
    {
        while (ref.mY != mY || ref.mM != mM || ref.mD != mD)
        {
            ref.dec();
            w--;
            if (w < 0)
                w = 6;
        }
    }
    else
    {
        while (ref.mY != mY || ref.mM != mM || ref.mD != mD)
        {
            ref.inc();
            w++;
            if (w > 6)
                w = 0;
        }
    }
    return weekday[w];
}

Date Date::currentDate()
{
    time_t tim;
    tm *pt;
    time(&tim);

    pt = localtime(&tim);

    int day = pt->tm_mday;
    int month = pt->tm_mon + 1;
    int year = pt->tm_year + 1900;

    return Date(day, month, year);
}
