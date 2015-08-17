// Using Class Inheritance to calculate Boat values

#include<iostream>
using namespace std;

// Class Ship (BASE)
class Ship
{
protected: // Needs to be "protected" if you want others to inherit
	// Ship data members
	double Lpp; // length between the perpendiculars (m)
	double B; // beam (m)
	double T; // draft (m)
	double L; // length (m)
	double D; // depth (m)
	double V; // volume of water displaced by the hull (m^3)
	double Cb; // block coefficient

public:
	// Constructor
	Ship(){Lpp = -1; B = -1; T = -1; L = -1; D = -1; V = -1; Cb = -1;}

	// Accessors
	double getLpp()const{return Lpp;}
	double getB()const{return B;}
	double getT()const{return T;}
	double getL()const{return L;}
	double getD()const{return D;}
	double getV()const{return V;}
	double getCb()const{return Cb;}

	// Mutators
	void setLpp(double lengthpp){Lpp = lengthpp;}
	void setB(double beam){B = beam;}
	void setT(double draft){T = draft;}
	void setL(double length){L = length;}
	void setD(double depth){D = depth;}
	void setV(double volume){V = volume;}
	void setCb(double coef){Cb = coef;}

	// Block coefficient Function Prototype
friend void Compute_Block_Coefficient(Ship S)
{
	S.Cb = (S.V/(S.Lpp*S.B*S.T));
}

//friend prototype overloaded output/input operator
friend istream& operator>> (istream&,Ship&);
friend ostream& operator<< (ostream&,const Ship&);
};

///* Function Compute Block Coefficient */
//void Compute_Block_Coefficient(Ship& S)
//{
//	S.setCb(S.getV()/(S.Lpp()*S.getB()*S.getT()));
//}
/* Function Compute Block Coefficient */

// Input/Output (istream and ostream)
istream& operator>> (istream& In, Ship& S)
{
	cout << "Enter the length between perpendiculars of the hull >>> ";
	In >> S.Lpp;
	cout << "Enter the total length of the hull >>> ";
	In >> S.L;
	cout << "Enter the beam of the hull >>> ";
	In >> S.B;
	cout << "Enter the draft of the hull >>> ";
	In >> S.T;
	cout << "Enter the depth of the hull >>> ";
	In >> S.D;
	cout << "Enter the volume of water displaced by the hull >>> ";
	In >> S.V;

	// Calculate the block coefficient
	Compute_Block_Coefficient(S);

	return In;
}

ostream& operator<< (ostream& Out, const Ship& S)
{
	Out << "The length of the ship is " << S.L << " meters." << endl;
	Out << "The breadth of the ship is " << S.B << " meters." << endl;
	Out << "The block coefficient of the ship is " << S.Cb << "." << endl;
	return Out;
}

// Class Barge (inherits Ship)
class Barge : public Ship
{
private:
	double craneheight;
public:
	// Constructor
	Barge() {craneheight = -1.0;}
	//double getCraneHeight()const {return craneheight;}
	//void setCraneHeight(double Ch){craneheight = Ch;}
friend istream& operator>> (istream&, Barge&);
friend ostream& operator<< (ostream&,const Barge&);
};

ostream& operator<< (ostream& Out, const Barge& B)
{
	Out << endl << "The height of the barge above the waterline including the crane is " <<
		 B.craneheight + (B.D - B.T) << " meters." << endl;
	Out << static_cast<Ship> (B);
	return Out;
}

istream& operator>> (istream& In, Barge& B) // NO CONST
{
	//  Make sure the tallest sail line comes before the Ship values
	cout << "Enter the height of the crane on the barge >>> ";
	In >> B.craneheight;
	Ship S;
	In >> S; // calls out the values for istream in Ship
	B.setLpp(S.getLpp()); B.setB(S.getB()); B.setT(S.getT()); B.setL(S.getL());
	B.setD(S.getD()); B.setV(S.getV()); B.setCb(S.getCb());
	return In;
}

// Class Sailboat (inherits Ship)
class Sailboat : public Ship
{
private:
	double sailheight;
public:
	// Constructor
	Sailboat() {sailheight = -1.0;}
	double getSailHeight()const {return sailheight;}
	void setSailHeight(double Ch){sailheight = Ch;}
friend ostream& operator<< (ostream&,const Sailboat&);
friend istream& operator>> (istream&, Sailboat&);
};

ostream& operator<< (ostream& Out, const Sailboat& Sa)
{
	Out << endl << "The height of the sailboat above the waterline including the sail is " <<
		 Sa.sailheight + (Sa.D - Sa.T) << " meters." << endl;
	Out << static_cast<Ship> (Sa);
	return Out;
}

istream& operator>> (istream& In, Sailboat& Sa) // NO CONST
{
	//  Make sure the tallest sail line comes before the Ship values
	cout << "Enter the height of the tallest sail on the sailboat >>> ";
	In >> Sa.sailheight;
	Ship S;
	In >> S; // calls out the values for istream in Ship
	Sa.setLpp(S.getLpp()); Sa.setB(S.getB()); Sa.setT(S.getT()); Sa.setL(S.getL());
	Sa.setD(S.getD()); Sa.setV(S.getV()); Sa.setCb(S.getCb());
	return In;
}
