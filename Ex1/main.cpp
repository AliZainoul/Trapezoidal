#include <iostream>
#include <cmath>
#include "trapezoidal.hpp"
#include "Vector.hpp"
#include "error.hpp"
using namespace std;

typedef double (*pfn) (double);

double g(double x){return 1+x;};
double square(double x){return x*x;};
double cube(double x){return x*x*x;};

int main ()
{
  int n=0;
  double h=0.0;
  double x_0=0.0;
  double integral=0.0;
  double a=0.0;
  double b=0.0;

  cout << "Entrez un nombre d'intervalles n :  \n";
  cin >> n;
  cout << "Entrez la borne inf a : \n ";
  cin >> a;
  cout << "Entrez la borne sup b :  \n";
  cin >> b;

  h = (b-a)/n;
  getchar();
  integral = trapezoidal(a, b, g, n);
  cout << "Function 1+x integrated from " << a << " to " << b << " is : " << integral << "\n";

  getchar();
  integral = trapezoidal(a, b, square, n);
  cout << "Function square integrated from " << a << "to " << b << " is : " << integral<< "\n";

  getchar();
  integral = trapezoidal(a, b, cube, n);
  cout << "Function cube integrated from " << a << "to " << b << " is : " << integral<< "\n";

}
