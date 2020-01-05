#include <iostream>
#include <cmath>
#include "Vector.hpp"
#include "error.hpp"
using namespace std;

typedef double (*pfn) (double);

double trapezoidal(double a, double b, pfn f, int n){
  double h = (b-a)/n;
  double x_0 = a;
  double integral=0.0;
  Vector x(n+1,x_0);
  x[n] = b;
  for (unsigned int i = 1; i < n; ++i) x[i] = x[i-1] + h;
  for (unsigned int k = 1; k <= n+1; ++k) integral += (f(x[k-1]) +f(x[k]))*(h/2);
  return integral;
}
