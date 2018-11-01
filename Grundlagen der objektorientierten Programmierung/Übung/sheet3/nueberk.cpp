#include "binomi.h"
#include "faculty.h"

double n_ueber_k(int n, int k)  {
  return faku(n)/(faku(k)*faku(n-k));
}

