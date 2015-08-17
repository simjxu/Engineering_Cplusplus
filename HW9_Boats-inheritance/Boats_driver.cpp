#include <iostream> 
#include <iomanip> 

using namespace std;

#include "boats.h"

int main ()
{
	Barge A;
	Sailboat B;
	
	// Set formatting of floating point numbers.
	cout << setiosflags (ios::fixed | ios::showpoint) << setprecision(2);

	cin >> A;	// does everything in the istream& operator
	cout << A ;   // does everything in the ostream& operator

	cout << endl;

	cin >> B;
	cout << B;
	
	return 0;
}