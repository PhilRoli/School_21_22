#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <iostream>

using namespace std;

void getFileData()
{
    //! Read file content to string
    QFile jsonFile("D://Schul_Dokumente//4AHBG//MGIN//07_CoronaAmpel//data.json");
    jsonFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QString wholeFile = jsonFile.readAll();
    jsonFile.close();

    //! Transform to jsonObject
    QJsonDocument jsonDoc = QJsonDocument::fromJson(wholeFile.toUtf8());
    QJsonArray jsonArrayWhole = jsonDoc.array();

    //! Get Object on array[0]
    QJsonObject jsonNewestObject = jsonArrayWhole[0].toObject();

    //! Get Date of Data
    QJsonValue dateOfData = jsonNewestObject["Stand"];
    QString dateOfDataStr = dateOfData.toString();

    //! Get Array with all communitys
    QJsonArray allCommunitys = jsonNewestObject["Warnstufen"].toArray();

    //! Find personal Community
    QString personalGKZ = "50338";
    QString objectGKZ = "0";
    QString personalName = "";
    QString personalStufe = "0";

    for (int objectCounter = 0; objectCounter < allCommunitys.size(); objectCounter++)
    {
        QJsonObject currentObject = allCommunitys[objectCounter].toObject();
        QJsonValue currentGKZ = currentObject["GKZ"];
        objectGKZ = currentGKZ.toString();
        if (objectGKZ == personalGKZ)
        {
            QJsonValue personalNameVal = currentObject["Name"];
            QJsonValue personalStufeVal = currentObject["Warnstufe"];
            personalName = personalNameVal.toString();
            personalStufe = personalStufeVal.toString();
            cout << objectCounter << endl;
            break;
        }
    }

    //! Print resaults
    cout << dateOfDataStr.toStdString().c_str() << endl;

    cout << personalName.toStdString().c_str() << endl;

    cout << personalStufe.toStdString().c_str() << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    getFileData();
}
