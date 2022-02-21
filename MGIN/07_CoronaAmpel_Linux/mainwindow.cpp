#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lightwidget.h"
#include "QUrl"
#include "filedownloader.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mRedLight = new LightWidget(Qt::red);
    mYellowLight = new LightWidget(Qt::yellow);
    mGreenLight = new LightWidget(Qt::green);
    ui->centralwidget->layout()->addWidget(mRedLight);
    ui->centralwidget->layout()->addWidget(mYellowLight);
    ui->centralwidget->layout()->addWidget(mGreenLight);
    mRedLight->turnOn();
    mYellowLight->turnOn();
    mGreenLight->turnOn();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QUrl url("https://corona-ampel.gv.at/sites/corona-ampel.gv.at/files/assets/Warnstufen_Corona_Ampel_Gemeinden_aktuell.json");
    delete mDownloader;
    mDownloader = new FileDownloader(url, this);
    connect(mDownloader, SIGNAL(downloaded()),
            this, SLOT(dataLoaded()));
}

void MainWindow::dataLoaded()
{
    qDebug() << "dataLoaded: " << mDownloader->downloadedData().size();

    //! Read Data and transform to jsonObject
    QJsonDocument jsonDoc = QJsonDocument::fromJson(mDownloader->downloadedData());
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
            break;
        }
    }

    if (personalStufe == "0" || personalStufe == "1")
    {
        mRedLight->turnOff();
        mYellowLight->turnOff();
        mGreenLight->turnOn();
    }
    else if (personalStufe == "2" || personalStufe == "3")
    {
        mRedLight->turnOff();
        mYellowLight->turnOn();
        mGreenLight->turnOff();
    }
    else if (personalStufe == "4" || personalStufe == "5")
    {
        mRedLight->turnOn();
        mYellowLight->turnOff();
        mGreenLight->turnOff();
    }
}
