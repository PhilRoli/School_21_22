# Erste Schulwoche MGIN4: C++

- Was ist C bzw. C++? Warum C/C++? Was sind die Unterschiede zwischen C++ und Java?

- printf / cout

- Header-Konzept
- Funktionen
- Strings char[]/string

- Dateizugriff

  ```c++
  ifstream infile;
  char str[80];
  infile.open("c:\\temp\\myfile.txt", ios::in);
  
  while (!infile.eof()) {
      infile.getline(str, 80);
      cout << str << endl;
  }
  
  infile.close();
  ```

## Programm TPERSONSORT.c (cpp 604)

Bringen Sie das folgende Programm zum Laufen.

```c
typedef struct person {
 int persnr;
 char name[40];
} TPERSON;
#define ANZ  3

void sort_persnr(TPERSON* p, int anzahl);

int main(int argc, char* argv[]){
 TPERSON wir[ANZ];
 int i;

 printf("\nBitte %d Datensaetze eingeben:\n", ANZ);
 for (i=0; i < ANZ; i++){
  printf("\n%d:persnr> ", i);
  scanf("%d", &(wir[i].persnr));
  printf("%d:Name> ", i);
  scanf("%s", wir[i].name);
 }

 // Das Array mit dem Namen wir soll sortiert werden
 sort_persnr(wir, ANZ);


 printf("\nAusgabe: Sortiert wurde nach persnr:\n");
 for (i=0; i < ANZ; i++){
  printf("\n%6d | %-20s", wir[i].persnr , wir[i].name);
 }
 return 0;
}

void sort_persnr(TPERSON* p, int anzahl){
 int i;
 int fertig;

 fertig=0;
 while (0==fertig){
  fertig= 1;

  for (i=0; i < anzahl-1; i++){
   if ( p[i].persnr > (&p[i+1].persnr)->persnr){
    TPERSON help;
    help= p[i];
    p[i] = p[i+1];
    p[i+1] = help;
    fertig= 0;
   }//if
  }//for
 }//while
}
```

Sortiert wird ein Array aus *TPERSON*-Elementen.

## Tore

- Gegeben ist die Datei *tore.txt* (s. u.)
- Lesen Sie die Datei ein und
- Geben Sie die Anzahl der insgesamt erzielten Tore aus.

tore.txt:

```
4
groedig:salzburg:0:0
frankfurt:stuttgart:4:5
gladbach:bayer:0:0
real:barca:3:1
```

Ausgabe:

```
In dieser Runde wurden 13 Tore geschossen.
```

-----------------------

- Qt-File

  ```c++
  char str[80];
  
  QFile f("c:\\temp\\roomtemp.txt");
  f.open(QFile::ReadOnly);
  while (!f.atEnd()) {
      f.readLine(str,80);
      cout << str;
  }
  f.close();
  ```

- QList

  ```c++
  QList<int> numList;
  numList.push_back(3);
  
  for(int num:numList) {
      qDebug() << num;
  }
  ```

## Programm: TRAFFIC.c

------------------------------------------------------------

1. Definieren Sie geeignete Datenstruktur-Typen (in C) zur Verarbeitung der Daten.

2. Lesen Sie die Daten ein  in ein mit malloc() zu alloziierendes Array.

input.txt:

```c
3
Maserati,1000 kg,2 Persons
VM,800 kg,4 Persons
Bus,2500 kg,8 Persons
```

Ausgabe:

```c
With 3 vehicles we transport 14 persons using 4300 kg.
So for 1 person we have to move about 307,14 kg 'vehicle weight'.
```

## Raum-Temperatur

Gegeben: roomtemp.txt

```
3
Schlafzimmer:20
Kueche:25
Keller:15
```

1. Öffnen Sie die Datei roomtemp.txt
2. Lesen Sie die Temperaturen in eine Liste ein
3. Schließen Sie die Datei roomtemp.txt
4. Berechnen Sie und geben die Werte in folgender Form aus (Schwelle 19°C):

```
Fester öffnen:Schlafzimmer:20
Fester öffnen:Kueche:25
Durschnittstemperatur: 20
```

Das Einlesen aus der Datei und die Berechnung soll in verschiedenen Funktionen in der Datei funclib.h/funclib.cpp

## Programm BMI.c

Erstellen Sie ein Programm (BMI.c). Berechnet werden soll der BMI (BodyMassIndex) von Personen deren Daten in einer Datei abgelegt sind. Die Errechneten Werte werden wiederum in einer Datei abgelegt.

