/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 09, Aufgabe: 28 */
/* Datum: 13.12.2018 */
/****************************************/

/*
 *  Fahrzeug -> KFZ -> PKW
 *     |            -> LKW
 *     v
 *    Fahrrad
 *
 *  PKW und LKW erben von KFZ, KFZ und Fahrrad erben von Fahrzeug,
 *  Fahrzeug ist Oberklasse von allen
 */

 /*
 * ausgegebene Anzahl weicht ab, da in Z. 110 das Objekt kopiert wird und nicht der ctor fuer Fahrzeug neu aufgerufen wird
 * Man muesste einen copy-ctor fuer Fahrzeug anlegen, der ein Objekt der Klasse Fahrzeug uebergeben bekommt.
 */

#include <utility>
#include <iostream>
#include <string>

using namespace std;

class Fahrzeug {
protected:
    float gewicht;
    string marke;
    static int anzahl;
public:
    Fahrzeug(float weight, string brand) : gewicht(weight), marke(brand) {
      anzahl++;
    }
    Fahrzeug(Fahrzeug& f1) {
      gewicht = f1.gewicht;
      marke = f1.marke;

      anzahl++;
    }
    ~Fahrzeug() {
      anzahl--;
    }

    static int getAnzahl() {
      return anzahl;
    }

    friend ostream& operator <<(ostream& os, Fahrzeug& fz) {
      os << "Ein Fahrzeug von " << fz.marke
      << " mit einem Gewicht von " << fz.gewicht << " kg";

      return os;
    }
};
int Fahrzeug::anzahl = 0;

class KFZ : public Fahrzeug {
protected:
    unsigned ps;
public:
    KFZ(float g, string brand, unsigned hp) : Fahrzeug(g, brand), ps(hp) {}

    friend ostream& operator <<(ostream& os, KFZ& kf) {
      os << "Ein KFZ von " << kf.marke
      << " mit einem Gewicht von " << kf.gewicht << " kg"
      << " und " << kf.ps << " PS";

      return os;
    }
};

class PKW : public KFZ {
	private:
		unsigned sitzplaetze;

	public:
		PKW(float g, string f, unsigned p, unsigned s) : KFZ(g, f, p), sitzplaetze(s) {}

    friend ostream& operator <<(ostream& os, PKW& pk) {
      os << "Ein PKW von " << pk.marke
      << " mit einem Gewicht von " << pk.gewicht << " kg"
      << ", " << pk.ps << " PS"
      << " und " << pk.sitzplaetze << " Sitzplaetzen";

      return os;
    }
};

class LKW : public KFZ {
	private:
		unsigned nutzlast;

	public:
		LKW(float g, string f, unsigned p, unsigned n) : KFZ(g, f, p), nutzlast(n) {}

    friend ostream& operator <<(ostream& os, LKW& truck) {
      os << "Ein LKW von " << truck.marke
         << " mit einem Gewicht von " << truck.gewicht << " kg"
         << ", " << truck.ps << " PS"
         << " und einer Nutzlast von " << truck.nutzlast;

      return os;
    }
};

class Fahrrad : public Fahrzeug {
	private:
		unsigned rahmenhoehe;
	public:
		Fahrrad(float g, string f, unsigned r) : Fahrzeug(g, f), rahmenhoehe(r) {
		}

		friend ostream& operator <<(ostream& os, Fahrrad& f) {
      os << "Ein Fahrrad von " << f.marke
      << " mit einem Gewicht von " << f.gewicht << " kg"
      << " und Rahmenhoehe " << f.rahmenhoehe;

		  return os;
		}
};

int main() {

	Fahrzeug f1(1260.5, "Audi");
	cout << f1 << endl;
	Fahrzeug f2(f1);
	cout << f2 << endl;
	KFZ k1(1200, "Mercedes", 120);
	cout << k1 << endl;
	PKW p1(1125.52, "Seat", 90, 5);
	cout << p1 << endl;
	LKW l1(12300, "BMW", 500, 20000);
	cout << l1 << endl;
	Fahrrad r1(10.7, "Kettler", 57);
	cout << r1 << endl;
	cout << "Anzahl Fahrzeuge: " << Fahrzeug::getAnzahl() << endl;

	return 0;
}
