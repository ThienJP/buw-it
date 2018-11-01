/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 03, Aufgabe: 7 */
/* Datum: 01.11.2018 */
/****************************************/

#include <iostream>
#include "faculty.h"
#include "binomi.h"

using namespace std;

int main() {
  for(int n=2; n<=7; n++) {
    cout << "(x+y)^" << n << " = x^" << n;
    for(int k=1; k<n; k++) {
      cout << " + " << n_ueber_k(n,k) << "x";
      if(n-k>1) cout << "^" << n-k;
      cout << "y";
      if(k>1) cout << "^" << k;
    }
    cout << " + y^" << n << endl;
  }
}
