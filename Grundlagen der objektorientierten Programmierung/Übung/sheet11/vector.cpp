/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 11, Aufgabe: 35 */
/* Datum: 23.12.2018 */
/****************************************/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class Mitarbeiter {
private:
    int personalnummer;
    string name;
    double gehalt;
public:
    Mitarbeiter(int pNum, string fullName, double salary) : personalnummer(pNum), name(fullName), gehalt(salary) {}
    ~Mitarbeiter() {}

    int getPersonalnummer() const {
      return personalnummer;
    }

    void setPersonalnummer(int personalnummer) {
      Mitarbeiter::personalnummer = personalnummer;
    }

    const string &getName() const {
      return name;
    }

    void setName(const string &name) {
      Mitarbeiter::name = name;
    }

    double getGehalt() const {
      return gehalt;
    }

    void setGehalt(double gehalt) {
      Mitarbeiter::gehalt = gehalt;
    }

    friend ostream& operator <<(ostream& os, Mitarbeiter& emp) {
      os << setw(6) << emp.personalnummer << setw(15) << emp.name << setw(12) << emp.gehalt << " € ";

      return os;
    }
};

class Abteilung {
private:
    string bezeichnung;
    vector<Mitarbeiter> angestellte;
public:
    Abteilung(string label, Mitarbeiter& employee) : bezeichnung(label) {
      angestellte.push_back(employee);
    }

    explicit Abteilung(string label) : bezeichnung (label) {}

    ~Abteilung() {
      angestellte.empty();
    }

    void addEmployee(Mitarbeiter& emp) {
      angestellte.push_back(emp);
    }

    void remEmployee(int pNum) {
      for (int i = 0; i < angestellte.size(); ++i) {
        if (pNum == angestellte[i].getPersonalnummer()) {
          cout << "Lay off employee # " << pNum << endl;
          angestellte.erase(angestellte.begin() + i);
        }
      }
    }

    struct sortBy {
        int category;
        sortBy(int category) {
          this->category = category;
        }

        bool operator() (const Mitarbeiter& L, const Mitarbeiter& R) const {
          switch (category) {
            case 1: return L.getPersonalnummer() < R.getPersonalnummer();
                    break;
            case 2: return L.getName() < R.getName();
                    break;
            case 3: return L.getGehalt() < R.getGehalt();
                    break;
            default: return false;
                    break;
          }
        }
    };

    void sortieren(int category) {
      switch (category) {
        case 1: cout << "Sortieren nach: PNUM" << endl;
                break;
        case 2: cout << "Sortieren nach: NAME" << endl;
                break;
        case 3: cout << "Sortieren nach: GEHALT" << endl;
                break;
        default: break;
      }
      sort(angestellte.begin(), angestellte.end(), sortBy(category));
    }

    friend ostream& operator <<(ostream& os, Abteilung& dep) {
      os << setw(8) << "Abteilung: " << setw(8) << dep.bezeichnung << endl;
      for (int i = 0; i < dep.angestellte.size(); ++i) {
        cout << i+1 << dep.angestellte[i] << endl;
      }

      return os;
    }
};

int main() {
  enum sortBy { PNUM = 1, NAME = 2, GEHALT = 3 };

  Mitarbeiter m1(127, "Dio Brando", 4987.87);
  Mitarbeiter m2(231, "Jotaro Kujo", 5143.69);
  Mitarbeiter m3(29, "SHIZAAAAA", 4359.32);
  cout << m1 << endl;

  Abteilung a1("Sales");
  a1.addEmployee(m3);
  a1.addEmployee(m2);
  a1.addEmployee(m1);
  cout << endl;

  cout << "Unsortiert: " << endl;
  cout << a1 << endl;

  a1.sortieren(NAME);
  cout << a1 << endl;

  a1.sortieren(PNUM);
  cout << a1 << endl;

  a1.sortieren(GEHALT);
  cout << a1 << endl;

  a1.remEmployee(18501);
  cout << a1 << endl;

  return 0;
}
