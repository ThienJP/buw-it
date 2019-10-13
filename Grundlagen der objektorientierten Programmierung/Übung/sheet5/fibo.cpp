/*
 * Grundlagen der objektorientierten Programmierung
 * Hochleistungsrechnen / Softwaretechnologie
 * Bergische Universitaet Wuppertal
 * Vorlage Blatt 5
 */

#include <iostream>

using namespace std;

unsigned f(unsigned n) {
  if(n==0) 
    return 0;

  unsigned* werte = new unsigned[n+1];
  werte[0] = 0;
  werte[1] = 1;
  for(unsigned i=2 ; i<n+1 ; i++) // Fehler 2: Schleifenzaehler nur bis n laufen lassen
    werte[i] = werte[i-1] + werte[i-2];
  unsigned ergebnis = werte[n];
  delete[] werte; // Fehler 1: Klammern
  return ergebnis;
}

int main() {
  cout << "Fibonacci-Folge: ";
  for(unsigned i=0 ; i<20 ; i++)
    cout << f(i) << " ";
  cout << endl;

  return 0;
}
