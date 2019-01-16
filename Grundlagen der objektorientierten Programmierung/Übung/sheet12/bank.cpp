/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 12, Aufgabe: 39 */
/* Datum: 16.01.2019 */
/****************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;
using namespace std::placeholders;

class Adresse {
	private:
		string strasse;
		string hausnummer;
		string plz;
		string ort;

	public:
		Adresse(string s, string h, string p, string o)
		: strasse(s), hausnummer(h), plz(p), ort(o) {}

		string getStrasse() const { return strasse; }
		string getHausnummer() const { return hausnummer; }
		string getPlz() const { return plz; }
		string getOrt() const { return ort; }

	friend ostream& operator<<(ostream& os, const Adresse& a) {
		os << a.strasse << " " << a.hausnummer << ", " << a.plz << " " << a.ort;
		return os;
	}

	friend class Kunde;
};

class Konto {
	private:
		unsigned nr;
		double stand;

	public:
		Konto(unsigned n, double s) : nr(n), stand(s) {}

		unsigned getNr() const { return nr; }
		double getStand() const { return stand; }
    void setStand(double stand) {
		  stand += stand;
		}

    friend ostream& operator<<(ostream& os, const Konto& k) {
		os << fixed << setprecision(2);
		os << k.nr << ": " << k.stand << " Euro";
		return os;
	}

	friend class Kunde;
};

class Kunde {
	private:
		string vorname;
		string nachname;
		Adresse adresse;
		Konto konto;

	public:
		Kunde(string v, string n, Adresse a, Konto k)
		: vorname(v), nachname(n), adresse(a), konto(k) {}

		string getVorname() const { return vorname; }
		string getNachname() const { return nachname; }
		Adresse getAdresse() const { return adresse; }
		Konto getKonto() const { return konto; }

		void standAnpassen(double d) {
			konto.stand += d;
		}

	friend ostream& operator<<(ostream& os, const Kunde& k) {
		os << k.nachname << ", " << k.vorname << "\n";
		os << "   " << k.adresse << "\n";
		os << "   " << k.konto;
		return os;
	}
};

void ausgabe(const vector<Kunde>& v) {
	for(auto i : v)
		cout << i << endl;
}

//------------------------------------------------------------------------

//
// Klassen fuer Funktionsobjekte hier ergaenzen!
//
class gebuehr : public function<void(double)> {
private:
    double gebuehren;
public:
    gebuehr(double d) : gebuehren(d) {}
    ~gebuehr() {}

    void operator() (Kunde& k) {
      k.standAnpassen(gebuehren);
    }
};

class zinsen : public function<void (double)> {
private:
    double zins;
public:
    zinsen() {}
    ~zinsen() {}

    void operator() (Kunde& k) {
      if (k.getKonto().getStand() >= 0) {
        k.standAnpassen(k.getKonto().getStand() * 0.05);
      } else if (k.getKonto().getStand() < 0) {
       k.standAnpassen(k.getKonto().getStand() * 0.12);
      }
    }
};

class wohnt_in : public function<void(string)>{
private:
    string city;
    bool result;
public:
    wohnt_in(string name) : city(name) {}
    ~wohnt_in() {}

    bool operator() (Kunde &k) {
      result = k.getAdresse().getOrt() == city;
      return result;
    }
};

class wohnt_in_und_kontostand_groesser : public function<void(string, double)>{
private:
    string city;
    double kontostand;
public:
    wohnt_in_und_kontostand_groesser(string name, double stand) : city(name), kontostand(stand) {}
    ~wohnt_in_und_kontostand_groesser() {}

    bool operator() (Kunde &k) {
      if (k.getAdresse().getOrt() == city && k.getKonto().getStand() > kontostand) {
        return true;
      } else {
        return false;
      }
    }
};

class einlagen_summieren : public function<void(Kunde)> {
private:
    double sum;
public:
    einlagen_summieren() {}
    ~einlagen_summieren() {}

    void operator() (Kunde &k) {
      sum += k.getKonto().getStand();
    }
    double getSum() {
      return sum;
    }
};

//------------------------------------------------------------------------

int main() {
	vector<Kunde> kunden;

	kunden.push_back(Kunde("Wilhelm Conrad", "Roentgen", Adresse("Gaensemarkt", "1", "42897", "Remscheid"), Konto(123456, 2974.45)));
	kunden.push_back(Kunde("Friedrich", "Engels", Adresse("Bruch", "127", "42283", "Wuppertal"), Konto(852369, -71.59)));
	kunden.push_back(Kunde("Friedrich", "Bayer", Adresse("Heckinghauser Str.", "162", "42289", "Wuppertal"), Konto(755319, 223456.32)));
	kunden.push_back(Kunde("Pina", "Bausch", Adresse("Focher Str.", "1", "42719", "Solingen"), Konto(776209, 834.63)));

	cout << "Liste der Kunden: " << endl << endl;
	ausgabe(kunden);

	//
	// Hier die Kontogebuehren von 5 Euro
	// mittels 'for_each()' von jedem Kunden abziehen
	//
	for_each(kunden.begin(), kunden.end(), gebuehr(-5));
	cout << endl << endl << "Nach Abzug der Kontogebuehren: " << endl << endl;
	ausgabe(kunden);

	for_each(kunden.begin(), kunden.end(), zinsen());
	cout << endl << endl << "Nach Gutschrift der Zinsen: " << endl << endl;
	ausgabe(kunden);

	cout << endl << endl << "Der erste Kunde aus Wuppertal: " << endl << endl;
	cout << *(find_if(kunden.begin(), kunden.end(), wohnt_in("Wuppertal"))) << endl;

	vector<Kunde>::iterator it;
	it = remove_if(kunden.begin(), kunden.end(), wohnt_in_und_kontostand_groesser("Wuppertal", 1000.0));
	kunden.erase(it, kunden.end());
	cout << endl << endl << "Nach Wegzug aller Kunden aus Wuppertal mit mehr als 1000 Euro: " << endl << endl;
	ausgabe(kunden);

	einlagen_summieren esum;
	esum = for_each(kunden.begin(), kunden.end(), esum);
	cout << endl << endl << "Summierte Einlagen: " << esum.getSum() << endl << endl;

	//
	// Hier Lambda-Funktion 'compare' zum Vergleich
	// der Nachnamen zweier Kunden anlegen
	//
	auto compare = [] (Kunde& k1, Kunde& k2) {
    return (k1.getNachname() < k2.getNachname());
	};
	sort(kunden.begin(), kunden.end(), compare);
	cout << endl << "Nach Sortierung:" << endl << endl;
	ausgabe(kunden);

	return 0;
}
