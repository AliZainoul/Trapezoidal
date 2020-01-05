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

int main ()
{
  int n;
  n = 100000;
  double integral=0.0;

  cout << "**** **** **** ****" << endl;
  Definite_integral iff = Definite_integral(0, 1, Square);
  integral = iff.trapezoidal(n);
  cout << "Function Square integrated from " << iff.lowbd() <<
  " to " << iff.upbd() << " is : " << integral <<"\n";
  iff.change_bounds(-1,1);
  integral = iff.trapezoidal(n);
  cout << "Function Square integrated from " << iff.lowbd() <<
   " to " << iff.upbd() << " is : " << integral <<"\n";
  iff.change_bounds(10,10);
  integral = iff.trapezoidal(n);
  cout << "Function Square integrated from " << iff.lowbd() <<
   " to " << iff.upbd() << " is : " << integral <<"\n";
  getchar();

  cout << "**** **** **** ****" << endl;
  iff = Definite_integral(0,1,Cube);
  integral = iff.trapezoidal(n);
  cout << "Function Cube integrated from " << iff.lowbd() <<
   " to " << iff.upbd() << " is : " << integral <<"\n";
  iff.change_bounds(-1,1);
  integral = iff.trapezoidal(n);
  cout << "Function Cube integrated from " << iff.lowbd() <<
   " to " << iff.upbd() << " is : " << integral <<"\n";
  iff.change_bounds(10,10);
  integral = iff.trapezoidal(n);
  cout << "Function Cube integrated from " << iff.lowbd() <<
   " to " << iff.upbd() << " is : " << integral <<"\n";
  getchar();

  cout << "**** **** **** ****" << endl;
  iff = Definite_integral(0, 1, sqrt);
  integral = iff.trapezoidal(n);
  cout << "Function Sqrt integrated from " << iff.lowbd() << " to " << iff.upbd() << " is : " << integral <<"\n";
  iff.change_bounds(1,1);
  integral = iff.trapezoidal(n);
  cout << "Function Sqrt integrated from " << iff.lowbd() << " to " << iff.upbd() << " is : " << integral <<"\n";
  cout << "**** **** **** ****" << endl;
  getchar();

}
