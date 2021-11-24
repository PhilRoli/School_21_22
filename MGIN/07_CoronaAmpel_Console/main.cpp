#include <QCoreApplication>
#include <QFile>
#include <QStringList>
#include <iostream>

using namespace std;

struct GamesType
{
    // winner
    QString team1;
    // looser
    QString team2;
    // goals winner
    int goals1;
    // goals looser
    int goals2;
};

QList<GamesType> procDta(QString str)
{
    QStringList strList = str.split("\n");
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
