/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 04, Aufgabe: 10 */
/* Datum: 09.11.2018 */
/****************************************/

#include <iostream>
#include <iomanip>
#include "sort.hpp"

using namespace std;

template <typename T, typename S>
void sort (T *arr, S length) {
  for (int i = 0; i < length-1; ++i) {
    for (int j = 0; j < length-1; ++j) {
      if (arr[j] > arr[j+1]) {
        T tmp;
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
}


// template specialization
template <>
void sort<char, int>(char *arr, int length) {
  for (int i = 0; i < length-1; ++i) {
    for (int j = 0; j < length-1; ++j) {
      if (arr[j] < arr[j+1]) {
        char tmp;
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
}


template<typename T>
void print (T *p, int dim)
{
  for (int i = 0; i < dim; ++i) {
    cout << setprecision(2) << p[i] << " ";
  }
  cout << endl;

  return;
}

int main() {
  int dim;
  int* intarr;
  double* dbarr;
  char* charr;
  cout << "Dimension: ";
  cin >> dim;

  // allocate mem
  intarr = new int[dim];
  dbarr = new double[dim];
  charr = new char[dim];

  // fill with random numbers
  srand(time(NULL));
  for (int i = 0; i < dim; ++i) {
    intarr[i] = rand() % dim;
    dbarr[i] = ((double)rand()/(double)RAND_MAX)*10.;;
    charr[i] = 'a' + rand() % 26;
  }
  cout << "Unsortiert: " << endl;
  cout << "int Array: ";
  print(intarr, dim);
  cout << "double Array: ";
  print(dbarr, dim);
  cout << "char Array: ";
  print(charr, dim);
  cout << endl;

  sort(intarr, dim);
  sort(dbarr, dim);
  sort(charr, dim);

  cout << "Sortiert: " << endl;
  cout << "int Array: ";
  print(intarr, dim);
  cout << "double Array: ";
  print(dbarr, dim);
  cout << "char Array: ";
  print(charr, dim);

  // free mem
  delete[] intarr;
  delete[] dbarr;

  return 0;
}
