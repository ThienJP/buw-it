/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 11, Aufgabe: 34 */
/* Datum: 23.12.2018 */
/****************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

class DimensionException : public exception {
public:
    virtual const char* what() const noexcept {
      return "Fehler: Vektoren unterschiedlicher Dimension!\n";
    }
};

class DivisionException : public exception {
public:
    virtual const char* what() const noexcept {
      return "Fehler: Division durch Null!\n";
    }
};


class Vektor
{
	private:
		double* d;
		int n;

	public:
		Vektor(int i) : n(i) {
			d = new double[i];
			for(int i=0 ; i<n ; i++)
				d[i] = rand() % 100 / 10.0;
		}

		~Vektor() {
			delete[] d;
		}

		//Vektoren elementweise addieren
		Vektor& operator+=(const Vektor& v) {
			if(v.n != n) {
				throw(DimensionException());
			}

			for(int i=0 ; i<n ; i++)
				d[i] += v.d[i];

			return *this;
		}

		//Jedes Element des Vektors durch z teilen
		Vektor& operator/=(double z) {
			if(z == 0) {
				throw(DivisionException());
			}

			for(int i=0 ; i<n ; i++)
				d[i] /= z;

			return *this;
		}

	friend ostream& operator<<(ostream& os, const Vektor& v) {
		os << setprecision(1) << fixed;
		os << "(";
		for(int i=0; i<v.n; ++i) {
			os << v.d[i];
			if(i<v.n-1)
				os << ",  ";
		}
		os << ")";
		return os;
	}
};

int main() {
	srand(time(nullptr));
	Vektor v1(5);
	Vektor v2(5);
	Vektor v3(6);
	cout << "       v1: " << v1 << endl;
	cout << "       v2: " << v2 << endl;
	cout << "       v3: " << v3 << endl;

	try {
    v1 += v2;
    cout << " v1 += v2: " << v1 << endl;
  }
  catch (DimensionException err_DIM) {
    cout << err_DIM.what();
  }

  try {
    v3 /= 2.5;
    cout << "v3 /= 2.5: " << v3 << endl;
  }
  catch (DivisionException err_DIV) {
    cout << err_DIV.what();
  }

  cout << " v1 += v3: ";
  try {
    v1 += v3;
    cout << v1 << endl;
  }
  catch (DimensionException err_DIM) {
    cout << err_DIM.what();
  }

  cout << "v3 /= 0.0: ";
  try {
    v3 /= 0.0;
    cout << v3 << endl;
  }
  catch (DivisionException err_DIV) {
    cout << err_DIV.what();
  }
  
	return 0;
}
