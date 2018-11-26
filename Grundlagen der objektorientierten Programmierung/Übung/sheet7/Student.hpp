/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 07, Aufgabe: 21 */
/* Datum: 26.11.2018 */
/****************************************/
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Person.hpp"
#include "Note.hpp"

using namespace std;

class Student : public Person {
private:
    unsigned matrikel;
    unsigned semester = 1;
    vector<Note> grades;
    double gpa = 0.0;
public:
    Student(string firstN, string lastN, unsigned matr, unsigned semester = 1, double gpa = 0.0);
    Student();
    Student(const Student& stud);
    Student(Student&& stud);
    ~Student();
    void incSem(int n = 0);
    void addNote(const Note& exam);
    double calcGPA();
    string getfirstName() const;
    string getlastName() const;
    friend int studcmp(const Student &stud1, const Student &stud2);
    Student& operator =(Student&& stud);
    friend std::ostream& operator << (std::ostream& os , const Student& stud);
    friend std::istream& operator >> (std::istream& is , Student& stud);
};

#endif
