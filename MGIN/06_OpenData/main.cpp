#include <QCoreApplication>
#include <QFile>
#include <QString>

void parkGetKonv(QString link, QString fileName)
{
  QFile csvfileParking("D://Schul_Dokumente//4AHBG//MGIN//06_OpenData//Parkautomaten.csv");
  csvfileParking.open(QIODevice::ReadOnly);

  QFile textfileParking("D://Schul_Dokumente//4AHBG//MGIN//06_OpenData//Parkautomaten.txt");
  textfileParking.open(QIODevice::WriteOnly);
  textfileParking.write("lat\tlon\ttitle\tdescription\ticon\ticonSize\ticonOffset");
  textfileParking.write("\n");

  csvfileParking.readLine();
  csvfileParking.readLine();
  csvfileParking.readLine(); // Ersten 3 zeilen beinhalten keine daten

  while (!csvfileParking.atEnd()) //bis ungleich Ende deswegen !
  {
    QString line = csvfileParking.readLine();
    QStringList strList = line.split(";");      //gibt QStringList aus
    QString lat = strList[3].replace(",", "."); //lat ist breite
    QString lon = strList[2].replace(",", "."); //long ist Längengrad
    QString adress = strList[1];
    QString number = "Automat #" + strList[0];

    QString finishLine = lat + "\t" + lon + "\t" + number + "\t" + adress + "\tparking.png\t24,24\t0,-24" + "\n";

    textfileParking.write(finishLine.toStdString().c_str());
  }

  csvfileParking.close();
  textfileParking.close();
}

void wlanGetKonv(QString link, QString fileName)
{
  QFile csvfileWlan("D://Schul_Dokumente//4AHBG//MGIN//06_OpenData//wlanhotspot.csv");
  csvfileWlan.open(QIODevice::ReadOnly);

  QFile textfileWlan("D://Schul_Dokumente//4AHBG//MGIN//06_OpenData//wlanhotspot.txt");
  textfileWlan.open(QIODevice::WriteOnly);
  textfileWlan.write("lat\tlon\ttitle\tdescription\ticon\ticonSize\ticonOffset");
  textfileWlan.write("\n");

  csvfileWlan.readLine(); // Erste Zeile beinhaltet keine Daten

  int lineNummber = 1;

  while (!csvfileWlan.atEnd())
  {
    QString line = csvfileWlan.readLine();
    QStringList strList = line.split(",");
    QStringList geometrie = strList[2].split(" ");
    QString lat = geometrie[2].remove(9, geometrie[2].size() - 9); // remove the last chars so size = 9
    QString lon = geometrie[1].remove(0, 1);                       // remove first char of the string => (
    lon.remove(9, lon.size() - 9);
    QString number = "Hotspot #" + QString::number(lineNummber);
    QString description = strList[0];

    QString finishLine = lat + "\t" + lon + "\t" + number + "\t" + description + "\twlan.png\t24,24\t0,-24" + "\n";

    textfileWlan.write(finishLine.toStdString().c_str());
    lineNummber++;
  }

  csvfileWlan.close();
  textfileWlan.close();
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
