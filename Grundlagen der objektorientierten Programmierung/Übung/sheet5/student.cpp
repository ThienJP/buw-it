#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person {
protected:
    string firstName;
    string lastName;
public:
    Person(string firstN, string lastN) : firstName(firstN), lastName(lastN) {
      cout << "Person: " << this->firstName << " " << this->lastName << " created" << endl;
    }

    ~Person() {
      cout << "Person: " << this->firstName << " " << this->lastName << " deleted" << endl;
    }
    void setfirstName(const string &name) {
      firstName = name;
    }
    void setlastName(const string &name) {
      lastName = name;
    }
};

class Student : public Person {
private:
    const unsigned matrikel;
    string major;
    int semester = 1;

public:
    Student(string firstN, string lastN, string majorr, unsigned matr) : Person(firstN, lastN), matrikel(matr) {
      major = majorr;

      cout << "Person: " << this->firstName << " " << this->lastName << " is now immatriculated" << endl;
    }

    ~Student() {
      cout << "Student: " << this->firstName << " " << this->lastName << " is now exmatriculated" << endl;
    }

    void setMajor(const string &m) {
      major = m;
    }

    void incSem(int n = 0) {
      this->semester += n;
      if (n == 0) {
        cout << this->firstName << " " << this->lastName << " ist immernoch im " << this->semester << ". Semester" << endl;
      } else
      cout << this->firstName << " " << this->lastName << " ist nun im " << this->semester << ". Semester" << endl;
    }

    string getfirstName() const {
      return this->firstName;
    }

    string getlastName() const {
      return this->lastName;
    }

    friend int stdcmp(const Student &stud1, const Student &stud2) {
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

    friend std::ostream& operator << (std::ostream& os , const Student& stud) {
      os << setw(10) << stud.firstName << "  " << setw(10) << stud.lastName << "  " << setw(10) << stud.matrikel << "  "
        << setw(12) << stud.major << "  " << setw(2) << stud.semester;
      return os;
    }
};

int main() {
  Student stud_A("Dio", "Brando", "Informatik", 1759060);
  Student stud_B("Jotaro", "Kujo", "Informatik", 1759060);
  Student stud_C("Joseph", "Joestar", "ET", 1659060);

  cout << stud_A << endl;
  cout << stud_B << endl;
  cout << stud_C << endl;

  stdcmp(stud_A, stud_B);
  stud_A.incSem(2);
  stud_B.incSem();
  stdcmp(stud_A, stud_B);

  return 0;
}