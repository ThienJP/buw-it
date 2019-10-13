/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 12, Aufgabe: 38 */
/* Datum: 16.01.2019 */
/****************************************/

#include <iostream>
#include "vereine.hpp"

using namespace std;

int main()
{
	Verein v1("Bayern Muenchen", 37, 11, 41);
	Verein v2("Schalke 04", 28, 21, 30);
	Verein v3("Borussia Dortmund", 39, 24, 28);
	Verein v4("Werder Bremen", 13, 20, 15);
	Verein v5("Hamburger SV", 15, 25, 15);
	Verein v6("1. FC Koeln", 10, 32, 6);
	Verein v7("Wuppertaler SV", 99, 0, 51);

	Liga l1("Bundesliga");
	l1.verein_hinzufuegen(v1);
	l1.verein_hinzufuegen(v2);
	l1.verein_hinzufuegen(v3);
	l1.verein_hinzufuegen(v4);
	l1.verein_hinzufuegen(v5);
	l1.verein_hinzufuegen(v6);
	l1.verein_hinzufuegen(v7);
	l1.verein_entfernen(v7);

  Verein v21("Fortuna Duesseldorf", 27, 20, 34);
  Verein v22("Holstein Kiel", 37, 23, 33);
  Verein v23("1. FC Nuernberg", 36, 23, 33);
  Verein v24("Ingolstadt", 27, 20, 28);
  Verein v25("FC Sandhausen", 24, 18, 27);
  Verein v26("Union Berlin", 33, 26, 26);

  Liga l2("Zweite Bundesliga");
  l2.verein_hinzufuegen(v21);
  l2.verein_hinzufuegen(v22);
  l2.verein_hinzufuegen(v23);
  l2.verein_hinzufuegen(v24);
  l2.verein_hinzufuegen(v25);
  l2.verein_hinzufuegen(v26);

  l1.sortieren();
  cout << "Liste nach Namen sortiert:" << endl;
  cout << l1 << endl;

  l1.sortieren(3);
  cout << "Liste nach Torverhaeltnis sortiert:" << endl;
  cout << l1 << endl;

  l1.sortieren(2);
  cout << "Liste nach Punkten sortiert:" << endl;
  cout << l1 << endl;

  neueSaison(l1, l2);
  cout << "Tabellen nach Auf- & Abstieg:" << endl;
  cout << l1 << endl;
  cout << l2 << endl;

	return 0;
}
