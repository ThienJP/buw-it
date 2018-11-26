/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 07, Aufgabe: 21 */
/* Datum: 26.11.2018 */
/****************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Person {
protected:
    string firstName;
    string lastName;
public:
    Person(string firstN, string lastN);
    ~Person();
    void setfirstName(const string &name);
    void setlastName(const string &name);
};

#endif
