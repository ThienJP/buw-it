/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 09, Aufgabe: 27 */
/* Datum: 13.12.2018 */
/****************************************/


#include <iostream>
#include <cmath>

using namespace std;

template<typename T, typename R> class Kreis {
	private:
		T m_x; //x-Koordinate Mittelpunkt
		T m_y; //y-Koordinate Mittelpunkt
		R rad; //Radius

	public:
		Kreis(T x, T y, R r) : m_x(x), m_y(y), rad(r) {
			if(rad < 0) {
        rad*=-1;
			}
		}

		void setMittelpunkt(int x, int y) {
			m_x = x;
			m_y = y;
		}

		void setRad(double r) {
			rad = r;
		}

		T getX() const {return m_x;}
		T getY() const {return m_y;}
		R getRad() const {return rad;}

		R berechne_flaecheninhalt();
		R berechne_umfang();
		bool schneidet(const Kreis<T, R>& k2);
};

template<typename T, typename R>
istream& operator>>(istream& is, Kreis<T, R>& k) {
  T x, y;
  R r;

	is >> x >> y >> r;
  k.setMittelpunkt(x, y);
  k.setRad(r);

	return is;
}

template<typename T, typename R>
ostream& operator<<(ostream& os, const Kreis<T, R>& k) {
	os << "Mittelpunkt: (" << k.getX() << "," << k.getY() << "), Radius: " << k.getRad();
	return os;
}
template <typename T, typename R>
R Kreis<T,R>::berechne_flaecheninhalt() {
	return 3.14 * (rad * rad);
}

template <typename T, typename R>
R Kreis<T, R>::berechne_umfang() {
  return 2 * 3.14 * rad;
}

template <typename T, typename R>
bool Kreis<T, R>::schneidet(const Kreis<T, R>& k2) {
  T distance;
  R max_r;

  if (this->rad > k2.rad) {
    max_r = this->rad;
  } else if (this->rad <= k2.rad) {
    max_r = k2.rad;
  }

  distance = sqrt( (m_x - k2.m_x) * (m_x - k2.m_x) + (m_y - k2.m_y) * (m_y - k2.m_y) );

  /*
   * if distance between both circles < radius of larger circle then intersect == true
   */
  if (distance < max_r ) {
    return true;
  } else if (distance >= max_r) {
      return false;
  }
}

int main() {

	Kreis<int,double> k1(2,2,1.5);
	cout << "Kreis k1: " << k1 << endl;
	cout << "Flaecheninhalt k1: " << k1.berechne_flaecheninhalt() << endl;
	cout << "Umfang k1: " << k1.berechne_umfang() << endl << endl;

	Kreis<double,double> k2(0.0,0.0,3.14);
	cout << "Kreis k2 eingeben: ";
	cin >> k2;
	cout << "Kreis k2: " << k2 << endl;
	cout << "Flaecheninhalt k2: " << k2.berechne_flaecheninhalt() << endl;
	cout << "Umfang k2: " << k2.berechne_umfang() << endl << endl;

	Kreis<double,double> k3(3.5,-0.5,1.0);
	cout << "Kreis k3: " << k3 << endl;
	cout << boolalpha << "Kreis k2 schneidet k3: " << k2.schneidet(k3) << endl;

	return 0;
}
