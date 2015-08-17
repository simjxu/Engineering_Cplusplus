// Using Overloaded Operators 
// for fraction addition/subtraction/multipication/division/power.

#include<iostream>
#include<math.h>
using namespace std;

class Fraction
{
private:
	// Data Members
	double numerator;
	double denominator;


public:
	// Constructor
	Fraction(){numerator = 0; denominator = 0;}

	// Accessors
	double getNum()const{return numerator;}
	double getDen()const{return denominator;}

	// Mutators
	void setNum(double N){numerator = N;}
	void setDen(double D){denominator = D;}
	
	// Reduce to Improper Function Prototype
	void ReduceFract(Fraction F);

	//Friend Prototype overloaded output/input operators
friend istream& operator>> (istream&,Fraction&);
friend ostream& operator<< (ostream&,Fraction&);

	// Friend Prototype overloaded Math functions
friend Fraction operator+(Fraction A, Fraction B);
friend Fraction operator-(Fraction A, Fraction B);
friend Fraction operator*(Fraction A, Fraction B);
friend Fraction operator/(Fraction A, Fraction B);
friend Fraction operator^(Fraction A, int power);
};

/* START FUNCTION: Reduce improper fraction -------------------------- */
void ReduceFract(Fraction& F)
{
	if (F.getNum() == 0 || F.getDen() == 0)
	{
		F.setDen(1); // denominator = 1 to avoid errors
	}
	else
	{
		// Handle positive/negative signs
		int flag = 1;
		int tempN = (int) F.getNum(); // save temporary numerator
		int tempD = (int) F.getDen(); // save temporary denominator

		if (tempN < 0)
		{
			flag = -flag;
			tempN = -tempN;
		}
		if (tempD < 0)
		{
			flag = -flag;
			tempD = -tempD;
		}

		// Handle Greatest common divisor
		int GCD = tempN;
		int dummy = tempD;
		while (GCD != dummy)
		{
			if (GCD > dummy)
			{
				GCD = GCD - dummy;
			}
			else
			{
				dummy = dummy - GCD;
			}
		}
		tempN = flag * tempN/GCD;
		tempD = tempD/GCD;

		// Set new values
		F.setNum(tempN);
		F.setDen(tempD);
	}
}
/* END FUNCTION: Reduce improper fraction ------------------------------ */

/* START Input/Output Operators ---------------------------------------- */
istream& operator>> (istream& In, Fraction& F)
{
	char divisionsign; // We toss this value
	cout << "Enter a fraction in the form \"numerator/denominator\" >>> ";
	In >> F.numerator >> divisionsign >> F.denominator;

	// Reduce the fraction
	ReduceFract(F);

	return In;
}

ostream& operator<< (ostream& Out, Fraction& F)
{
	// Make Proper Fraction
	if (fabs(F.getNum()) < F.getDen()) // fabs computes absolute value
	{
		Out << F.getNum() << "/" << F.getDen();
	}
	else
	{
		// Put a whole number in the front
		int wholeno = (int)(F.getNum()/F.getDen());
		if (F.getNum() - wholeno*F.getDen() == 0)
		{
			Out << wholeno;
		}
		else
		{
			Out << wholeno << " " << fabs(F.getNum() - wholeno*F.getDen())
				<< "/" << F.getDen();
		}
	}

	return Out;
}
/* END Input/Output Operators ------------------------------------------ */

// Addition
Fraction operator+(Fraction A, Fraction B)
{
	Fraction C;

	// Set temporary Numerator/Denominator Values
	double tempAN = A.getNum();
	double tempAD = A.getDen();
	double tempBN = B.getNum();
	double tempBD = B.getDen();

	// Multiply A's numerator and denominator by B's denominator
	A.setNum(tempAN*tempBD);
	A.setDen(tempAD*tempBD);

	// Multiply B's numerator and denominator by A's denominator
	B.setNum(tempBN*tempAD);
	B.setDen(tempBD*tempAD);

	// Calculate Fraction Sum
	C.setNum(A.getNum()+B.getNum());
	C.setDen(A.getDen()); // Doesnt matter A or B, they both should
	                      // have the same denominator now.

	ReduceFract(C); // Reduce the improper fraction

	return C;
}

// Subtraction
Fraction operator-(Fraction A, Fraction B)
{
	Fraction C;

	// Set temporary Numerator/Denominator Values
	double tempAN = A.getNum();
	double tempAD = A.getDen();
	double tempBN = B.getNum();
	double tempBD = B.getDen();

	// Multiply A's numerator and denominator by B's denominator
	A.setNum(tempAN*tempBD);
	A.setDen(tempAD*tempBD);

	// Multiply B's numerator and denominator by A's denominator
	B.setNum(tempBN*tempAD);
	B.setDen(tempBD*tempAD);

	// Calculate Fraction Sum
	C.setNum(A.getNum()-B.getNum());
	C.setDen(A.getDen()); // Doesnt matter A or B, they both should
	                      // have the same denominator now.

	ReduceFract(C); // Reduce the improper fraction

	return C;
}

// Multiplication
Fraction operator*(Fraction A, Fraction B)
{
	Fraction C;

	C.setNum(A.getNum()*B.getNum());
	C.setDen(A.getDen()*B.getDen());

	ReduceFract(C); // Reduce the improper fraction

	return C;
}

// Division
Fraction operator/(Fraction A, Fraction B)
{
	Fraction C;

	C.setNum(A.getNum()*B.getDen());
	C.setDen(A.getDen()*B.getNum());
	
	ReduceFract(C); // Reduce the improper fraction

	return C;
}

// Power
Fraction operator^(Fraction A, int B)
{
	Fraction C;

	C.setNum(pow(A.getNum(), B));
	C.setDen(pow(A.getDen(), B));

	ReduceFract(C); // Reduce the improper fraction

	return C;
}
