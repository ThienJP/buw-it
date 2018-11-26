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

Student::Student(string firstN, string lastN, unsigned matr, unsigned semester, double gpa) : Person(firstN, lastN), matrikel(matr) {}

// default ctor if no arguments passed
Student::Student() : Student("", "", 0) {}

// copy ctor
Student::Student(const Student& stud) : Person(stud.firstName, stud.lastName), matrikel(stud.matrikel),
                                         semester(stud.semester), grades(stud.grades), gpa(stud.gpa) {}

// move ctor
Student::Student(Student&& stud) : Person(stud.firstName, stud.lastName) {
  matrikel = stud.matrikel;
  semester = stud.semester;
  grades = stud.grades;
  gpa = stud.gpa;

  stud.gpa = 0;
  stud.grades.clear();
}

Student::~Student() {}

void Student::incSem(int n) {
  this->semester += n;
  if (n == 0) {
    cout << this->firstName << " " << this->lastName << " ist immernoch im " << this->semester << ". Semester" << endl;
  } else
  cout << this->firstName << " " << this->lastName << " ist nun im " << this->semester << ". Semester" << endl;
}

// pass Note object and push onto vector, then recalc GPA
void Student::addNote(const Note& exam) {
  grades.push_back(exam);

  this->gpa = calcGPA();
}

double Student::calcGPA() {
  double avg = 0.0;
  // int cp;
  if (grades.size() == 0) {
    return 0.0;
  }

  for(auto i = 0; i < grades.size(); ++i) {
    /*
     * gewichtet nach Leistungspunkten??
     *
    cp = grades[i].getCP();
    avg += ( cp * grades[i].getGrade() );
    */
    avg += grades[i].getGrade();
  }

  return avg / grades.size();
}

string Student::getfirstName() const {
  return this->firstName;
}

string Student::getlastName() const {
  return this->lastName;
}

int studcmp(const Student &stud1, const Student &stud2) {
  if (stud1.semester > stud2.semester) {
    cout << stud1.getfirstName() << " " << stud1.getlastName() << " ist im höheren Semester als "
        << stud2.getfirstName() << " " << stud2.getlastName() << endl;
    return 1;
  } else if (stud1.semester == stud2.semester) {
    cout << stud1.getfirstName() << " " << stud1.getlastName() << " und "
        << stud2.getfirstName() << " " << stud2.getlastName() << " sind im gleichen Semester." << endl;
    return -1;
  } else
    cout << stud2.getfirstName() << " " << stud2.getlastName() << " ist im höheren Semester als "
        << stud2.getfirstName() << " " << stud2.getlastName() << endl;
  
  return 0;
}

Student& Student::operator =(Student&& stud) {
  if(this != &stud) {
    matrikel = stud.matrikel;
    semester = stud.semester;
    grades = stud.grades;
    gpa = stud.gpa;

    stud.gpa = 0;
    stud.grades.clear();
  }

  return *this;
}

std::ostream& operator << (std::ostream& os , const Student& stud) {
  os << setw(7) << stud.matrikel << setw(10) << stud.firstName << setw(10) << stud.lastName << setw(4) << stud.semester << ". Semester"
    << setw(12) << "Schnitt: " << setprecision(3) << stud.gpa << endl;

  // only print out grades if grades vector not empty
  if (!stud.grades.empty()) {
    for (const auto &grade : stud.grades) {
      cout << setw(12) << grade.getSubject() << "," << setw(2) << grade.getCP() << " LP," << " Note: " << setw(3) << grade.getGrade() << endl;
    }
  }

  return os;
}

std::istream& operator >> (std::istream& is , Student& stud) {
is >> stud.firstName >> stud.lastName >> stud.matrikel;
return is;
}
