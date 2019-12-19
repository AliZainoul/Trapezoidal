#include <iostream>
#include <cmath>
#include "Vector.hpp"
#include "error.hpp"
using namespace std;
// Constructor 0 : Default Constructor
// Constructor 1 : Test Constructor
/*Vector::Vector(int i){
	M_data = new double[i];
	M_size = i;
	cout << "HOLA JE SUIS Constructeur 1: allocation du tableau: "<<M_data<<"\n";
    for(int k=0;k<M_size;++k){
			M_data[k]=0;
		}
}*/
// Constructor 2 : Original Constructor Example: Vector v(2,3) => v = (3;3)
Vector::Vector(int i, double v){
	M_data = new double[i];
	M_size = i;
	cout << "Constructeur 2: allocation du vecteur: "<<M_data<<"\n";
    for(int k=0;k<M_size;++k){
			M_data[k]=v;
		}
}
// Constructor 3 : List Constructor - Example:
Vector::Vector(initializer_list<double> lst){
	M_data = new double[lst.size()];
	M_size = static_cast<int>(lst.size());
	cout << "Constructeur 3: allocation du vecteur: "<<M_data<<"\n";
 	std::copy(lst.begin(), lst.end(), M_data);
}
//  Constructor 4 : Copy Constructor - Example :
Vector::Vector(Vector const &v){
	v.M_size==0? M_data = nullptr : M_data = new double[v.M_size];
	M_size = v.M_size;
	cout << "Copy constructor: allocation du vecteur: "<<M_data<<" de taille "<<M_size<<"\n";
	for (int k=0;k<M_size;++k) M_data[k] = v.M_data[k];
}
// Constructor 5 : Move Constructor - Example:
Vector::Vector(Vector&& v){
	M_data=v.M_data;
	M_size=v.M_size;
	cout << "Move du vecteur"<<v.M_data<<" via move constructeur"<<"\n";
	v.M_size = 0;
	v.M_data = nullptr;
}

// Constructor 6 : Assignment Operator
Vector& Vector::operator=(Vector const &v){
  if (this != &v){
	  delete[] M_data;
	  M_data = new double[M_size=v.M_size];
	  cout << "Assign du vecteur: "<<v.M_data<<"\n";
	  for(int k=0;k<M_size;++k) M_data[k]=v.M_data[k];
  }
  return *this;
}
// Constructor 6 - Move Assignment Operator - Usage:
Vector& Vector::operator=(Vector&& v){
	cout << "Move du vecteur"<<v.M_data<<" via move assignment"<<"\n";
	delete[] M_data;
	M_data = v.M_data;
	M_size = v.M_size;
	v.M_data = nullptr;
	v.M_size = 0;
	return *this;
}
// Destructor
Vector::~Vector(){
	cout << "Destruction du vecteur: "<<M_data<<"\n";
	delete[] M_data;
}

// Show Function
void Vector::affiche(){
  std::cout << "Taille du vecteur: "<< M_size<< "\n";
  for(int i=0; i<M_size; i++) cout<<i<<" "<<M_data[i]<<endl;
}


// Surcharge Of Operator 'Outstream'
std::ostream& operator << (std::ostream& s, const Vector& v){
  using std::endl;
  s << "Surcharge opérateur: taille du vecteur: " << v.M_size << endl;
  for (int i = 0; i < v.M_size; i++){
    s << i+1 << " " << v.M_data[i] << endl;
  }
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
    for (int i = 0; i < M_size; i++)
    two_norm += pow(M_data[i],2);
    return sqrt(two_norm);
};

// Dot Operator
double dot(const Vector& v1, const Vector& v2) {
  if (v1.M_size != v2.M_size ) error("bad vector sizes in dot product");
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

// Unary Operator Surcharge, usage: V = +W;
Vector operator+(const Vector& vec) {
  return vec;
}
// Unary Operator Surcharge, usage: V = -W;
Vector operator-(const Vector& vec) {
  Vector minus = vec;
  for (int i = 0; i < vec.M_size; i++) minus[i] = - vec[i];
  return minus;
}

// Binary Operator Surcharge, usage: V = V1 + V2
Vector operator+(const Vector& v1, const Vector& v2) {
  if (v1.M_size != v2.M_size ) error("Bad vector sizes in vector addition.");
  Vector sum = v1;
  sum += v2;
  return sum;
}
// Binary Operator Surcharge, usage: V = V1 - V2
Vector operator-(const Vector& v1, const Vector & v2) {
  if (v1.M_size != v2.M_size ) error("Bad vector sizes in vector subtraction.");
  Vector sum = v1;           // It would cause problem without copy constructor
  sum -= v2;
  return sum;
}

// Unary Operator Surcharge, usage: V += W
Vector& Vector::operator+=(const Vector& vec) {
  if (M_size != vec.M_size) error("Bad vector sizes in Vcr::operator+=()");
  for (int i = 0; i < M_size; i++) M_data[i] += vec.M_data[i];
  return *this;
}
// Unary Operator Surcharge, usage: V -= W
Vector& Vector::operator-=(const Vector& vec) {
  if (M_size != vec.M_size) error("bad vector sizes in Vcr::operator-=()");
  for (int i = 0; i < M_size; i++) M_data[i] -= vec.M_data[i];
  return *this;
}
