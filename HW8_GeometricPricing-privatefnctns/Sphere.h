/* 
Sphere Header File
*/

#include <iostream>
using namespace std;

// Declaration of Sphere class -------------------------------------------------- //
class Sphere
{
// All data members are private
private:
	// Data Members
	double radius;

// Only the methods and functions are public
public:
	// Constructor (must be public)
	Sphere(double R = -1) 
	{radius = R;}

	// Mutator Method
	void setRadius(double R) {radius = R;}

// Friends (Access)
friend double SurfaceArea(const Sphere &);
friend double Volume(const Sphere &);
friend ostream& operator<< (ostream&,const Sphere &);
};

/* Function SurfaceArea ---------------------------------------------------------------- */
	double SurfaceArea(const Sphere &S)
	{
		// Return Answer
		return 4.0 * PI * S.radius * S.radius;
	}
/* Function SurfaceArea ---------------------------------------------------------------- */

/* Function Volume --------------------------------------------------------------------- */
	double Volume(const Sphere &S)
	{
		// Return Answer
		return 4.0/3.0 * PI * S.radius * S.radius * S.radius;
	}
/* Function Volume --------------------------------------------------------------------- */

// Output 
ostream& operator<< (ostream& Out, const Sphere & S)
{
	Out << "The sphere volume is " << Volume(S) << endl;
	Out << "The sphere surface area is " << SurfaceArea(S) << endl;
	Out << "SPHERE: " << S.radius << endl;
	return Out;
}