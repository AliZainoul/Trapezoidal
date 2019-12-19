#ifndef ERROR_H
#define ERROR_H
#include <iostream>
using namespace std;
// Report error and exit with return value 1.
void error(const string& t, ostream& s = cout);
#endif
