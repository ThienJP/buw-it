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
#include "Note.hpp"

using namespace std;

Note::Note(string subj, int credits, double grd) : subject(subj), cp(credits), grade(grd) {}
Note::~Note() {}
string Note::getSubject() const {
  return subject;
}
int Note::getCP() const {
  return cp;
}

double Note::getGrade() const {
  return grade;
}

std::ostream& operator << (std::ostream& os , const Note& grade) {
  os << setw(10) << grade.subject << setw(10) << grade.cp << setw(10) << grade.grade;
  return os;
}
