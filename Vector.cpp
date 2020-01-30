#include <iostream>
#include <cmath>
#include "Vector.hpp"
#include "error.hpp"
using namespace std;

// Constructor 0 - Default Constructor
// Usage: Vector V => V = NULLPTR
Vector::Vector(){
	M_data = nullptr;
	M_size = 0;
}

// Constructor 1 - Size Constructor
// Usage: Vector V(10) => V = [0.0 ; 0.0 ; ... ; 0.0], size=10;
Vector::Vector(int i){
	M_data = new double[i];
	M_size = i;
  for(int k=0;k<M_size;++k) M_data[k] = 0.0;
}

// Constructor 2 - Size and value Constructor
// Usage: Vector V(2,3) => V = [3;3], size=2;
Vector::Vector(int i, double v){
	M_data = new double[i];
	M_size = i;
  for(int k=0;k<M_size;++k) M_data[k]=v;
}
// Constructor 3 - List Constructor
// Usage: Vector V = {x1,...,xn} => V = [x1; ... ;xn], size=n;
Vector::Vector(initializer_list<double> lst){
	M_data = new double[lst.size()];
	M_size = static_cast<int>(lst.size());
 	copy(lst.begin(), lst.end(), M_data); // std::copy(...)
}

// Constructor 4 - Copy Constructor
// Usage: Vector V = W => V = W, size=size of  W;
Vector::Vector(Vector const &v){
	(v.M_size==0)? M_data = nullptr : M_data = new double[v.M_size];
	M_size = v.M_size;
	for (int k=0;k<M_size;++k) M_data[k] = v.M_data[k];
}

// Constructor 5 - Move Constructor
// Usage: Vector V(W) => V = W, size=size of  W;
Vector::Vector(Vector&& v){
	M_data=v.M_data;
	M_size=v.M_size;
	v.M_size = 0;
	v.M_data = nullptr;
}

// Destructor
Vector::~Vector(){
	delete[] M_data;
}

// Show Function
void Vector::show(){
  cout << "Vector's Size: "<< M_size<< endl;
	cout << " Index : ";
	cout << " [ " ;
  for(int i=0; i<M_size; i++)
	{
		cout << "  " << i+1	<< "  ";
	}
	cout << " ] " ;
	cout << endl;
	cout << " Value : ";
	cout << " [ " ;
	for(int i=0; i<M_size; i++)
	{
		cout << "  " <<M_data[i] << "  ";
	}
	cout << " ] " ;
	cout << endl;
}
void Vector::resize(int n){
	M_size = n;
	delete[] M_data;
	M_data = new double [n];
}


int Vector::size() const { return M_size; }    // Return Size of the Vector

/*Vector Vector::reset(double x) {
for(int i=0; i<M_size; i++) M_data[i]=x;
};*/



// Assignment Operator
Vector& Vector::operator=(Vector const &v){
  if (this != &v){
	  delete[] M_data;
	  M_data = new double[M_size=v.M_size];
	  for(int k=0;k<M_size;++k) M_data[k]=v.M_data[k];
  }
  return *this;
}

// Move Assignment Operator
Vector& Vector::operator=(Vector&& v){
	delete[] M_data;
	M_data = v.M_data;
	M_size = v.M_size;
	v.M_data = nullptr;
	v.M_size = 0;
	return *this;
}

// Surcharge Of Operator 'Outstream'
std::ostream& operator << (std::ostream& s, const Vector& v){
	s << "Vector's size is : " << v.M_size << endl;
  for (int i = 0; i < v.M_size; i++)
	s << i+1 << "  "<< v.M_data[i]<<"  "<< endl;
  return s;
}

// L-infinity Norm for Vectors
double Vector::maxnorm() const{
  double max_norm=abs(M_data[0]);
  for (int i = 1; i < M_size; i++){
		double vi = abs(M_data[i]);
		if (max_norm < vi) max_norm = vi;
	}
  return max_norm;
};

// L-2 Norm for Vectors
double Vector::twonorm() const{
  double two_norm=0.0;
  for (int i = 0; i < M_size; i++) two_norm += pow(M_data[i],2);
  return sqrt(two_norm);
};

// Dot Operator
double dot(const Vector& v1, const Vector& v2) {
  if (v1.M_size != v2.M_size ) error("Bad vector sizes in dot product.");
  double tm = v1[0]*v2[0];
  for (int i = 1; i < v1.M_size; i++) tm += v1[i]*v2[i];
  return tm;
}

// Scalar-Vector Product
Vector operator*(double scalar, const Vector& vec) {
  Vector tm(vec.M_size);
  for (int i = 0; i < vec.M_size; i++) tm[i] = scalar*vec[i];
  return tm;
}

// Vector-Scalar Product
Vector operator*(const Vector& vec, double scalar) {
  Vector tm(vec.M_size);
  for (int i = 0; i < vec.M_size; i++) tm[i] = scalar*vec[i];
  return tm;
}

// Unary Operator "+" overload - Usage: Vector V1 = +V2;
Vector operator+(const Vector& vec) {return vec;}

// Unary Operator "-" overload - Usage: Vector V1 = -V2;
Vector operator-(const Vector& vec) {
  Vector minus = vec;
  for (int i = 0; i < vec.M_size; i++) minus[i] = (-1) * vec[i];
  return minus;
}
// Binary Operator "+" overload - Usage: Vector V = V1+V2;
Vector operator+(const Vector& v1, const Vector& v2) {
  if (v1.M_size != v2.M_size ) error("Bad vector sizes in Vector addition.");
  Vector sum = v1;
  sum += v2;
  return sum;
}

// Binary Operator "-" overload - Usage: Vector V = V1-V2;
Vector operator-(const Vector& v1, const Vector & v2) {         // v=v1-v2
  if (v1.M_size != v2.M_size ) error("Bad vector sizes in Vector substraction.");
  Vector sum = v1; // It would cause problem without copy constructor
  sum -= v2;
  return sum;
}
// Unary Operator "+=" overload - Usage: V += W
Vector& Vector::operator+=(const Vector& vec) {
  if (M_size != vec.M_size) error("Bad vector sizes in Vector::operator+=()");
  for (int i = 0; i < M_size; i++) M_data[i] += vec.M_data[i];
  return *this;
}

// Unary Operator "-=" overload - Usage: V -= W
Vector& Vector::operator-=(const Vector& vec) {
  if (M_size != vec.M_size) error("Bad vector sizes in Vector::operator-=()");
  for (int i = 0; i < M_size; i++) M_data[i] -= vec.M_data[i];
  return *this;
}