bmi.txt (NName, VName, Alter, Gr, Gewicht:

```
4
Mueller Fritz 32 192 82
Struber Karin 29 178 85
Krumber Sigi 57 177 94
Hoellwart Klaus 53 182 90
```

Ausgabe:

```
Fritz Mueller ist Normalgewichtig BMI = 22.24 kg/m2
Struber Karin ist Uebergewichtig BMI = 26.83 kg/m2
Krumber Sigi ist BMI = 30.00 kg/m2
Hoellwart Klaus ist Uebergewichtig BMI = 27.17 kg/m2
```

bmi_out.txt:

```
4
Mueller Fritz 32 192 82 22.24
Struber Karin 29 178 85 26.83
Krumber Sigi 57 177 94 30.00
Hoellwart Klaus 53 182 90 27.17
```

## OPEN DATA und SALZBURG (wlanhotspots) (037)

- Laden Sie die Datei *wlanhotspot.csv* aus Ihrem Programm von <https://www.data.gv.at/katalog/dataset/c3d494f6-ad43-4225-b3ec-3b2c86b11a01/resource/b78ab487-f7dc-485d-899b-2140517df042/download/cusers15960desktopparkscheinautomatenaz20161212.csv>
  Hinweis: Verwenden Sie bitsadmin (windows-tool), wget, curl bzw. ....
  z.B.:

  ```
  system("bitsadmin /transfer wcb /priority high /dynamic \"https://www.data.gv.at/katalog/dataset/c3d494f6-ad43-4225-b3ec-3b2c86b11a01/resource/b78ab487-f7dc-485d-899b-2140517df042/download/cusers15960desktopparkscheinautomatenaz20161212.csv\" \"c:\\temp\\od\\parkscheine.csv\"");
  ```

  (wget gibts unter <http://downloads.sourceforge.net/gnuwin32/wget-1.11.4-1-setup.exe>)

- Lesen Sie die Datei *parkscheine.csv* ein und erstellen Sie die Datei *textfile.txt* (siehe Muster weiter unten).

- Laden Sie mit Ihrem Webbrowser die Datei *index.html* und testen Sie die Funktionalität. Die Datei *texfile.txt* muss sich dabei im gleichen Ordner befinden.
  Tipp: Achten Sie auf den richtigen Aufbau (Tabulator, Zeilenumbruch am Ende ...) der Datei *texfile.txt*.

**HINWEIS: texfile.txt, index.html, parkscheine.csv**

- Studieren Sie: <http://wiki.openstreetmap.org/wiki/Openlayers_POI_layer_example>
- Laden Sie die Dateien in einen eigenen Unterordner:
  index.html
  textfile.txt
  Ol_icon_blue_example.png
  Ol_icon_red_example.png

parkscheine.csv (falls kein Internet)

```csv
Nr.;Parkscheinautomaten - Standorte;GPS Koordinaten;;GK Koordinaten;;Bemerkungen bzw. Korrekturen (Stand 12/16)
;;Längengrad;Breitengrad;Rechtswert;Hochwert;
;;;;;;
001;Schwarzstraße 49 - Musikum;13,038234;47,808318;-22046,650;296679,900;
002;Ernest-Thunstr. - Elisabethkai (Kreuzung);13,037725;47,808025;-22084,900;296647,400;Ernest-Thun-Str. - Elisabethkai (Kreuzung)
003;Markus-Sittikus-Straße - Elisabethkai (Kreuzung);13,037962;47,807115;-22067,500;296546,200;
004;Elisabethkai b. Kirche - Schulschwestern;13,038253;47,806269;-22046,100;296452,100;
005;Elisabethkai - Gehmacherstr. (Kreuzung);13,038684;47,805324;-22014,200;296346,900;
006;Schwarzstraße 29;13,039641;47,804881;-21942,700;296297,300;
007;Schwarzstraße 35 neben Garteneinfahrt links;13,039166;47,805881;-21977,900;296408,700;
008;Schwarzstraße 27 gegenüber;13,039978;47,804802;-21917,500;296288,400;
009;Auerspergstr. 9 neben Einfahrt rechts;13,039940;47,807003;-21919,400;296533,200;
011;Markus-Sittikus-Straße 4;13,039503;47,807427;-21952,000;296580,500;
012;Max-Ott-Platz 6 links v. Eingang;13,041037;47,808056;-21836,800;296649,900;
013;Ernest-Thunstr. 12 neben Trafostation;13,040548;47,808338;-21873,300;296681,400;Ernest-Thun-Str. 12 neben Trafostation
014;Ernest-Thunstr. 9 links v. Einfahrt;13,039394;47,808274;-21959,800;296674,700;Ernest-Thun-Str. 9 links v. Einfahrt
015;Faberstr. Humboldtstr.;13,042663;47,809037;-21714,600;296758,600;
016;Markus-Sittikus-Straße 19;13,042489;47,808427;-21727,900;296690,800;
017;Faberstr. 18 Ecke Auersbergstr.;13,043607;47,807914;-21644,400;296633,400;
018;Auersbergstr. 12;13,042725;47,807688;-21710,500;296608,600;
019;Weiserstraße 4 - Einfahrt Handelskammer;13,044828;47,808506;-21552,700;296698,900;
020;Lasserstraße - Weiserstraße;13,045355;47,809420;-21512,800;296800,400;
021;Lasserstraße 35;13,046695;47,808799;-21412,700;296730,900;
023;Auerspergstraße 35 neben Einfahrt links;13,046275;47,807986;-21444,500;296640,700;
024;Haydnstr. gegenüber Nr. 22;13,045532;47,808539;-21499,900;296702,400;
025;Auerspergstr. 20 bei Trafostation;13,044458;47,807972;-21580,600;296639,600;
026;Wartelsteinstr. 16 bei Einfahrt rechts;13,029248;47,803583;-22721,800;296156,000;
027;Rupertgasse 23;13,054709;47,808013;-20812,800;296641,400;lt. GIS Rupertgasse 25
028;Franz-Josef-Str. 14 neben  Eingang rechts;13,044726;47,807137;-21560,900;296546,700;
029;Auerspergstr. 48 - 50;13,050199;47,806069;-21151,400;296426,400;
031;Franz-Josef-Str. - P. Lodronstr. ( Kreuzung );13,048805;47,805965;-21255,800;296415,300;
032;Paris-Lodrostr. 26;13,049376;47,806195;-21213,000;296440,700;Paris-Lodron-Str. 26
033;Franz-Josef-Str. 23;13,047406;47,806975;-21360,200;296527,900;
034;Franz-Josef-Str. 13;13,044768;47,807418;-21557,600;296577,900;
035;Schrannengasse 2 ;13,044234;47,805359;-21598,500;296349,200;
036;Schrannengasse 6 ;13,045288;47,805724;-21519,400;296389,500;
037;Julius-Haagn-Straße zwischen 30 und 32;13,041382;47,816906;-21807,200;297633,900;
038;Julius-Haagn-Straße 12;13,038919;47,817079;-21991,600;297653,800;
039;Schrannengasse 7a Ecke Haydnstraße;13,045932;47,806055;-21471,000;296426,100;
040;Paracelsusstr. 4 ( Bundesforste );13,047079;47,807662;-21384,400;296604,400;
041;Stelzhammerstraße 3 Ecke Auerspergstraße;13,048562;47,807090;-21273,600;296540,400;
042;Lasserstraße 14;13,049240;47,807869;-21222,500;296626,800;
043;Lasserstraße 6;13,050226;47,807474;-21148,800;296582,600;
044;Bayerhammerstr. 11;13,051257;47,806883;-21071,800;296516,700;
045;Gabelsbergstr. 32;13,050310;47,808220;-21142,200;296665,600;
046;Arnogasse 5;13,053019;47,806843;-20939,800;296511,700;lt. GIS Arnogasse 7
047;Schallmooser Hauptstraße 19;13,052764;47,805907;-20959,300;296407,700;
048;Virgilgasse neben Eingang Trafostation;13,052172;47,806719;-21003,300;296498,200;
049;Bayerhammerstr. 2;13,052147;47,805714;-21005,600;296386,400;
050;Auerspergstr. 71;13,050841;47,805528;-21103,500;296366,100;
051;Glockengasse neben Trafostation;13,051117;47,804906;-21083,100;296296,900;
052;Vierthalerstraße 16;13,049830;47,805551;-21179,200;296368,900;lt. GIS Vierthalerstraße 14
053;Auerspergstr. 61 Ecke Rupertgasse;13,049921;47,806747;-21171,900;296501,900;
054;Bayerhamerstr. 15;13,051045;47,807595;-21087,400;296595,900;
055;Hildmannplatz 5 ;13,037972;47,797472;-22070,900;295474,000;
056;Reichenhallerstraße 3;13,036828;47,798215;-22156,300;295557,000;
057;Neutorstraße 16/Untersbergsr. 9;13,035428;47,797646;-22261,400;295494,100;
058;Untersbergstraße 2;13,035332;47,798612;-22268,200;295601,500;
059;Neutorstraße Ecke Fürstenbrunnstr. 8;13,034027;47,797723;-22366,400;295503,100;
060;Fürstenbrunnstr. 2 Ecke Reichenhallerstr. 15;13,034048;47,798678;-22364,400;295609,200;
061;Reichenhallerstraße 19;13,032959;47,799019;-22445,800;295647,500;
062;Reichenhallerstraße 14 ;13,032343;47,800135;-22491,500;295771,700;lt. GIS Reichenhallerstraße 16
063;Rainbergstr.14;13,033847;47,796969;-22380,150;295419,300;
064;Johann-Wolf-Str. Ecke Untersbergstr. 12;13,035212;47,796781;-22278,000;295398,000;
065;Steinbruchstraße 3;13,036646;47,796053;-22170,900;295316,600;
066;Fürstenalle 3;13,048558;47,792251;-21280,000;294890,500;lt. GIS zwischen Fürstenalle 3 und5
067;Nonntaler Hauptstr. 38;13,048939;47,792438;-21251,400;294911,200;
068;Nonntaler Hauptstr. 31a;13,049650;47,793370;-21197,700;295014,600;
069;Zugallistraße 7 gegenüber;13,051301;47,794209;-21073,700;295107,500;
070;Petersbrunnstr. 10;13,052011;47,794743;-21020,300;295166,600;zwischen Petersbrunnstr. 10 und Erhardplatz
071;Nonntaler Hauptstr. 9;13,052057;47,795468;-20955,600;295280,600;
072;Nonntaler Hauptstr. 11;13,052869;47,795770;-21016,500;295247,200;
073;Nonntaler Hauptstr. 16 Gehsteig;13,051207;47,794963;-21080,400;295191,300;
075;Schwarzstraße - Landestheater;13,042405;47,803038;-21736,500;296091,600;lt. GIS Schwarzstraße 24
076;Imbergstr. 10;13,050296;47,800282;-21146,500;295783,000;
077;Imbergstr. 14;13,051400;47,799995;-21063,900;295750,700;
078;Äusserer Stein - Neuhauser;13,053322;47,800236;-20919,800;295777,000;
079;Dr.-Varnschein-Gasse;13,052559;47,799626;-20977,200;295709,400;
080;Dr.-Franz-Rehrplatz 2 ;13,054194;47,799448;-20854,800;295689,200;
081;Rainerstraße 15 Ecke Hans-Prodinger-Straße;13,041329;47,809400;-21814,400;296799,300;
083;Staatsbrücke gegenüber Rathauswache;13,044941;47,800471;-21547,600;295805,500;
084;Franz-Josef-Kai 9;13,040575;47,801475;-21874,200;295918,400;
085;Ursulinenplatz 8;13,038045;47,802897;-22063,100;296077,200;
086;Hubert-Sattler-Gasse 5;13,043572;47,806427;-21647,600;296468,100;
087;Auerspergstr. 13;13,040793;47,807240;-21855,400;296559,300;
089;Hubert-Sattler-Gasse 11;13,044763;47,806770;-21558,300;296505,900;
090;Hubert-Sattler-Gasse  Ecke Haydnstr.;13,045450;47,806815;-21506,800;296510,700;
091;Faberstr. 11;13,043955;47,807006;-21618,700;296532,400;
092;Esshaverstr. 5;13,027284;47,810920;-22865,700;296972,400;
093;Sparkassenstraße Ecke Esshaverstraße;13,028272;47,810828;-22791,700;296961,900;
094;Leonhard v. Keutschachstr. 37;13,027288;47,810211;-22865,700;296893,600;
095;Schwarzstraße Ecke Markus-Sittikus-Straße;13,038721;47,807147;-22010,700;296549,500;
096;Franz-Josef-Str. 17;13,045770;47,807385;-21482,600;296574,000;
097;Haydnstr. 9;13,045418;47,807716;-21508,800;296610,900;Adresse gibt es im GIS nicht
098;Imbergstraße - Robert-Jungk-Platz;13,048459;47,800515;-21284,000;295809,400;Robert-Junk-Platz wurde verlegt!
101;Zillnerstraße 18 gegenüber;13,030821;47,804045;-22603,800;296206,900;
102;Franz-Neumeister-Str.4 vor der Einfahrt rechts;13,040962;47,810268;-21841,500;296895,900;
104;Lessingstr. 3, vor der Einfahrt links;13,040990;47,809805;-21839,600;296844,400;
106;Plainstr. 2 Ecke Hans Prodingerstr.;13,040548;47,809244;-21872,900;296782,200;
107;Schwarzstraße 50 Ecke Viktor-Kaplan-Straße;13,038854;47,809270;-21999,800;296785,500;
109;Gebirgsjägerplatz / Alois Schmiedbauerstraße;13,038787;47,810183;-22004,400;296887,100;
110;Elisabethkai / Alois Schmiedbauerstraße;13,037510;47,810181;-22100,100;296887,200;Elisabethkai / Alois-Schmiedbauer-Straße
111;Hans-Sachs-Gasse 25;13,029852;47,812153;-22672,800;297108,700;
112;Hans-Sachs-Gasse gegenüber 15;13,031939;47,811920;-22516,600;297082,200;
114;Paris-Lodrostr. 8a vormals Gebirgsjägerplatz;13,046874;47,805362;-21400,700;296348,700;lt. GIS Paris-Lodron-Str. 10
115;Plainstr. 10 links beim Eingang;13,040504;47,810026;-21875,900;296869,100;
116;Hans-Prodingerstr.7;13,039262;47,808956;-21969,400;296750,500;Hans-Prodinger-Str.7
117;Sylvester Oberbergerstraße / Bergheimerstraße;13,038332;47,815343;-22036,300;297460,900;Sylvester-Oberberger-Straße / Bergheimerstraße
120;Müllner Hauptstr. 3;13,036962;47,804261;-22143,700;296229,200;
121;Müllner Hauptstr. 11;13,035868;47,805675;-22225,000;296386,700;
122;Augustinergasse beim Kircheneingang;13,034663;47,805377;-22315,400;296353,900;
123;Ferdinand-Porschestr. 9;13,043411;47,812505;-21657,100;297143,900;Adresse gibt es im GIS nicht
124;Gaswerkgasse 3 beim Hauseck;13,033088;47,808494;-22432,000;296700,900;
125;Strubergasse / Wallnergasse;13,030962;47,808921;-22591,060;296749,010;
126;Strubergasse 4b;13,034800;47,809222;-22303,500;296781,400;lt. GIS Strubergasse 4A
127;Nikolaus Lenaustr. 1 vorm Haus rechts;13,034123;47,810106;-22353,800;296879,900;Nikolaus-Lenau-Str. 1 vorm Haus rechts
128;Rainerstraße 25;13,043231;47,811036;-21671,200;296980,700;
129;Johann-Haspinger-Str. 5;13,034189;47,810521;-22348,700;296926,000;lt. GIS Joachim-Haspinger-Straße 1
130;Emil Koflergasse 7;13,053973;47,807033;-20868,300;296532,600;Emil-Kofler-Gasse 7
131;Schießstattstraße 6 gegenüber;13,034335;47,811825;-22337,200;297070,900;lt. GIS Schießstattstraße 9
132;Weiserstraße 22 vor Hauseinfahrt rechts;13,046583;47,810786;-21420,250;296951,950;
133;Hübnergasse Nähe 5;13,032387;47,798255;-22489,000;295562,700;
134;Hübnergasse Nähe 6;13,048036;47,809907;;;kein PAUT (1.12.16)
138;Makartplatz 1 (in der Insel);;;;;kein PAUT vorhanden
140;Paracelsusstr. 21 vor Hauseingang rechts;13,048036;47,809907;-21311,800;296853,800;
141;Ignaz-Harrer-Str. 44c (Hotel Wienerwald);13,028090;47,811608;-22805,000;297048,700;
142;Paracelsusstr. 31;13,047685;47,811100;-21337,600;296986,500;
143;Merianstr. / Weiserhofstr.;13,047952;47,811640;-21317,400;297046,500;
144;Leonhard v. Keutschachstr. 25;13,028803;47,810215;-22752,200;296893,600;Leonhard-v.-Keutschach-Str. 25
145;Haunspergstr. 44;13,039147;47,815444;-21975,200;297471,900;lt. GIS Kreuzung Haunspergstraße - Sylvester-Oberberger-Str. 7
148;Alois Stockingerstr. gegenüber 9;13,031598;47,812408;-22541,900;297136,600;Alois-Stockinger-Str. gegenüber 9
149;Schuhmacherstraße Ecke Hüttenbergstraße;13,026568;47,812464;-22918,600;297144,300;
152;Roseggerstraße 8;13,029757;47,811271;-22680,300;297010,700;lt. GIS Roseggerstraße 12
153;Bayerhamerstr. 35 vor Einfahrt rechts;13,050528;47,810218;-21125,000;296887,700;lt. GIS Bayerhamerstraße 33
154;Bayerhamerstr. 31 Einfahrt inks;13,050609;47,809621;-21119,200;296821,300;
155;Bayerhamerstr. 25 gegenüber;13,050904;47,809189;-21097,300;296773,100;
157;Elisabethstr. Ecke Mertenstr.;13,041736;47,811772;-21782,900;297062,900;(demontiert Baustelle)
158;Ferdinand-Porschestr. 2 ;13,042381;47,812253;-21734,400;297116,200;Ferdinand-Porsche-Str. 2 
159;Elisabethstr. Ecke Stauffenstr. 19 od. 18;13,041855;47,813049;-21773,400;297204,900;lt. GIS Nr.19
160;Elisabethstr. bei Ausfahrt Schule rechts;13,042227;47,814875;-21744,800;297407,800;lt. GIS Nr.18
161;Karl-Wurmb-Str. bei Ausfahrt ÖBB rechts;13,042904;47,815114;-21694,000;297434,200;
162;Elisabethstr. 22 Automat gegenüber Einfahrt;13,042942;47,815872;-21690,800;297518,400;
163;Elisabethstr. zwischen 47 und 49;13,043665;47,816624;-21636,400;297601,800;
164;August Gruberstr vor Batimat;13,043813;47,817276;-21625,000;297674,300;August-Gruber-Str vor Batimat
165;Erzherzog - Eugenstr. 22;13,040082;47,818557;-21903,900;297817,800;Erzherzog-Eugen-Straße 22
167;Erzherzog - Eugenstr. Ecke Bergheimerstr.;13,037487;47,818410;-22098,300;297802,200;Erzherzog-Eugen-Straße Ecke Bergheimer Straße
168;Bergheimerstr. 50;13,037625;47,817754;-22088,200;297729,200;Bergheimer Straße
169;Haunspergstr. Ecke Bayrisch - Platzl. - Str.;13,038853;47,817788;-21996,200;297732,600;
170;Bayrisch - Platzl - Str. 21;13,039887;47,818030;-21918,700;297759,200;
171;Plainstraße 73;13,040543;47,817082;-21870,000;297653,700;
172;Julius-Haagn-Str. 16;13,039793;47,816962;-21926,200;297640,500;
173;Wolf-Dietrich-Straße 31 gegenüber;13,047034;47,806439;-21388,300;296468,500;
174;Haunspergstr. 43 Ecke V. M. Süßstr.;13,038934;47,816134;-21990,900;297548,700;
175;Bergheimerstr. 55;13,037937;47,816391;-22065,400;297577,600;
176;Lasserstraße - Paracelsusstraße;13,047672;47,808385;-21339,700;296684,600;
177;Plainstraße zwischen 50 und 52;13,040603;47,816305;-21865,800;297567,200;
178;Plainstraße 57a;13,040329;47,815708;-21886,600;297501,000;Adresse? lt. GIS gegenüber 42
180;Julius-Haagn-Str. 24 gegenüber Lichtmast;13,041699;47,816163;-21783,800;297551,100;
181;Wolf-Dietrich-Straße 21 - Paris-Lodron-Straße 11;13,047404;47,805661;-21360,900;296381,800;
183;Rudolf-Spängler-Straße 16 gegenüber;13,040135;47,814756;-21901,500;297395,200;
184;Bergheimerstr. 31;13,038482;47,814474;-22025,400;297364,300;lt. GIS gegenüber 31
185;Bergheimerstr. 17 Ecke Stauffenstr. 3;13,038378;47,813133;-22033,800;297215,200;
187;Elmokino Parkplatz ;13,037923;47,811197;-22068,700;297000,100;
188;Bergheimerstr. 3;13,038015;47,811727;-22061,600;297059,000;
189;Mertenstr. 12;13,039544;47,811829;-21947,000;297069,900;
190;Ignaz-Heffter-Str. 6 neben Einfahrt;13,039981;47,811338;-21914,500;297015,200;
191;Plainstraße zwischen 18 und 18a;13,040489;47,811268;-21876,500;297007,200;
192;Mertenstr. 18 neben KAK, gegenüber;13,040577;47,811898;-21869,600;297077,300;
193;Purtschellergasse 15 / Plainstraße;13,040432;47,812500;-21880,200;297144,200;
195;Stauffenstraße 9 neben KAK;13,039757;47,813106;-21930,500;297211,800;
196;Stauffenstraße 15 neben KAK;13,041317;47,813058;-21813,700;297206,000;
197;Plainstr. 41 neben Trafostation, gegenüber;13,040662;47,813473;-21862,600;297252,400;
198;Schallmooser Hauptstraße 30b;13,054519;47,806308;-20827,700;296451,800;
199;Schallmooser Hauptstraße 35;13,054606;47,806568;-20821,100;296480,700;
201;Hans-Sachs-Gasse 7;13,033521;47,811741;-22398,200;297061,900;
202;Emil Koflergasse 14 gegenüber;13,054692;47,807316;-20814,300;296563,900;demontiert Baustelle
203;Franz-Josef-Str. 8 neben Eingang links;13,043387;47,807000;-21661,200;296531,900;
205;Rupertgasse 16 links von der Einfahrt;13,053198;47,807415;-20926,200;296575,300;
206;Kaiserschützenstr. 8;13,043296;47,813948;-21665,100;297304,400;
207;Wartelsteinstraße 3 gegenüber;13,030131;47,803865;-22655,500;296187,100;
208;Eduard Baumgartnerstr. 12 neben KAK;13,030879;47,799071;-22601,600;295653,900;Eduard-Baumgartner-Str. 12 neben KAK
209;Augustinergasse zwischen 11 und 13;13,032035;47,802114;-22513,700;295991,900;
210;Augustinergasse 19;13,032105;47,800994;-22508,900;295867,300;
211;Zillernerstraße 4;13,030914;47,801722;-22597,800;295948,600;
213;Willibald-Hauthaler-Straße 3 gegenüber;13,031099;47,803392;-22583,200;296134,300;
214;Anton Behackerstr. vor KAK;13,029866;47,803122;-22675,700;296104,600;Anton-Behacker-Str. 7 vor KAK
216;Adolf Bekkstr. 7;13,029559;47,802096;-22699,200;295990,600;Adolf-Beck-Straße 7
217;Eduard Baumgartnerstr. 22 ;13,030742;47,800216;-22611,400;295781,200;Eduard-Baumgartner-Str. 22
218;Augustinergasse 9a rechts n. Schutzweg;13,031901;47,802996;-22523,300;296090,000;
224;Viktor-Kehldorfer-Straße 3 gegenüber;13,053623;47,792569;-20900,400;294924,500;
225;Mühlbacherhofweg 6/Viktor-Kehldorfer-Straße;13,054128;47,793168;-20862,300;294990,900;
226;Ulrike-Gschwandtner-Straße 6 gegenüber;13,055915;47,793895;-20728,100;295071,300;
227;Akademiestr. 19 - 21;13,057279;47,792062;-20626,700;294867,100;
228;Akademiestr. 9 ;13,058554;47,792834;-20530,800;294952,600;Akademiestr. 9 gegenüber
233;Hans-Sachs-Gasse 29, gegenüber;13,028842;47,812013;-22748,500;297093,500;
244;Hellbrunnerstr. 16b;13,059780;47,792706;-20439,000;294938,000;
245;Hellbrunnerstr. 26, gegenüber;13,059651;47,791871;-20449,000;294845,200;
246;Hellbrunnerstr. beim Altersheim;13,060249;47,790814;-20404,600;294727,500;
250;Kaiserschützenstr. 12;13,043428;47,813612;-21655,400;297267,000;
251;Alois Stockingerstr. 3;13,031042;47,811542;-22583,900;297040,400;
252;Neutorstraße bei der Riedenburgapotheke;13,031469;47,797736;-22558,000;295505,300;Neutorstraße 32F bei der Riedenburgapotheke
253;Erzabt Klotzstr. 10;13,052976;47,793646;-20948,400;295044,400;Erzabt-Klotz-Str. 10
```

textfile.txt (erstellen aus csv-Datei):

```
lat lon title description icon iconSize iconOffset
48.0 9.1 Title One Description one Ol_icon_blue_example.png 24,24 0,-24
48.1 9.2 Title Two Description two Ol_icon_red_example.png 16,16 -8,-8

```

index.html (Vorlage zum Testen):

```html
<html><body>
  <div id="mapdiv"></div>
  <script src="http://www.openlayers.org/api/OpenLayers.js"></script>
  <script>
    map = new OpenLayers.Map("mapdiv");
    map.addLayer(new OpenLayers.Layer.OSM());

    var pois = new OpenLayers.Layer.Text( "W-LAN Hotspots",
                    { location:"./wlanhotspot.txt",
                      projection: map.displayProjection
                    });
    map.addLayer(pois);
    var pois2 = new OpenLayers.Layer.Text( "Parkscheinautomaten",
                    { location:"./textfile.txt",
                      projection: map.displayProjection
                    });
    map.addLayer(pois2);
 // create layer switcher widget in top right corner of map.
    var layer_switcher= new OpenLayers.Control.LayerSwitcher({});
    map.addControl(layer_switcher);
    //Set start centrepoint and zoom
    var lonLat = new OpenLayers.LonLat( 13.03, 47.8 )
          .transform(
            new OpenLayers.Projection("EPSG:4326"), // transform from WGS 1984
            map.getProjectionObject() // to Spherical Mercator Projection
          );
    var zoom=11;
    map.setCenter (lonLat, zoom);

  </script>
</body></html>
```

## Erweiterung

- Verändern Sie die Datei *index.html* dahingehend, dass beim Öffnen der Datei die Anzeige auf den Mittelwert der erstellten Punkte zentriert wird. Dazu müssen die Koordinaten in der folgenden Zeile angepasst werden:

  ```
  var lonLat = new OpenLayers.LonLat( 9.5788, 48.9773 )
  ```

- Erstellen Sie einen zweiten Layer mit den WLan-Hotspots der Stadt-Salzburg. Die Vorgangsweise ist wieder:

  - Die csv-Daten müssen von der Seite data.gv.at in eine lokale csv-Datei gespeichert werden
  - Schreiben der Koordinaten, Title und Description in eine Datei *wlan.txt* (Formatierung wie oben). Suchen und Verlinken Sie ein passendes P-Logo (24x24).
  - Einfügen eines neuen Layers in der Datei *index.html*.
  - Starten der Datei *index.html* im Browser.

## OpenDataTrack.c (037c)

Es ist eine GPS-Aufzeichnung in Form einer csv-Datei *fks.csv* vorhanden (siehe unten). Der resultierende *Track* ist in einer OpenData-Karte darzustellen. Es können lediglich *GPX*-Formate dargestellt werden, daher ist das csv-Format zu konvertieren. Als Beispiel für eine GPX-Datei ist die Datei *beispiel.gpx* gegeben.

Mit der *index.html* Datei wird das Ergebnis dargestellt.

fks.csv:

```
time;latitude;longitude;elevation
2017-01-01T08:12:51Z;46,586418;13,923359;555,000000
2017-01-01T08:13:24Z;46,586781;13,925720;563,000000
2017-01-01T08:14:57Z;46,587120;13,926850;569,000000
2017-01-01T08:15:30Z;46,587372;13,927240;572,000000
2017-01-01T08:16:03Z;46,587650;13,928000;578,000000
2017-01-01T08:17:36Z;46,588051;13,929750;579,000000
2017-01-01T08:18:09Z;46,588551;13,931470;578,000000
2017-01-01T08:19:42Z;46,588261;13,931890;576,000000
2017-01-01T08:20:15Z;46,588032;13,932050;575,000000
2017-01-01T08:21:48Z;46,587139;13,932430;565,000000
2017-01-01T08:22:21Z;46,586800;13,932640;561,000000
2017-01-01T08:23:54Z;46,586418;13,933310;563,000000
2017-01-01T08:24:27Z;46,585979;13,933670;564,000000
2017-01-01T08:25:00Z;46,585850;13,933890;568,000000
2017-01-01T08:26:33Z;46,585850;13,933800;566,000000
2017-01-01T08:27:06Z;46,585861;13,933890;568,000000
2017-01-01T08:28:39Z;46,586102;13,934020;568,000000
2017-01-01T08:29:12Z;46,586189;13,934140;568,000000
2017-01-01T08:30:45Z;46,586571;13,935030;575,000000
2017-01-01T08:31:18Z;46,586380;13,935190;578,000000
2017-01-01T08:32:51Z;46,586231;13,935430;587,000000
2017-01-01T08:33:24Z;46,586189;13,935742;589,000000
2017-01-01T08:34:57Z;46,586044;13,935318;586,000000
2017-01-01T08:35:30Z;46,585884;13,935108;585,000000
2017-01-01T08:36:03Z;46,585556;13,934977;584,000000
2017-01-01T08:37:36Z;46,584991;13,935169;585,000000
2017-01-01T08:38:09Z;46,584873;13,935415;588,000000
2017-01-01T08:39:42Z;46,584988;13,935889;595,000000
2017-01-01T08:40:15Z;46,584732;13,936401;598,000000
2017-01-01T08:41:48Z;46,584587;13,936542;598,000000
2017-01-01T08:42:21Z;46,584084;13,936808;601,000000
2017-01-01T08:43:54Z;46,583740;13,936858;605,000000
2017-01-01T08:44:27Z;46,583382;13,936645;603,000000
2017-01-01T08:45:00Z;46,582825;13,936573;610,000000
2017-01-01T08:46:33Z;46,582233;13,936580;610,000000
2017-01-01T08:47:06Z;46,581547;13,936895;620,000000
2017-01-01T08:48:39Z;46,581005;13,936949;617,000000
2017-01-01T08:49:12Z;46,580612;13,937103;614,000000
2017-01-01T08:50:45Z;46,579273;13,938390;614,000000
2017-01-01T08:51:18Z;46,578617;13,939126;613,000000
2017-01-01T08:52:51Z;46,577793;13,939846;590,000000
2017-01-01T08:53:24Z;46,577614;13,940168;582,000000
2017-01-01T08:54:57Z;46,577606;13,940597;585,000000
2017-01-01T08:55:30Z;46,577351;13,941160;573,000000
2017-01-01T08:56:03Z;46,577271;13,940600;574,000000
2017-01-01T08:57:36Z;46,577160;13,940440;570,000000
2017-01-01T08:58:09Z;46,577229;13,939570;569,000000
2017-01-01T08:59:42Z;46,577171;13,938790;564,000000
2017-01-01T09:00:15Z;46,576939;13,937350;558,000000
2017-01-01T09:01:48Z;46,576839;13,937090;557,000000
2017-01-01T09:02:21Z;46,576679;13,936940;557,000000
2017-01-01T09:03:54Z;46,576401;13,936910;558,000000
2017-01-01T09:04:27Z;46,575958;13,936990;558,000000
2017-01-01T09:05:00Z;46,575970;13,936870;558,000000
2017-01-01T09:06:33Z;46,575958;13,936990;558,000000
2017-01-01T09:07:06Z;46,574810;13,937150;559,000000
2017-01-01T09:08:39Z;46,574371;13,936930;559,000000
2017-01-01T09:09:12Z;46,573891;13,936380;559,000000
2017-01-01T09:10:45Z;46,571651;13,934230;558,000000
2017-01-01T09:11:18Z;46,571678;13,934090;558,000000
2017-01-01T09:12:51Z;46,570862;13,933320;558,000000
2017-01-01T09:13:24Z;46,570782;13,933410;559,000000
2017-01-01T09:14:57Z;46,567661;13,930360;561,000000
2017-01-01T09:15:30Z;46,567059;13,929530;559,000000
2017-01-01T09:16:03Z;46,566631;13,928620;562,000000
2017-01-01T09:17:36Z;46,566349;13,927670;564,000000
2017-01-01T09:18:09Z;46,566212;13,926700;566,000000
2017-01-01T09:19:42Z;46,566021;13,921250;559,000000
2017-01-01T09:20:15Z;46,565910;13,920320;560,000000
2017-01-01T09:21:48Z;46,567348;13,919120;554,000000
2017-01-01T09:22:21Z;46,568130;13,918360;554,000000
2017-01-01T09:23:54Z;46,568310;13,918060;554,000000
2017-01-01T09:24:27Z;46,568459;13,917600;555,000000
2017-01-01T09:25:00Z;46,568562;13,917010;555,000000
2017-01-01T09:26:33Z;46,568710;13,916935;555,000000
2017-01-01T09:27:06Z;46,569260;13,917350;553,000000
2017-01-01T09:28:39Z;46,569359;13,916540;553,000000
2017-01-01T09:29:12Z;46,569820;13,915510;554,000000
2017-01-01T09:30:45Z;46,569832;13,915010;554,000000
2017-01-01T09:31:18Z;46,569740;13,914420;554,000000
2017-01-01T09:32:51Z;46,569939;13,911470;554,000000
2017-01-01T09:33:24Z;46,569328;13,910030;555,000000
2017-01-01T09:34:45Z;46,569328;13,910030;555,000000
2017-01-01T09:35:18Z;46,569221;13,909260;555,000000
2017-01-01T09:36:51Z;46,569382;13,907970;555,000000
2017-01-01T09:37:24Z;46,569359;13,907380;554,000000
2017-01-01T09:38:57Z;46,569759;13,907280;554,000000
2017-01-01T09:39:30Z;46,569672;13,906930;553,000000
2017-01-01T09:40:03Z;46,569691;13,906200;554,000000
2017-01-01T09:41:36Z;46,569599;13,905690;557,000000
2017-01-01T09:42:09Z;46,569729;13,904650;558,000000
2017-01-01T09:43:42Z;46,569939;13,904100;559,000000
2017-01-01T09:44:15Z;46,570789;13,902590;560,000000
2017-01-01T09:45:48Z;46,571072;13,902390;562,000000
2017-01-01T09:46:21Z;46,571442;13,902000;566,000000
2017-01-01T09:47:54Z;46,571072;13,902390;562,000000
2017-01-01T09:48:27Z;46,570789;13,902590;560,000000
2017-01-01T09:49:00Z;46,570789;13,902470;560,000000
2017-01-01T09:50:33Z;46,571510;13,901700;568,000000
2017-01-01T09:51:06Z;46,572231;13,901220;575,000000
2017-01-01T09:52:39Z;46,573738;13,900700;582,000000
2017-01-01T09:53:12Z;46,574261;13,900910;585,000000
2017-01-01T09:54:45Z;46,574539;13,900920;587,000000
2017-01-01T09:55:18Z;46,574959;13,900580;590,000000
2017-01-01T09:56:51Z;46,575291;13,900480;593,000000
2017-01-01T09:57:24Z;46,575611;13,900560;596,000000
2017-01-01T09:58:57Z;46,576900;13,901200;593,000000
2017-01-01T09:59:30Z;46,577309;13,901480;592,000000
2017-01-01T10:00:03Z;46,577560;13,901780;592,000000
2017-01-01T10:01:36Z;46,577888;13,902390;591,000000
2017-01-01T10:02:09Z;46,578159;13,903600;587,000000
2017-01-01T10:03:42Z;46,578590;13,904590;581,000000
2017-01-01T10:04:15Z;46,578579;13,904700;581,000000
2017-01-01T10:05:48Z;46,578590;13,904590;581,000000
2017-01-01T10:06:21Z;46,578892;13,905010;580,000000
2017-01-01T10:07:54Z;46,579639;13,905780;577,000000
2017-01-01T10:08:27Z;46,580151;13,905050;575,000000
2017-01-01T10:09:00Z;46,580280;13,903830;571,000000
2017-01-01T10:10:33Z;46,580742;13,902810;565,000000
2017-01-01T10:11:06Z;46,580952;13,902580;564,000000
2017-01-01T10:12:39Z;46,581478;13,902410;561,000000
2017-01-01T10:13:12Z;46,581692;13,902410;560,000000
2017-01-01T10:14:45Z;46,582111;13,902970;559,000000
2017-01-01T10:15:18Z;46,582809;13,903730;558,000000
2017-01-01T10:16:51Z;46,583530;13,904710;560,000000
2017-01-01T10:17:24Z;46,583900;13,905480;563,000000
2017-01-01T10:18:57Z;46,584190;13,906290;562,000000
2017-01-01T10:19:30Z;46,584480;13,908440;560,000000
2017-01-01T10:20:03Z;46,584541;13,909350;560,000000
2017-01-01T10:21:36Z;46,584431;13,911210;563,000000
2017-01-01T10:22:09Z;46,584530;13,912650;568,000000
2017-01-01T10:23:42Z;46,584881;13,913650;574,000000
2017-01-01T10:24:15Z;46,585331;13,914230;580,000000
2017-01-01T10:25:48Z;46,585571;13,914410;584,000000
2017-01-01T10:26:21Z;46,585468;13,914450;580,000000
2017-01-01T10:27:54Z;46,585091;13,915110;572,000000
2017-01-01T10:28:27Z;46,584251;13,915640;564,000000
2017-01-01T10:29:00Z;46,584019;13,915700;562,000000
2017-01-01T10:30:33Z;46,583981;13,916910;566,000000
2017-01-01T10:31:06Z;46,584019;13,918130;563,000000
2017-01-01T10:32:39Z;46,584370;13,919150;562,000000
2017-01-01T10:33:12Z;46,584949;13,920140;561,000000
2017-01-01T10:34:45Z;46,585072;13,920460;559,000000
2017-01-01T10:35:18Z;46,586079;13,922010;556,000000
2017-01-01T10:36:51Z;46,586231;13,922340;555,000000
2017-01-01T10:37:51Z;46,586418;13,923359;555,000000
2017-01-01T10:38:51Z;46,587618;13,922659;555,000000
```

beispiel.gpx:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<gpx version="1.1" creator="" xmlns="http://www.topografix.com/GPX/1/1">
 <metadata>
  <time>2017-01-01T08:05:00.00Z</time>
  <bounds minlat="46.0" minlon="13.0" maxlat="46.1" maxlon="13.1"/>
 </metadata>
 <trk>
  <name>Benennung des Tracks</name>
  <trkseg>
   <trkpt lat="47.81" lon="13.03">
    <ele>500.000000</ele>
    <time>2017-01-01T08:00:00Z</time>
   </trkpt>
   <trkpt lat="47.83" lon="13.05">
    <ele>600.000000</ele>
    <time>2017-01-01T08:01:00Z</time>
   </trkpt>
   <trkpt lat="47.83" lon="13.03">
    <ele>600.000000</ele>
    <time>2017-01-01T08:02:00Z</time>
   </trkpt>
   <trkpt lat="47.81" lon="13.03">
    <ele>500.000000</ele>
    <time>2017-01-01T08:03:00Z</time>
   </trkpt>
  </trkseg>
 </trk>
</gpx>
```

Dieser Track beinhaltet 4 Punkte (trkpt). Für jeden Punkt ist die Zeit (time), Latitude (lat), Longitude (lon) und die Höhe (ele) angegeben.

index.html:

```html
<html>
<head>
 <!-- Source: http://wiki.openstreetmap.org/wiki/Openlayers_Track_example -->
 <title>GPX-Track von ?</title>
 <!--  OpenLayers javascript library
	 	 Wir binden die  Bibliothek direkt aus dem Internet ein, 
	 	 die Datei kann bei Bedarf aber auch lokal abgespeichert werden)
	 -->
 <script src="http://www.openlayers.org/api/OpenLayers.js"></script>
 <!-- OpenStreetMap OpenLayers layers.
		Diese Datei bevorzugt aus dem Internet laden um sie aktuell zu halten 
	 -->
 <script src="http://www.openstreetmap.org/openlayers/OpenStreetMap.js"></script>

 <script type="text/javascript">
  // Aendern auf Trail-Start:
  var lat=47.8218747
  var lon=13.0454751
  var zoom=13

  var map; //complex object of type OpenLayers.Map

  function init() {
   map = new OpenLayers.Map ("map", {
    controls:[
     new OpenLayers.Control.Navigation(),
     new OpenLayers.Control.PanZoomBar(),
     new OpenLayers.Control.LayerSwitcher(),
     new OpenLayers.Control.Attribution()],
    maxExtent: new OpenLayers.Bounds(-20037508.34,-20037508.34,20037508.34,20037508.34),
    maxResolution: 156543.0399,
    numZoomLevels: 19,
    units: 'm',
    projection: new OpenLayers.Projection("EPSG:900913"),
    displayProjection: new OpenLayers.Projection("EPSG:4326")
   } );

   // Define the map layer
   // Here we use a predefined layer that will be kept up to
            // date with URL changes
   layerMapnik = new OpenLayers.Layer.OSM.Mapnik("Mapnik");
   map.addLayer(layerMapnik);
   layerCycleMap = new OpenLayers.Layer.OSM.CycleMap("CycleMap");
   map.addLayer(layerCycleMap);
   layerMarkers = new OpenLayers.Layer.Markers("Marker");
   map.addLayer(layerMarkers);

   // ******************************************************************
   // Block "Layer mit GPX-Track" - Start
   var GPXVariable_1 = new OpenLayers.Layer.Vector("Beispielstrecke", {
    strategies: [new OpenLayers.Strategy.Fixed()],
    protocol: new OpenLayers.Protocol.HTTP({
     url: "./beispiel.gpx",
     format: new OpenLayers.Format.GPX()
    }),
    style: {strokeColor: "red", strokeWidth: 5, strokeOpacity: 0.5},
    projection: new OpenLayers.Projection("EPSG:4326")
   });
   map.addLayer(GPXVariable_1);
   // Block "Layer mit GPX-Track" - Ende
   // ******************************************************************

   var lonLat = new OpenLayers.LonLat(lon, lat).transform(new OpenLayers.Projection("EPSG:4326"), map.getProjectionObject());
   map.setCenter(lonLat, zoom);
   
   // Home-Marker A214
   var latH=47.8218747
   var lonH=13.0454751

   var lonLatH = new OpenLayers.LonLat(lonH, latH).transform(new OpenLayers.Projection("EPSG:4326"), map.getProjectionObject());

   var size = new OpenLayers.Size(90, 40);
   var offset = new OpenLayers.Pixel(-(size.w/2), -size.h);
   var icon = new OpenLayers.Icon('./marker.png',size,offset);
   layerMarkers.addMarker(new OpenLayers.Marker(lonLatH,icon));
  }
 </script>

</head>
<!-- body.onload is called once the page is loaded
	 (call the 'init' function) -->
<body onload="init();">
 <!-- define a DIV into which the map will appear. Make it
		 take up the whole window -->
 <div style="width:90%; height:90%" id="map"></div>
</body>
</html>
```

In dieser Datei muss der GPX-Track angegeben (...url: "./beispiel.gpx"). Es können auch mehrere Tracks eingefügt werden, dann muss ein weiterer Layer (map.addLayer) einkopiert werden.
