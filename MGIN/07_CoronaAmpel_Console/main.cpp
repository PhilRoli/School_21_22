#include <QCoreApplication>
#include <QFile>
#include <QDebug>
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
    QList<GamesType> gamesList;
    GamesType game;

    QStringList strList = str.split("\n");

    for (int iList = 0; iList < strList.length(); ++iList)
    {
        if (strList[iList] != "")
        {
            QStringList gameList = strList[iList].split(",");

            qDebug() << strList[iList].mid(strList[iList].indexOf(',') + 1, 4);

            game.team1 = gameList[0];
            game.team2 = gameList[1];
            game.goals1 = gameList[2].toInt();
            game.goals2 = gameList[3].toInt();

            if (game.goals2 > game.goals1)
            {
                game.team1 = game.team2;
                game.team2 = gameList[0];
                game.goals1 = game.goals2;
                game.goals2 = gameList[2].toInt();
            }
            gamesList.append(game);
        }
    }
    return gamesList;
}

void printGames(QList<GamesType> gamesList)
{
    for (int iList = 0; iList < gamesList.length(); ++iList)
    {
        if (gamesList[iList].goals1 != gamesList[iList].goals2)
        {
            qDebug() << "Team " << gamesList[iList].team1 << " gewinnt gegen " << gamesList[iList].team2 << " mit " << gamesList[iList].goals1 << " zu " << gamesList[iList].goals2;
        }
        else
        {
            qDebug() << "Team " << gamesList[iList].team1 << " spielt unentschieden gegen " << gamesList[iList].team2 << " mit " << gamesList[iList].goals1 << " zu " << gamesList[iList].goals2;
        }
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
    cout << getDta("results.txt").toStdString().c_str() << "\n"
         << endl;

    printGames(procData(getDta("results.txt")));

    cout << endl;

    return 0;
}
