#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cassert>
using namespace std;

class Vector
{
 private:
  double* M_data;
  int M_size;

 public:
  // Constructors
  Vector();                             // Constructor 0: Default Constructor
  Vector(int i);                        // Constructor 1: Size Constructor
  Vector(int i, double v);              // Constructor 2: Size-Value Constructor
  Vector(initializer_list<double> lst); // Constructor 3: List Constructor
  Vector(Vector const &v);              // Constructor 4: Copy Constructor
  Vector(Vector&& v);                   // Constructor 5: Move constructor

  // Destructors
  ~Vector();

  // void reset(double x);
  void show();
  int size() const;    // Return Size of the Vector
  void resize(int n);

  // Norms
  double maxnorm() const;                // L-infinity norm
  double twonorm() const;                // L-2 norm

  // Operators
  Vector& operator=(Vector const &v);    // Assignment Operator
  Vector& operator=(Vector&& v);         // Move Assignment Operator
  Vector& operator+=(const Vector& vec); // Binary Operator, V += W
  Vector& operator-=(const Vector& vec); // Binary Operator, V -= W
  double& operator[](int i){return M_data[i];} // Subscript Operator left value
  double operator[](int i) const{return M_data[i];} // Subscript Operator const

  // Friends Functions
  friend ostream& operator<< (ostream&, const Vector&);// '<<' Overload
  friend Vector   operator+ (const Vector&, const Vector&); // Binary Operator V = V1 + V2
  friend Vector   operator- (const Vector&, const Vector&); // Binary Operator V = V1 - V2
  friend Vector   operator+ (const Vector&);           // Unary Operator, V = +W
  friend Vector   operator- (const Vector&);           // Unary Operator, V = -W
  friend Vector   operator* (double, const Vector&);   // Scalar-Vector Product
  friend Vector   operator* (const Vector&, double);   // Vector-Scalar Product
  friend double dot(const Vector&, const Vector&);     // Dot product


};
#endif
