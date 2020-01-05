#include <iostream>
using namespace std;
// Report error and exit with return value 1.
void error(const string& t, ostream& s = cout) {
//template<class T> void error(const T& t) {
  cout << t << ". program exited." << "\n";
  exit(1);
}
