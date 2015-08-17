/* 
Cylinder Header File
*/

#include <iostream>
using namespace std;

// Only need to state PI once, in Sphere and Cone we will eliminate
const double PI = 3.1415926535898;

// Declaration of Cylinder class -------------------------------------------------- //
class Cylinder
{
// All data members are private
private:
	// Data Members
	double height;
	double radius;

// Only the methods and functions are public
public:
	// Constructor (must be public)
	Cylinder(double H = -1, double R = -1) 
	{height = H; radius = R;}

	// Mutator Method
	void setHeight(double H) {height = H;}
	void setRadius(double R) {radius = R;}

// Set Friends (Access)
friend double SurfaceArea(const Cylinder &);
friend double Volume(const Cylinder &);
friend ostream& operator<< (ostream&,const Cylinder &);
};

/* Function SurfaceArea ---------------------------------------------------------------- */
	double SurfaceArea(const Cylinder &C)
	{
		// Return Answer
		return 2.0 * PI * C.radius * C.height + 2.0 * PI * C.radius * C.radius;
	}
/* Function SurfaceArea ---------------------------------------------------------------- */

/* Function Volume --------------------------------------------------------------------- */
	double Volume(const Cylinder &C)
	{
		// Return Answer
		return C.height * PI * C.radius * C.radius;
	}
/* Function Volume --------------------------------------------------------------------- */

// Output 
ostream& operator<< (ostream& Out, const Cylinder & C)
{
	Out << "The cylinder volume is " << Volume(C) << endl;
	Out << "The cylinder surface area is " << SurfaceArea(C) << endl;
	Out << "CYLINDER: " << C.height << ", " << C.radius << endl;
	return Out;
}