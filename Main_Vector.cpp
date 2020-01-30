#include <iostream>
#include "Vector.hpp"
using namespace std;

// La fonction fill() est sujette au "Copy Elision"
Vector fill(){
	Vector vec={8,8,8,8};
	return vec;
}
// La fonction change() n'est pas sujette au "Copy Elision"
//  (il est interdit au compilateur
//  d'éluder la copie d'un argument passé par valeur
//  vers un objet temporaire en return)
Vector change(Vector tmp){
	tmp[3]=500;
	return tmp;
}

int main()
{
  Vector v3(4,1);
  Vector v4={-4.3,4.5,-4.6,-4.7};
  Vector v5(5,5);

  // Initialisation ==> Copy Constructor
  cout<< "Test of Constructor "<<endl;
  Vector w1{v3};
  cout << w1;
	cout << "Size of the vector : " << w1.size()<<endl;
  cout << "L2-Norm of the vector : "<< w1.twonorm()<<endl;
	cout << "Linfinity-Norm of the vector : "<< w1.maxnorm()<<endl;
  cout<< "                        "<<endl;
	Vector pihg = v4;
	cout << "**************************************" << endl;
	cout << pihg << endl;
	double doot = dot(v4,pihg);
	cout << doot << endl;
	cout << v4.twonorm()*v4.twonorm()<<endl;
	cout << "**************************************" << endl;

	cout << "**************************************" << endl;
	cout << "v3" << v3;
	Vector zero = v3 - v3;
	cout << "duble" << zero;
	Vector duble = v3 + v3;
	double lambda = 10;
	cout << "lambda" << lambda;
	Vector lambdaR =  v3*lambda;
	cout << "v3" << lambdaR;
	Vector lambdaL =  lambda * v3;
	cout << "v3" << lambdaL;
	cout << "**************************************" << endl;

	/*cout<< "Test of Constructor "<<endl;
	w1.reset(1.1);
	cout << "Size of the vector : " << w1.size()<<endl;
	cout << "L2-Norm of the vector : "<< w1.twonorm()<<endl;
	cout << "Linfinity-Norm of the vector : "<< w1.maxnorm()<<endl;
	cout<< "                        "<<endl;*/

  // Affectation ==> Copy Assignment
  cout<< "Test Copy Assignment "<<endl;
  Vector w1b(4);
  w1b = v4;
  cout << w1b;
	cout << "Size of the vector : " << w1b.size()<<endl;
  cout << "L2-Norm of the vector : "<< w1b.twonorm()<<endl;
	cout << "Linfinity-Norm of the vector : "<< w1b.maxnorm()<<endl;
  cout<< "                        "<<endl;

  // Initialisation ==> Copy constructor
  cout<< "Test Copy Constructor"<<endl;
  Vector w2(v3);
  cout << w2;
	cout << "Size of the vector : " << w2.size()<<endl;
  cout << "L2-Norm of the vector : "<< w2.twonorm()<<endl;
	cout << "Linfinity-Norm of the vector : "<< w2.maxnorm()<<endl;
  cout<< "                        "<<endl;


  // Initialisation
  // le constructeur de copy n'est pas appelé
  // c'est une initialisation !
	cout<< "Test Copy Constructor"<<endl;
  Vector v6=Vector(6,6);
  cout << v6;
  //cout<< "copy elision !"<<endl;
	cout << "Size of the vector : " << v6.size()<<endl;
  cout << "L2-Norm of the vector : "<< v6.twonorm()<<endl;
	cout << "Linfinity-Norm of the vector : "<< v6.maxnorm()<<endl;
  cout<< "                        "<<endl;

	// le constructeur de copie n'est pas appelé car le vecteur issu de fill ne sera jamais utilisé "seul"
	cout<< "Test Copy Constructor "<<endl;
	Vector v7=fill();
	cout << v7;
	//cout<< "copy elision !"<<endl;
	cout << "Size of the vector : " << v7.size()<<endl;
  cout << "L2-Norm of the vector : "<< v7.twonorm()<<endl;
	cout << "Linfinity-Norm of the vector : "<< v7.maxnorm()<<endl;
	cout<< "                        "<<endl;


  // Affectation ==> move assignment car Vector(6,6) ne sera jamais utilisé "seul"
  cout<< "Test Copy/Move Constructor "<<endl;
  Vector v6b(6);
  v6b = Vector(6,6);
  cout << v6b;
	cout << "Size of the vector : " << v6b.size()<<endl;
  cout << "L2-Norm of the vector : "<< v6b.twonorm()<<endl;
	cout << "Linfinity-Norm of the vector : "<< v6b.maxnorm()<<endl;
  cout<< "                        "<<endl;

  cout<< "Test Copy Constructor"<<endl;
	Vector w3=v5;
	cout << w3;
 	cout << "Size of the vector : " << w3.size()<<endl;
 	cout << "L2-Norm of the vector : "<< w3.twonorm()<<endl;
	cout << "Linfinity-Norm of the vector : "<< w3.maxnorm()<<endl;
	cout<< "pas d'appel de l'opÃ©rateur d'assignement car initialisation!"<<endl;
	cout<< "                        "<<endl;

  cout<< "Test Move Constructor"<<endl;
  Vector v8(8,8);
  Vector v8b=change(v8);
  cout << v8b;
  // cout<< "Maintenant, move constructor est appelé automatiquement"<<endl;
	cout << "Size of the vector : " << v8b.size()<<endl;
  cout << "L2-Norm of the vector : "<< v8b.twonorm()<<endl;
	cout << "Linfinity-Norm of the vector : "<< v8b.maxnorm()<<endl;
  cout<< "                        "<<endl;

  cout<< "Test Move Assignment"<<endl;
  Vector v9(9,9);
  cout << v9 << endl;
	cout << "Size of the vector : " << v9.size()<<endl;
	cout << "L2-Norm of the vector : "<< v9.twonorm()<<endl;
	cout << "Linfinity-Norm of the vector : "<< v9.maxnorm()<<endl;

  v9 = fill();
  cout << v9 << endl;
	cout << "Size of the vector : " << v9.size()<<endl;
  cout << "L2-Norm of the vector : "<< v9.twonorm()<<endl;
	cout << "Linfinity-Norm of the vector : "<< v9.maxnorm()<<endl;
  // cout<< "move assignment est appelé automatiquement"<<endl;
  // cout<< "car il s'agit d'une affectation et non initialisation"<<endl;
  cout<< "                        "<<endl;

}
