#include "fractions.h"

int main()
{
	
	Fraction fract_1, fract_2;
	cin >> fract_1 >> fract_2;  // need an istream & operator to take values.

	int power;	
	cout << "Enter a positive integer power to raise the fraction to >>> ";
	cin >> power;

	cout << endl;
	cout << "The entered fraction, reduced is "<< fract_1 << endl 
		<< "The entered fraction, reduced is " << fract_2 << endl << endl;
	
	// addition
	Fraction fract_3 = fract_1 + fract_2;
	cout << "fraction 1 + fraction 2 = " << fract_3 << endl << endl;

	// subtraction
	fract_3 = fract_1 - fract_2;
	cout << "fraction 1 - fraction 2 = " << fract_3 << endl << endl;


	// multiplication
	fract_3 = fract_1 * fract_2;
	cout << "fraction 1 * fraction 2 = " << fract_3 << endl << endl;


	// division
	fract_3 = fract_1 / fract_2;
	cout << "fraction 1 / fraction 2 = " << fract_3 << endl << endl;

	// power
	fract_3 = fract_1 ^ power;
	cout << "fraction 1 ^ " << power << " = " << fract_3 << endl << endl;

	return 0;
}

