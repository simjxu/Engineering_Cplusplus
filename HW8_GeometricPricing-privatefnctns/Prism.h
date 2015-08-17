/* 
Prism Header File
*/

#include <iostream>
using namespace std;

// Declaration of Prism class -------------------------------------------------- //
class Prism
{
// All data members are private
private:
	// Data Members
	double length, height, width;

// Only the methods and functions are public
public:
	// Constructor (must be public)
	Prism(double L = -1, double H = -1, double W = -1) 
	{length = L; height = H; width = W;}

	// Mutator Method
	void setLength(double L) {length = L;}
	void setHeight(double H) {height = H;}
	void setWidth(double W) {width = W;}

// Friends (Access)
friend double SurfaceArea(const Prism &);
friend double Volume(const Prism &);
friend ostream& operator<< (ostream&,const Prism &);
};

/* Function SurfaceArea ---------------------------------------------------------------- */
	double SurfaceArea(const Prism &P)
	{
		// Return Answer
		return 2.0 * P.length * P.height + 2.0 * P.height * P.width 
			+ 2.0 * P.width * P.length;
	}
/* Function SurfaceArea ---------------------------------------------------------------- */

/* Function Volume --------------------------------------------------------------------- */
	double Volume(const Prism &P)
	{
		// Return Answer
		return P.length * P.height * P.width;
	}
/* Function Volume --------------------------------------------------------------------- */

// Output 
ostream& operator<< (ostream& Out, const Prism & P)
{
	Out << "The prism volume is " << Volume(P) << endl;
	Out << "The prism surface area is " << SurfaceArea(P) << endl;
	Out << "PRISM: "<< P.length << ", " << P.height << ", " << P.width << endl;
	return Out;
}