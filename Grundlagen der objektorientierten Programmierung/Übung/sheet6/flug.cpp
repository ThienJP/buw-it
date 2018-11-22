/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 06, Aufgabe: 18 */
/* Datum: 21.11.2018 */
/****************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "flug.hpp"

using namespace std;

int main()
{
	Flug f1("Lufthansa", "Duesseldorf", "Berlin", 15);
	f1.addBuchung(Buchung("Petra Meier", "B3"));
	f1.addBuchung(Buchung("Dieter Schmidt", "E1"));
	cout << "[f1] nach zwei Buchungen" << endl << f1 << endl;

	Flug f2(f1);
	f2.addBuchung(Buchung("Carolin Becker", "A2"));
	f2.addBuchung(Buchung("Stefan Becker", "A1"));
	f1.umbuchen("B3", "B1");
	cout << "[f2] nach zwei weiteren Buchungen" << endl << f2 << endl;
	cout << "[f1] nach einer Umbuchung" << endl << f1 << endl;

	f1 = f2;
	cout << "[f1] nach Zuweisung" << endl << f1 << endl;

	return 0;
}
