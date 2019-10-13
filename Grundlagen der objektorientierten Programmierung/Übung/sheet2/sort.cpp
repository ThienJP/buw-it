/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 02, Aufgabe: 3 */
/* Datum: 23.10.2018 */
/* Status: lauffaehig */
/****************************************/

/*
 * a) sort 2 arrays filled with random numbers using 2 different algorithms (bubblesort + selectionsort),
 * 		g++ can compile c code by treating c code as c++.
 * c) gcc can't compile c++ but g++ can compile c code.
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "zeit.hpp"

const int MAXLENGTH = 50000;

using namespace std;

void swap(int num[], int i, int j) {
	int tmp = num[j];
	num[j]  = num[i];
	num[i]  = tmp;
}

// bubbleSort
void sort1(int num[], int start, int end) {
	bool finished = false;

	while(!finished) {
		finished = true;
		for(int i=start ; i<end ; i++) {
			if(num[i] > num[i+1]) {
				swap(num, i, i+1);
				finished = false;
			}
		}
	}
}

// selectionSort
void sort2(int num[], int start, int end) {
	int min;

	do {
		min = start;
		for(int i=start+1; i<=end; i++) {
			if(num[i] < num[min])
				min = i;
		}
		swap(num, min, start);
		start++;
	}
	while(start < end);
}

void sum(const int num1[], const int num2[], int length, long int &erg) {
	erg = 0.0;

	for(int i=0 ; i<length ; i++)
		erg += num1[i] + num2[i];
}

void prod(const int num1[], const int num2[], int length, long int &erg) {
	erg = num1[0] * num1[length/2] * num1[length-1];
	erg += num2[0] * num2[length/2] * num2[length-1];
}

void out(int num[], int start, int end) {
	for(int i=start ; i<=end ; i++)
	  cout << num[i] << " ";
	cout << " " << endl;
}

int main() {
	int numbers1[MAXLENGTH];
	int numbers2[MAXLENGTH];
	int length;
	long int summe;
	long int erg;
  double start, end;
  clock_t starto, endo;

	cout << "Anzahl der Elemente: ";
	cin >> length;

	if(length<=0 || length>MAXLENGTH) {
	  cout << "Fehler, Anzahl muss zwischen 1 und " << MAXLENGTH << " liegen" << endl;
		return 1;
	}

	/* Mit Zufallszahlen zwischen 1 und length fuellen */
	srand(time(nullptr));
	for(int i=0 ; i<length ; i++) {
		numbers1[i] = rand() % length + 1;
		numbers2[i] = rand() % length + 1;
	}

	summe = 0;
	for(int i=0 ; i<length ; i++)
		summe += numbers1[i];

	cout << " " << endl;

	cout << "Array 1 vor dem Sortieren: " << endl;
  out(numbers1,0,length-1);
	cout << "Array 2 vor dem Sortieren: " << endl;
	out(numbers2,0,length-1);

	cout << " " << endl;
	cout << "Der Mittelwert von Array 1 hat den Wert " << (double)summe/length << endl;
  cout << " " << endl;

  cout << "Sortiere Array 1 mit " << length << " Elementen mit Algorithmus 1..." << endl;
  start = GetTime();
  sort1(numbers1,0,length-1);
  end = GetTime();
  print_time_used(start, end);

	cout << "Sortiere Array 2 mit " << length << " Elementen mit Algorithmus 2..." << endl;
  starto = GetTime();
	sort2(numbers2,0,length-1);
	endo = GetTime();
	print_time_used(starto, endo);
	cout << " " << endl;

  cout << "Array 1 nach dem Sortieren: " << endl;
	out(numbers1,0,length-1);
	cout << "Array 2 nach dem Sortieren: " << endl;
	out(numbers2,0,length-1);
  cout << " " << endl;

  sum(numbers1, numbers2, length, erg);
  cout << "Ergebnis von sum: " << erg << endl;

	prod(numbers1, numbers2, length, erg);
	cout << "Ergebnis von prod: " << erg << endl;

  cout << " " << endl;

  return 0;
}
