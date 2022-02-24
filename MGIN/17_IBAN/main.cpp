#include <iostream>

using namespace std;

class Pruefziffer
{
public:
  /**
   * Gibt an, ob die Prüfziffer der ISBN-Nummer gültig ist.
   * verwendet: calcPruefziffer_ISBN(string nummerISBN)
   * @param string nummerISBN: ISBN-Nummer (inkl. '-')
   * @return bool: true, wenn die errechnete Prüfziffer
   * gleich der letzten Ziffer der ISBN-Nummer ist
   */
  static bool isValid_ISBN(string nummerISBN)
  {
    // ???????????
  }
  /**
   * Berechnet aus der ISBN-13 Nummer die Prüfziffer
   * @param string nummerISBN: ISBN-Nummer (inkl. '-')
   * @return char: errechnete Prüfziffer */
  static char calcPruefziffer_ISBN(string nummerISBN)
  {
    // ????????????
    // löscht alle '-' Zeichen
    string nummer = getDigitsOnly(nummerISBN);
    // berechnet die Prüfziffer und gibt diese zurück
    // ????????????
  }

private:
  // lokale Hilfsfunktion
  // gibt einen string, der nur aus Ziffern besteht zurück
  static string getDigitsOnly(string nummer)
  {
    // ???????????
  }
};
// ---------------------------------------------------------------
int main()
{
  string isbn = string("978-0-30716-548-0");
  string isValid;
  cout << "ISBN: " << isbn << endl;
  isValid = bool isValid_ISBN(isbn) ? "true" : "false";
  cout << "Pruefziffer ist " << isValid << endl;
  return 0;
}
