#include <cmath>
#include <iostream>
#include <utility>
#include "Vector.hpp"
//#include "full_mat_c.hpp"
#include "trapezoidal.hpp"
#include "mesh.hpp"
typedef double (*pfn) (double);
/*for (int i=0; i < nv; ++i)
{
  x.push_back(i.dx);
}
dx()
*/

Mesh::Mesh(double a,double b, unsigned int n_interval){
  if (a > b)
  error("The supremum value b must be greater than the infinimum a; please try again.");
  else
  {
    xr = b;
    xl = a;
    ni = n_interval;
    L = xr-xl;
    h = L/ni;
    x.resize(n_interval);
    center.resize(n_interval-1);
    for (unsigned int k = 0; k <= ni; ++k) x[k] = xl + (k*h);
    for (unsigned int k = 0; k < ni; ++k) center[k] = (x[k] + x[k+1]) / 2;
  }
}

double Mesh::trapezoidal(pfn f) const {
  double integral=0.0; // Integral of a fct
  integral = ::trapezoidal(xl,xr,f,ni);
  return integral;
}
