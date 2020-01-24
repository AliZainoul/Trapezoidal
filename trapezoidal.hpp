#ifndef TRAPEZOIDAL_H
#define TRAPEZOIDAL_H
#include <iostream>
#include <cmath>

  typedef double (*pfn) (double);
  double trapezoidal(double a, double b, pfn f, int n);

#endif
