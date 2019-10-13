/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 07, Aufgabe: 22 */
/* Datum: 26.11.2018 */
/****************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

class Muenzwurf {
private:
    int result;
    static int flips;
public:
    Muenzwurf() {
      result = rand() % 2;
      flips++;
    }
    ~Muenzwurf() {}

    static int getFlips() {
      return flips;
    }

    int getResult() const {
      return result;
    }

    friend ostream &operator <<(ostream &os, const Muenzwurf &muenzwurf) {
      string strResult;
      if (muenzwurf.result == 1) {
        strResult = "Heads";
      } else if (muenzwurf.result == 0) {
        strResult = "Tails";
      }

      os << "Last flip: " << strResult << endl;

      return os;
    }
};
int Muenzwurf::flips = 0;

class Wurfstatistik {
private:
    int heads = 0;
    int tails = 0;
public:
    Wurfstatistik() {
      srand(time(NULL));
    }
    ~Wurfstatistik() {}

    int getHeads() const {
      return heads;
    }

    int getTails() const {
      return tails;
    }

    Wurfstatistik &operator +=(const Muenzwurf& flip) {
      if (flip.getResult() == 1) {
        heads++;
      } else if (flip.getResult() == 0) {
          tails++;
      }

      return *this;
    }

    friend ostream &operator <<(ostream &os, const Wurfstatistik &stats) {
      os << setw(10) << "Heads: " << stats.getHeads() << setw(10) << "Tails: " << stats.getTails();

      return os;
    }
};

int main() {
  int n = 10000;
  Wurfstatistik flipStats;

  for (int i = 1; i <= n ; ++i) {
    Muenzwurf flips;
    flipStats += flips;

    if ((i % 1000) == 0) {
      cout << "Statistik nach " << i << " Coinflips: " << endl;
      cout << flipStats << endl;
      cout << flips << endl;
    }
  }

  return 0;
}
