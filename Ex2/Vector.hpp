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
  Vector(); // Constructor 0 : Default Constructor
  // Vector(int i); // Constructor 1 : Test Constructor
  Vector(int i, double v=0); // Constructor 2 : Original Constructor
  Vector(initializer_list<double> lst); // Constructor 3 : List Constructor
  Vector(Vector const &v); // Constructor 4 : Copy Constructor
  Vector(Vector&& v); // Constructor 5 : Move constructor
  Vector& operator=(Vector const &v); // Constructor 6 : Assignment Operator
  Vector& operator=(Vector&& v); // Constructor 7 : Move Assignment Operator
  ~Vector(); // Destructor
  void affiche();

  double& operator[](int i){return M_data[i];} // Subscript Operator lvalue (for left value)
  double operator[](int i) const{return M_data[i];} // Subscript Operator const

  friend std::ostream& operator << (std::ostream&, const Vector&); // '<<' Overload
  void reset(double = 0);

  int size() const { return M_size; } // Return Size of the Vector
  double maxnorm() const; // L-infinity norm
  double twonorm() const; // L-2 norm

  Vector& operator+=(const Vector& vec); // Unary Operator, usage: V += W
  Vector& operator-=(const Vector& vec); // Unary Operator, usage: V -= W
  friend Vector operator+(const Vector&); // Unary operator, usage: V = +W
  friend Vector operator-(const Vector&); // Unary operator, usage: V = -W
  friend Vector operator+(const Vector&, const Vector&);  // Binary Operator, usage:  V = V1 + V2
  friend Vector operator-(const Vector&, const Vector&);  // Binary Operator, usage: V = V1 - V2
  friend Vector operator*(double, const Vector&); // Vector-Scalar multiplication, usage: V = k * W
  friend Vector operator*(const Vector&, double); // Vector-Scalar multiplication, usage: V = W * k
  friend double dot(const Vector&, const Vector&); // Dot product, usage: d = Dot(V1,V2)
};



#endif
