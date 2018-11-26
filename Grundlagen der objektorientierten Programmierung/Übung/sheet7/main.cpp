/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 07, Aufgabe: 21 */
/* Datum: 26.11.2018 */
/****************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Person.hpp"
#include "Student.hpp"
#include "Note.hpp"

using namespace std;

int main() {

  Student s("Jim", "Button", 1674589);
	//Student s;
  //cout << "Bitte Studenten eingeben: ";
	//cin >> s;

  Student harry("Dio", "Brando", 1648952);
  harry.addNote(Note("OOP", 6, 1.3));
  harry.addNote(Note("SWT", 6, 1.7));
  harry.addNote(Note("Info I", 9, 1.3));

  Student bastian("Jotaro", "Kujo", 1537516);
  bastian.addNote(Note("LA I", 9, 2.3));
  bastian.addNote(Note("LA II", 9, 2.0));

  Student pippi("Joseph", "Joestar", 1549765);
  pippi.addNote(Note("AuD", 9, 2.7));
  pippi.addNote(Note("OOP", 6, 1.7));
  pippi.addNote(Note("Java", 6, 3.3));

  bastian.incSem();
  pippi.incSem(2);

  cout << s << endl;
  cout << harry << endl;
  cout << bastian << endl;
  cout << pippi << endl;

  studcmp(bastian, pippi);

  Student s2(move(harry));
	cout << "Harry:" << endl << harry << endl;
	cout << "Kopie Harry:" << endl << s2 << endl;

	pippi = move(bastian);
	cout << "Bastian:" << endl << bastian << endl;
	cout << "Zuweisung Pippi:" << endl << pippi << endl;

  return 0;
}
