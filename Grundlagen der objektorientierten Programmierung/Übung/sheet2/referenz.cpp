/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 02, Aufgabe: 4 */
/* Datum: 23.10.2018 */
/* Status: lauffaehig */
/****************************************/

/*
 * a) i = 20, d = 8, c = c
 *
 * c) call-by-value: kopiert den Wert der übergebenen Argumente in die Parameter der aufgerufenen Funktion.
 * Bedeutet: Code in der Funktion ändern die ursprünglichen Argumente nicht.
 *
 * call-by-reference: kopiert die Referenz der übergebenen Arugmente in die Parameter der aufgerufenen Funktion.
 * Bedeutet: Code in der Funktion greift auf die ursprünglich übergebenen Argumente zu und Werte können verändert werden.
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void bar (int& i, double d, char& c) {
	cout << "Beginn von bar: " << i << ", " << d << ", " << c << endl;
	i += 1;
	d /= 2;
	cout << "Mitte von bar: " << i << ", " << d << ", " << c << endl;
	d *= 5;
	i = d;
	c += i;
	cout << "Ende von bar: " << i << ", " << d << ", " << c << endl;
}

void foo (int& i, double& d, char c) {
	cout << "Beginn von foo: " << i << ", " << d << ", " << c << endl;
	i -= 3;
	d *= i;
	cout << "Mitte von foo: " << i << ", " << d << ", " << c << endl;
	bar (i,d,c);
	cout << "Ende von foo: " << i << ", " << d << ", " << c << endl;
}

void foo_ptr (int* i, double* d, char c) {
	cout << "Beginn von foo: " << i << ", " << d << ", " << c << endl;
	*i -= 3;
	*d *= *i;
	cout << "Mitte von foo: " << i << ", " << d << ", " << c << endl;
	bar(*i,*d,c);
	cout << "Ende von foo: " << i << ", " << d << ", " << c << endl;
}

int main () {
	int i{5};
	double d{4};
	char c{'c'};

  foo(i,d,c);
  cout << "Main: " << i << ", " << d << ", " << c << endl;

  i = 5;
  d = 4;
  c = 'c';
  foo_ptr(&i,&d,c);
	cout << "Main (ptr): " << i << ", " << d << ", " << c << endl;

	return 0;
}