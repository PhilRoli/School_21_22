#include <QCoreApplication>
#include <QDebug>

double dadd(double num1, double num2)
{
    return num1 + num2;
}

int iadd(int inum1, int inum2)
{
    if (inum2 == 0) {
        return inum1;
    }
    return 1 + iadd(inum1, inum2-1);
}

int ladd(int lnum1, int lnum2)
{
    int lsum = lnum1;
    while (lnum2 > 0)
    {
        lsum++;
        lnum2--;
    }
    return lsum;
}

int lpow(int base, int expo)
{
    if (expo == 0)
    {
        return 1;
    }
    return base * lpow(base, expo-1);
}

// add(5, 3) = 1+add(5, 2) = 1+(1+add(5,1)) = 1+(1+(1+add(5,0)))

int main(int argc, char *argv[])
{
    int sum = ladd(5,3);
    qDebug() << sum;

    return 0;
}
