#include <QCoreApplication>
#include <QFile>
#include <QString>

void parkGetKonv(QString link, QString fileName)
{
  QFile csvfile("D://Schul_Dokumente//4AHBG//MGIN//06_OpenData//Parkautomaten.csv");
  csvfile.open(QIODevice::ReadOnly);

  QFile textfile("D://Schul_Dokumente//4AHBG//MGIN//06_OpenData//Parkautomaten.txt");
  textfile.open(QIODevice::WriteOnly);
  textfile.write("lat\tlon\ttitle\tdescription\ticon\ticonSize\ticonOffset");
  textfile.write("\n");

  csvfile.readLine();
  csvfile.readLine();
  csvfile.readLine(); //weil Zeile für Zeile einlesen wollen

  while (!csvfile.atEnd()) //bis ungleich Ende deswegen !
  {
    QString line = csvfile.readLine();
    QStringList strList = line.split(";");      //gibt QStringList aus
    QString lat = strList[3].replace(",", "."); //lat ist breite
    QString lon = strList[2].replace(",", "."); //long ist Längengrad
    QString adress = strList[1];
    QString number = "Automat #" + strList[0];

    QString finishLine = lat + "\t" + lon + "\t" + number + "\t" + adress + "\tparking.png\t24,24\t0,-24" + "\n";

    textfile.write(finishLine.toStdString().c_str());
  }

  csvfile.close();
  textfile.close();
}

void wlanGetKonv(QString link, QString fileName)
{
  return;
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QString wlanlink = "";
  QString parklink = "";

  QString parkFilename = "parkautomaten";
  QString wlanFilename = "wlan";

  parkGetKonv(parklink, parkFilename);
  wlanGetKonv(wlanlink, wlanFilename);

  return 0;
}
