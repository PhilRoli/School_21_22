# GOALS

Datei results.txt
Graz,Salzburg,1,5
Linz,Innsbruck,4,3
Wien,St. Pölten,5,2

- Funktion QString getDta(QString fName)
  zum Einlesen der Daten in einen String
- Funktion QList<GamesType> procDta(QString dta)
  zum Übertragen der Daten in eine Strukturen-Liste
  Reihenfolge der Teams: Sieger|Verlierer
- Funktion void printGames(QList<GamesType> g)
  zur Ausgabe der Spielergebnisse

# Raum-Temperatur

Datei perstemp.txt
3
John Blond: 37.3
Heinz Mailer: 36.4
Kuns Dänlich: 38.2
Fida Hunlika: 37.8

- Funktion QString getDta(QString fName)
  zum Einlesen der Daten in einen String
- Funktion QList<PersTempTypes> procDta(QString dta)
  zum Übertragen der Daten in eine Strukturen-Liste
- Funktion void printAlert(QList<PersTempTypes> g)
  zur Ausgabe in der Form (Grenze 37,6):
  Alarm:Kuns Dänlich:38,2
  Alarm:Fida Hunlika:37,8

# Sort Personen

Datei persons.txt
17 Hans Meier
12 Roger Smith
14 Jim Beam
3  Gudrun Birne

- Funktion QString getDta(QString fName)
  zum Einlesen der Daten in einen String
- Funktion QList<PersonType> procDta(QString dta)
  zum Übertragen der Daten in eine Strukturen-Liste
- Funktion QList<PersonType> sortDta(QList<PersonType> l, int elem, int order)
  zum Sortieren der Daten nach elem in der Reihenfolge order
- Funktion void printPresons(QList<PersonType> pers)
  zur Ausgabe der Personen
