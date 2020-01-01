#include <iostream>
#include <cmath>
using namespace std;

#include "Vector.hpp"
#include "error.hpp"
#include "trapezoidal.hpp"
#include "class_definite_integral.hpp"

typedef double (*pfn) (double);

double Square(double x){return x*x;};
double Cube(double x){return x*x*x;};
// cout << "the name of this function is: " << __func__ << endl;

int main ()
{
  int n=0;
  double integral=0.0;
  double a=0.0;
  double b=0.0;

  cout << "Entrez la borne inf a : \n";
  cin >> a;
  cout << "Entrez la borne sup b :  \n";
  cin >> b;
  cout << "Entrez le nombre n : \n";
  cin >> n;

  Definite_integral iff = Definite_integral(a, b, Square);
  integral = iff.trapezoidal(n);
  cout << "Function integrated from " << a << " to " << b << " is : " << integral <<"\n";


  iff = Definite_integral(a, b, Cube);
  integral = iff.trapezoidal(n);
  cout << "Function integrated from " << a << " to " << b << " is : " << integral <<"\n";

  iff = Definite_integral(a, b, sqrt);
  integral = iff.trapezoidal(n);
  cout << "Function integrated from " << a << " to " << b << " is : " << integral <<"\n";
}
