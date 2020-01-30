#include <iostream>
#include <cmath>
#include "error.hpp"
#include "Vector.hpp"
#include "trapezoidal.hpp"
#include "mesh.hpp"
using namespace std;

typedef double (*pfn) (double);

double g(double x){return 1+x;};
double square(double x){return x*x;};
double cube(double x){return x*x*x;};

int main ()
{
  Mesh m(0,1,100000);
  double integral=0.0;

  // Trapezoidal Params
  integral = m.trapezoidal(g);
  cout << "Function 1+x integrated from " <<
  m.lower() << " to " << m.upper() << " is : " << integral << "\n";
  getchar();

  integral = m.trapezoidal(square);
  cout << "Function square integrated from " <<
  m.lower() << " to " << m.upper() << " is : " << integral<< "\n";
  getchar();

  Mesh mm(-1,1,100000);
  integral = mm.trapezoidal(cube);
  cout << "Function cube integrated from " <<
  mm.lower() << " to " << mm.upper() << " is : " << integral<< "\n";

}
