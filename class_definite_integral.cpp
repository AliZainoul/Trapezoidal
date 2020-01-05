#include <cmath>
using namespace std;
#include "trapezoidal.hpp"
#include "class_definite_integral.hpp"


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
  integral = ::trapezoidal(lower,upper,integrand,n);
  return integral;
}
