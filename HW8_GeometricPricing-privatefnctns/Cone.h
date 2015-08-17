/* 
Cone Header File
*/

#include <iostream>
#include <cmath>
using namespace std;

// Declaration of Cone class -------------------------------------------------- //
class Cone
{
// All data members are private
private:
	// Data Members
	double radius;
	double height;

// Only the methods and functions are public
public:
	// Constructor (must be public)
	Cone(double R = -1, double H = -1) 
	{radius = R;}

	// Mutator Method
	void setRadius(double R) {radius = R;}
	void setHeight(double H) {height = H;}

// Friends (Access)
friend double SurfaceArea(const Cone &);
friend double Volume(const Cone &);
friend ostream& operator<< (ostream&,const Cone &);
};

/* Function SurfaceArea ---------------------------------------------------------------- */
	double SurfaceArea(const Cone &C)
	{
		// Return Answer
		return PI * C.radius * C.radius 
			+ PI * C.radius * sqrt(C.radius * C.radius + C.height * C.height);
	}
/* Function SurfaceArea ---------------------------------------------------------------- */

/* Function Volume --------------------------------------------------------------------- */
	double Volume(const Cone &C)
	{
		// Return Answer
		return 1.0/3.0 * PI * C.radius * C.radius * C.height;
	}
/* Function Volume --------------------------------------------------------------------- */

// Output 
ostream& operator<< (ostream& Out, const Cone & C)
{
	Out << "The cone volume is " << Volume(C) << endl;
	Out << "The cone surface area is " << SurfaceArea(C) << endl;
	Out << "CONE: " << C.height << ", " << C.radius << endl;
	return Out;
}