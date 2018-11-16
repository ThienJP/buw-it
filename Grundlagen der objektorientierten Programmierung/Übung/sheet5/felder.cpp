/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 03, Aufgabe: 6 */
/* Datum: 01.11.2018 */
/****************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Feld {
private:
    int length;
    ifstream dataStream;
    vector<int> feld;
public:
    Feld(string fileN);
    ~Feld();
    int getLength() const;
    void displayVector();
    void swap(int *a, int *b);
    void sortVector();
    double calcMedian();
    long long calcProd(int length);
    friend long long sum(Feld &vec1, Feld &vec2);
    friend long long prod(Feld &vec1, Feld &vec2);
};

Feld::Feld(string fileN) {
  dataStream.open(fileN, ios::in);

  if (!dataStream) {
    cerr << "File corrupted." << endl;
  } else {
    // read length of field
    dataStream >> length;
    string line;
    // skip first line since we already saved the value to length;
    getline(dataStream, line);
    // retrieve line, parse values and push to vector
    getline(dataStream, line);
    istringstream iss(line);
    for (int i = 0; i < length; ++i) {
    int val;
    iss >> val;
    feld.push_back(val);
  }
  dataStream.close();

  // display contents and size of vector
  cout << "Vector initialisiert: ";
  displayVector();
  cout << "Laenge: " << getLength() << endl;
  }
}

Feld::~Feld() {
  // empty dtor
  cout << "Feld freigegeben" << endl;
}

int Feld::getLength() const {
  return this->length;
}

void Feld::displayVector() {
  for (const auto i: feld) {
    cout << i << ' ';
  }
}

void Feld::swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// bubbleSort
void Feld::sortVector() {
  int n = getLength();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (feld[j] > feld[j + 1]) {
        swap(&feld[j], &feld[j + 1]);
      }
    }
  }
}

double Feld::calcMedian() {
  int n = getLength();
  double result;

  for (int i = 0; i < n; ++i) {
    result += feld[i];
  }
  return result / (double) n;
}

long long Feld::calcProd(int length) {
  auto result = 1;

  for (int i = 0; i < length; ++i) {
    result *= feld[i];
  }

  return result;
}

long long sum(Feld &vec1, Feld &vec2) {
  auto result = 0;
  int n = vec1.getLength();
  int m = vec2.getLength();

  if (n != m) {
    return 0;
  } else {
    for (int i = 0; i < n; ++i) {
      result += vec1.feld[i];
    }

    for (int j = 0; j < n; ++j) {
      result += vec2.feld[j];
    }
  }

  return result;
}

long long prod(Feld &vec1, Feld &vec2) {
  int n = vec1.getLength();
  int m = vec2.getLength();

  return vec1.calcProd(n) * vec2.calcProd(m);
}

int main() {
  string file1 = "feld1.txt";
  string file2 = "feld2.txt";

  Feld vec1(file1);
  vec1.sortVector();
  cout << "Sortiert: ";
  vec1.displayVector();
  cout << "Mittelwert: " << vec1.calcMedian() << endl;

  cout << endl;

  Feld vec2(file2);
  vec2.sortVector();
  cout << "Sortiert: ";
  vec2.displayVector();
  cout << "Mittelwert: " << vec2.calcMedian() << endl;

  cout << endl;
  if (sum(vec1, vec2) == 0) {
    cout << "Dimensionen stimmen nicht ueberein." << endl;
  } else {
    cout << "Summe beider Felder: " << sum(vec1, vec2) << endl;
  }
  cout << "Produkt beider Felder: " << prod(vec1, vec2) << endl << endl;

  return 0;
}