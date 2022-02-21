#include <QCoreApplication>
#include <QFile>
#include <qstring.h>

#include <iostream>

using namespace std;

string convertToString(char *a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++)
    {
        s = s + a[i];
    }
    return s;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // code
    char str[80];
    int numGoals = 0;
    int numMatches = 0;

    QFile f("C:\\VSC_School20-21\\GitRepoTest\\04_Tore\\toreListe.txt");

    f.open(QFile::ReadOnly);
    f.readLine(str, 80);
    while (!f.atEnd())
    {
        f.readLine(str, 80);

        char *strPrt = strtok(str, ":");
        strPrt = strtok(NULL, ":");
        strPrt = strtok(NULL, ":");
        numGoals += atoi(strPrt);
        strPrt = strtok(NULL, ":");
        numGoals += atoi(strPrt);
        numMatches++;
    }
    f.close();

    cout << "Es wurden in " << numMatches << " Matches insgesamt " << numGoals << " geschossen." << endl;

    return a.exec();
}

// char str[80];

// QFile f("c:\\temp\\roomtemp.txt");
// f.open(QFile::ReadOnly);
// while (!f.atEnd())
// {
//     f.readLine(str, 80);
//     cout << str;
// }
// f.close();

// QList<int> numList;
// numList.push_back(3);

// for (int num : numList)
// {
//     qDebug() << num;
// }
