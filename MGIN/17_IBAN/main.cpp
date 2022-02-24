#include <iostream>
#include <algorithm>

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
    if (calcPruefziffer_ISBN(nummerISBN) == nummerISBN[nummerISBN.length() - 1])
    {
      return true;
    }
    return false;
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
    int pruefZiffer = 0;
    for (int i = 0; i < nummer.length(); i++)
    {
      if ((i + 1) % 2 == 0)
      {
        pruefZiffer += (nummer[i] - '0') * 3;
      }
      else
      {
        pruefZiffer += nummer[i] - '0';
      }
    }
    pruefZiffer = pruefZiffer % 10;
    return to_string(pruefZiffer)[0];
  }

private:
  // lokale Hilfsfunktion
  // gibt einen string, der nur aus Ziffern besteht zurück
  static string getDigitsOnly(string nummer)
  {
    nummer.erase(remove(nummer.begin(), nummer.end(), '-'), nummer.end());
    return nummer;
  }
};
// ---------------------------------------------------------------
int main()
{
  Pruefziffer pruefziffer;
  string isbn = string("978-0-30716-548-0");
  string isValid;
  cout << "ISBN: " << isbn << endl;
  isValid = (bool)pruefziffer.isValid_ISBN(isbn) ? "true" : "false";
  cout << "Pruefziffer ist " << isValid << endl;
  return 0;
}
