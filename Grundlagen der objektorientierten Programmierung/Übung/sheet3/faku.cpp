#include "faculty.h"

double faku(int n) {
  double erg=1;
  for(int i=2; i<=n; i++)
    erg*=i;
  return erg;
}