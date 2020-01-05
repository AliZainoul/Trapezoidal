using namespace std;
#ifndef CLASS_DEFINITE_INTEGRAL_H
#define CLASS_DEFINITE_INTEGRAL_H

// Class Declaration
typedef double (*pfn) (double);
//typedef double MyFunction (double);


class Definite_integral
{
private :
  double lower;
  double upper;
  pfn integrand;

public:
  Definite_integral(double a, double b, pfn f); // constructor
  double lowbd() const; // accessor: get lower bound
  double upbd() const; // accessor: get upper bound
  void change_bounds(double a, double b); //change integral bounds to a, b
  double trapezoidal(int n) const; // Compute integral using Trapezoidal
  //friend double trapezoidal(double a, double b, pfn f, int n);
  //double integral_polynome(MyFunction polynome,double* x,double* omega,int n);

};

#endif
