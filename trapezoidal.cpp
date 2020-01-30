#include <iostream>
#include <cmath>
using namespace std;
#include "Vector.hpp"
#include "error.hpp"
typedef double (*pfn) (double);

double trapezoidal(double a, double b, pfn f, int n){
  double h = (b-a)/n;
  double integral=0.0;
  //Vector x(n+1,0.0);
  double* x = new double [n+1];
  for (unsigned int k = 0; k <= n;  ++k) x[k] = a + k*h;
  for (unsigned int k = 1; k <= n+1; ++k) integral += (f(x[k-1]) +f(x[k]))*(h/2);
  return integral;
}
