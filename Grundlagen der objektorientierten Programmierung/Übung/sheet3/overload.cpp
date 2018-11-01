/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 03, Aufgabe: 7 */
/* Datum: 01.11.2018 */
/****************************************/

/*
 * c) using both namespaces leads to a ambiguous call since there are two possible functions of out(char *val, int length);
 * solve error by specifically naming which function from which namespace to call by adding NAMESPACE:: before function call.
 *
 * d) 1. no, identical parameter types => redefinition
 *    2. yes, depending on 2nd parameter compiler knows which function to call
 *    3. yes, similar to 2)
 *    4. no, functions that differ only in their return type cannot be overloaded
 */

#include <iostream>

using namespace std;

namespace ausgeben {
    void out (char * val, int length) {
      cout << "Datentyp char:" << endl;
      for (int i = 0; i < length; ++i) {
        cout << val[i] << " ";
      }
      cout << endl;

      return;
    }

    void out (float * val, int length) {
      cout << "Datentyp float:" << endl;
      for (int i = 0; i < length; ++i) {
        cout << val[i] << " ";
      }
      cout << endl;

      return;
    }

    void out (bool * val, int length) {
      cout << "Datentyp bool:" << endl;
      for (int i = 0; i < length; ++i) {
        cout << noboolalpha << val[i] << " ";
      }
      cout << endl;

      return;
    }
}

namespace ausgeben_und_rechnen {
    void out (char * val, int length, bool berechne = false) {
      ausgeben::out(val, length);
      if (berechne != false) {
        char max = val[0];
        for (int i = 0; i < length; ++i) {
          if (val[i] > max) {
            max = val[i];
          }
        }
        cout << "größter ASCII-Wert: " << max << endl;
        cout << endl;
      } else {
        cout << endl;
      }

      return;
    }

    void out (float * val, int length, bool berechne = false) {
      ausgeben::out(val, length);
      if (berechne != false) {
        float sum;
        for (int i = 0; i < length; ++i) {
          sum += val[i];
        }

        cout << "Mittelwert: " << sum/length << endl;
        cout << endl;
      }

      return;
    }

    void out (bool * val, int length, bool berechne = false) {
      ausgeben::out(val, length);
      if (berechne != false) {
        cout << "Umgedreht: ";
        for (int i = length-1; i >= 0; --i) {
          cout << val[i] << " ";
        }
        cout << endl;
        cout << endl;
      }

      return;
    }
}

using namespace ausgeben_und_rechnen;
using namespace ausgeben;

int main() {
  char a[] = {'o','o','p','1','7'};
  float b[] = {-0.5f, 2.4f, 7.7f, 9.2f, -5.7};
  bool c[] = {false, true, false, true, false, false};

  ausgeben_und_rechnen::out(a,5);
  ausgeben_und_rechnen::out(b,5,true);
  ausgeben_und_rechnen::out(c,6,true);

  return 0;
}