#include <iostream>
#include <cmath>
#include <iomanip>
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
	Cylinder(double R = -1, double H = -1) 
	{radius = R; height = H;}

	// Mutator Method
	void setHeight(double H) {height = H;}
	void setRadius(double R) {radius = R;}

// Set Friends (this is in place of using an accessor)
friend double surface_area(const Cylinder &);
friend double volume(const Cylinder &);
friend ostream& operator<< (ostream&,const Cylinder &);
};

/* Function SurfaceArea ---------------------------------------------------------------- */
	double surface_area(const Cylinder &C)
	{
		// Return Answer
		return 2.0 * PI * C.radius * C.height + 2.0 * PI * C.radius * C.radius;
	}
/* Function SurfaceArea ---------------------------------------------------------------- */

/* Function Volume --------------------------------------------------------------------- */
	double volume(const Cylinder &C)
	{
		// Return Answer
		return C.height * PI * C.radius * C.radius;
	}
/* Function Volume --------------------------------------------------------------------- */

// Output 
ostream& operator<< (ostream& Out, const Cylinder & C)
{
	Out << "CYLINDER: " << C.height << ", " << C.radius << endl;
	return Out;
}

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
friend double surface_area(const Sphere &);
friend double volume(const Sphere &);
friend ostream& operator<< (ostream&,const Sphere &);
};

/* Function SurfaceArea ---------------------------------------------------------------- */
	double surface_area(const Sphere &S)
	{
		// Return Answer
		return 4.0 * PI * S.radius * S.radius;
	}
/* Function SurfaceArea ---------------------------------------------------------------- */

/* Function Volume --------------------------------------------------------------------- */
	double volume(const Sphere &S)
	{
		// Return Answer
		return 4.0/3.0 * PI * S.radius * S.radius * S.radius;
	}
/* Function Volume --------------------------------------------------------------------- */

// Output 
ostream& operator<< (ostream& Out, const Sphere & S)
{
	Out << "SPHERE: " << S.radius << endl;
	return Out;
}

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
friend double surface_area(const Prism &);
friend double volume(const Prism &);
friend ostream& operator<< (ostream&,const Prism &);
};

/* Function SurfaceArea ---------------------------------------------------------------- */
	double surface_area(const Prism &P)
	{
		// Return Answer
		return 2.0 * P.length * P.height + 2.0 * P.height * P.width 
			+ 2.0 * P.width * P.length;
	}
/* Function SurfaceArea ---------------------------------------------------------------- */

/* Function Volume --------------------------------------------------------------------- */
	double volume(const Prism &P)
	{
		// Return Answer
		return P.length * P.height * P.width;
	}
/* Function Volume --------------------------------------------------------------------- */

// Output 
ostream& operator<< (ostream& Out, const Prism & P)
{
	Out << "PRISM: "<< P.length << ", " << P.height << ", " << P.width << endl;
	return Out;
}

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
	{radius = R; height = H;}

	// Mutator Method
	void setRadius(double R) {radius = R;}
	void setHeight(double H) {height = H;}

// Friends (Access)
friend double surface_area(const Cone &);
friend double volume(const Cone &);
friend ostream& operator<< (ostream&,const Cone &);
};

/* Function SurfaceArea ---------------------------------------------------------------- */
	double surface_area(const Cone &C)
	{
		// Return Answer
		return PI * C.radius * C.radius 
			+ PI * C.radius * sqrt(C.radius * C.radius + C.height * C.height);
	}
/* Function SurfaceArea ---------------------------------------------------------------- */

/* Function Volume --------------------------------------------------------------------- */
	double volume(const Cone &C)
	{
		// Return Answer
		return 1.0/3.0 * PI * C.radius * C.radius * C.height;
	}
/* Function Volume --------------------------------------------------------------------- */

// Output 
ostream& operator<< (ostream& Out, const Cone & C)
{
	Out << "CONE: " << C.height << ", " << C.radius << endl;
	return Out;
}

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
friend double surface_area(const Pyramid &);
friend double volume(const Pyramid &);
friend ostream& operator<< (ostream&,const Pyramid &);
};

/* Function SurfaceArea ---------------------------------------------------------------- */
double surface_area(const Pyramid &P)
{
	// Return Answer
	return P.side * P.side + 4.0 * 0.5 * P.side 
		* sqrt(P.height * P.height + 0.5 * P.side * 0.5 * P.side);
}

/* Function SurfaceArea ---------------------------------------------------------------- */

/* Function Volume --------------------------------------------------------------------- */
double volume(const Pyramid &P)
{
	// Return Answer
	return 1.0/3.0 * P.side * P.side * P.height;
}
/* Function Volume --------------------------------------------------------------------- */

// Output 
ostream& operator<< (ostream& Out, const Pyramid & P)
{
	Out << "PYRAMID: " << P.side << ", " << P.height << endl;
	return Out;
}
