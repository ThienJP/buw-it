/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 03, Aufgabe: 6 */
/* Datum: 01.11.2018 */
/****************************************/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void input_val(int* startX, double* endX, double* stepX, int* sigDigits);
void draw_table(double *x_val, double* x_pow3, double* sin, double* log, int sigDigits, int length);
void write_val(double* f_x, int start, double step,int length, int func);
double calc_log(double x);
double calc_sin(double x);
double calc_power3(double x);
double func_arg(double x);

int main() {
  int startX = 0;
  double endX = 0;
  double stepX = 0;
  int sigDigits = 0;
  int length;

  input_val(&startX, &endX,&stepX,&sigDigits);
  length = ((abs(startX) + abs(endX))/stepX);

  double x_val[length];
  write_val(x_val, startX, stepX, length, 4);

  double x_pow3[length];
  write_val(x_pow3, startX, stepX, length, 1);

  double sin[length];
  write_val(sin, startX, stepX, length, 2);

  double log[length];
  write_val(log, startX, stepX, length, 3);

  draw_table(x_val, x_pow3, sin, log, sigDigits, length);

  return 0;
}

void input_val(int* startX, double* endX, double* stepX, int* sigDigits) {

  cout << "Bitte Startwert fuer x eingeben: ";
  cin >> *startX;

  cout << "Bitte Endwert fuer x eingeben: ";
  cin >> *endX;

  cout << "Bitte Schrittweite fuer x eingeben: ";
  cin >> *stepX;

  cout << "Wieviele signifikante Ziffern sollen angezeigt werden? ";
  cin >> *sigDigits;
  cout << endl;
}

// calculate values and save it to array f_x
void write_val(double* f_x, int start, double step,int length, int func)
{
  double i = start;
  for (int j = 0; j <= length; ++j)
  {
    switch(func)
    {
      case(1): f_x[j]=calc_power3(i);
        break;
      case(2): f_x[j]=calc_sin(i);
        break;
      case(3): f_x[j]=calc_log(i);
        break;
      case(4): f_x[j]=func_arg(i);
        break;
      default: cout << endl;
    }
    i += step;
  }
}

double func_arg(double x) {
  return x;
}

double calc_power3(double x) {
  return pow(x, 3);
}

double calc_sin(double x) {
  return sin(x);
}

double calc_log(double x) {
  // error handling
  if (x <= 0) {
    return -1;
  } else
    return log(x);
}

void draw_table(double *x_val, double* x_pow3, double* sin, double* log, int sigDigits, int length)
{
  cout << left << setw(10) << "x";
  cout << setw(2) << "|";
  cout << setw(sigDigits+10) << "x^3";
  cout << setw(sigDigits+10) << "sin(x)";
  cout << setw(sigDigits+10) << "log(x)" << endl;

  for(int i = 0; i <= (10 + (10 + sigDigits) *3); ++i) {
    cout << "=";
  }
  cout << endl;

  for(int j = 0; j <= length; ++j) {
    cout << scientific << showpos << setprecision(2) << x_val[j] << setw(2) << " | ";
    cout << scientific << showpos << setprecision(sigDigits) << setw(sigDigits + 10) << x_pow3[j];
    cout << scientific << showpos << setprecision(sigDigits) << setw(sigDigits + 10) << sin[j];

    if (log[j] == -1) {
      cout << "/" << endl;
    } else {
      cout << scientific << showpos << setprecision(sigDigits) << setw(sigDigits + 10) << log[j] << endl;
    }
  }
}





