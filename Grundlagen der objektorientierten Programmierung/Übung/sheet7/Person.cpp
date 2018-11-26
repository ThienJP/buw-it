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

using namespace std;

Person::Person(string firstN, string lastN) : firstName(firstN), lastName(lastN) {}
Person::~Person() {}

void Person::setfirstName(const string &name) {
firstName = name;
}
void Person::setlastName(const string &name) {
lastName = name;
}
