#include <QCoreApplication>
#include <QFile>
#include <iostream>

using namespace std;

struct GamesType
{
    QString team1;
    QString team2;
    int goals1;
    int goals2;
};

QList<GamesType> procData(QString str)
{
    QStringList strList = str.split("\n");
    QStringList gameList = strList[0].split(",");

    QString team1 = gameList[0];
    QString team2 = gameList[1];
    int goals1 = gameList[2].toInt();
    int goals2 = gameList[3].toInt();

    if (goals2 > goals1)
    {
        swap(goals1, goals2);
        swap(team1, team2);
    }
}

QString getDta(QString fName)
{
    QFile file(fName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QString returnString;

    while (!file.atEnd())
    {
        returnString += file.readLine();
    }

    file.close();

    return returnString;
}

int main(int argc, char *argv[])
{
    cout << getDta("results.txt").toStdString().c_str() << endl;

    return 0;
}
