#include <cmath>
using namespace std;
#include "class_definite_integral.hpp"
#include "trapezoidal.hpp"

// Constructor
Definite_integral::Definite_integral(double a, double b, pfn f){
  lower = a;
  upper = b;
  integrand = f;
}

double Definite_integral::lowbd() const {return lower;}
double Definite_integral::upbd() const {return upper;}

void Definite_integral::change_bounds(double a, double b)
{
  lower=a;
  upper=b;
}

double Definite_integral::trapezoidal(int n) const {
  double integral=0.0; // Integral of a fct
  double h=(upper-lower)/n; // Space Step
  Vector x(n+1); // Vector of n+1 compenents initialized to 0
  for (int k=0;k<=n;k++) x[k]=lower+(k*h); // Space Coordinates;Complexity: n+1
  for (int k=0;k<n;k++) integral += (integrand(x[k+1])+integrand(x[k]))*(h/2); // Complexity: n
  return integral;
}
