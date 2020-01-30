#ifndef MESH_H
#define MESH_H
#include <iostream>
#include <cassert>
#include <cmath>
#include <utility>
//#include "full_mat_c.hpp"
#include "mesh.hpp"
#include "Vector.hpp"
#include "error.hpp"
using namespace std;
typedef double (*pfn) (double);

class Mesh
{
  private:
  double xl; // Left-hand side of the interval I = [xl,xr]
  double xr; // Right-hand side of the interval I = [xl,xr]
  unsigned int ni; // Number of intervals
  double L; // Interval Length L = xr - xl
  double h; // Discretized step h = L / n
  //double dx; xmin + i * dx = i.dx
  Vector x; // Vector x of discretized points
  Vector center; // Center of the cell C[i]


  public:
  // MAIN CONSTRUCTOR of a 1D-MESH
  Mesh(double a,double b, unsigned int n_interval);
  double lower() const {return xl;}
  double upper() const {return xr;}
  double trapezoidal (pfn f) const;

  //double Mesh::dx const {return  a + (i*h); }
  //void discretize()..
};

#endif
