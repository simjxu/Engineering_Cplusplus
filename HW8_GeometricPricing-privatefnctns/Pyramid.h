/* 
Pyramid Header File
*/

#include <iostream>
#include <cmath>
using namespace std;

// Declaration of Pyramid class -------------------------------------------------- //
class Pyramid
{
// All data members are private
private:
	// Data Members
	double side, height;

// Only the methods and functions are public
public:
	// Constructor (must be public)
	Pyramid(double S = -1, double H = -1) 
	{side = S; height = H;}

	// Mutator Method
	void setSide(double S) {side = S;}
	void setHeight(double H) {height = H;}

// Friends (Access)
friend double SurfaceArea(const Pyramid &);
friend double Volume(const Pyramid &);
friend ostream& operator<< (ostream&,const Pyramid &);
};

/* Function SurfaceArea ---------------------------------------------------------------- */
double SurfaceArea(const Pyramid &P)
{
	// Return Answer
	return P.side * P.side + 4.0 * 0.5 * P.side 
		* sqrt(P.height * P.height + 0.5 * P.side * 0.5 * P.side);
}

/* Function SurfaceArea ---------------------------------------------------------------- */

/* Function Volume --------------------------------------------------------------------- */
double Volume(const Pyramid &P)
{
	// Return Answer
	return 1.0/3.0 * P.side * P.side * P.height;
}
/* Function Volume --------------------------------------------------------------------- */

// Output 
ostream& operator<< (ostream& Out, const Pyramid & P)
{
	Out << "The pyramid volume is " << Volume(P) << endl;
	Out << "The pyramid surface area is " << SurfaceArea(P) << endl;
	Out << "PYRAMID: " << P.side << ", " << P.height << endl;
	return Out;
}