/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 06, Aufgabe: 17 */
/* Datum: 21.11.2018 */
/****************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Intervall {
private:
    int inf;
    int sup;
public:
    Intervall(int inf, int sup) : inf(inf), sup(sup) {
      if (inf > sup) {
        swap(&inf, &sup);
      }
    }

    Intervall() : Intervall(0,0) { }
    ~Intervall() {

    }

    int getInf() const {
      return inf;
    }

    void setInf(int inf) {
      Intervall::inf = inf;
    }

    int getSup() const {
      return sup;
    }

    void setSup(int sup) {
      Intervall::sup = sup;
    }

    void swap(int *inf, int *sup) {
      int temp = *inf;
      *inf = *sup;
      *sup = temp;
    }

    friend std::ostream& operator << (std::ostream& os, const Intervall& intervall) {
      os << "[" << intervall.inf << ", " << intervall.sup << "]";
      return os;
    }

    friend std::istream& operator>>(std::istream& is, Intervall& intervall) {
      is >> intervall.inf >> intervall.sup;
      // check if wohldefiniert
      if (intervall.inf > intervall.sup) {
        intervall.swap(&intervall.inf, &intervall.sup);
      }

      return is;
    }

    Intervall &operator +(const Intervall &b) {
      Intervall c;
      c.inf = this->inf + b.inf;
      c.sup = this->sup + b.sup;

      return c;
    }

    Intervall &operator +=(const Intervall &b) {
      this->inf += b.inf;
      this->sup += b.sup;

      return *this;
    }
};

Intervall operator *(const Intervall &a, const Intervall &b) {
  Intervall c;
  vector<int> minmax;

  minmax.push_back(a.getInf() * b.getInf());
  minmax.push_back(a.getInf() * b.getSup());
  minmax.push_back(a.getSup() * b.getInf());
  minmax.push_back(a.getSup() * b.getSup());

  for (int j : minmax) {
    cout << j << " ";
  }
  cout << endl;

  sort(minmax.begin(), minmax.end());
  c.setInf(minmax[0]);
  c.setSup(minmax[minmax.size()-1]);

  return c;
}

int main() {
  Intervall a(1, 5);
  Intervall b(2, 10);
  Intervall c;

  cout << setw(10) << "a = " << a << endl;
  cout << setw(10) << "b = " << b << endl;
  cout << setw(10) << "c = " << c << endl;

  cout << setw(10) << "a + b = " << a+b << endl;
  c = a+b;
  cout << setw(10) << "c = a+b = " << a+b << endl;
  c += a;
  cout << setw(10) << "c += a = " << c << endl;

  cout << setw(10) << "a = " << a << endl;
  cout << setw(10) << "b = " << b << endl;
  cout << setw(10) << "c = " << c << endl;

  Intervall d;
  d = a * b;
  cout << setw(10) << "d = a*b = " << d << endl;

  Intervall e;
  cout << "Enter Intervall: " << endl;
  cin >> e;
  cout << "e = " << e << endl;

  return 0;
}
