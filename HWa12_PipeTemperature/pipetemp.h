// Using Arrays to Calculate Pipe Temperatures

#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

const int maxFinHeight = 100;
const int maxFinWidth = 100;

class Steampipe
{
private:
	int height,width;
	double steamTemp;
public:
	Steampipe (int H = 0, int W = 0, double sT = 0.0)
	{
		height = H;
		width = W;
		steamTemp = sT;
	}

	// Access function definitions (get set privates)
	int getHeight()const{return height;}
	int getWidth()const{return width;}
	double getSteamT()const{return steamTemp;}
	void setHeight(int h){height = h;}
	void setWidth(int w){width = w;}
	void setSteamT(double st){steamTemp = st;}
};

class GridPt
{
private:
	double temperature;
	char symbol; // Either C,H,X
public:
	GridPt(double t = 0.0, char s = '?')
	{
		temperature = t;
		symbol = s;
	}

	// Access function definitions (get set privates)
	double getTemp()const{return temperature;}
	char getSymbol()const{return symbol;}
	void setTemp(double T){temperature = T;}
	void setSymbol(char S){symbol = S;}
};

class Fin
{
private:
	int width, height; //width and height of fin
	int pipeLocationX, pipeLocationY; //grid location of lower left corner of steampipe
	double boundaryTemp; //temperature of fin surroundings
	Steampipe Pipe; //steampipe object - COMPOSITION
	GridPt GridArray[maxFinHeight][maxFinWidth]; // array of GridPts - COMPOSITION
public:

	// Calculate the values of the Array
	void initialize()
		{
			for (int j=height-1; j>=0; j--)
			{
				for (int i=0; i<=width; i++)
				{
					// Set the border values to C
					if (i==0 || j==0 || i==width-1 || j==height-1)
					{
						GridArray[i][j].setSymbol('C');
					}
					else
					{
						// Set the Pipe area to H
						if (i >= pipeLocationX && j >= pipeLocationY 
							&& i < pipeLocationX + Pipe.getWidth() 
							&& j < pipeLocationY + Pipe.getHeight())
						{
							GridArray[i][j].setSymbol('H');
						}
						else
						{
							// Set the rest to X
							GridArray[i][j].setSymbol('X');
						}
					}
				}
			}
		}

friend istream& operator>>(istream& , Fin& ); // YOU MUST DEFINE
friend ostream& operator<<(ostream& , const Fin& ); // YOU MUST DEFINE
};

// Fin Overloaded Input/Output
istream& operator>> (istream& In, Fin& F)
{
	cout << "Enter the height of the fin (integer) >>> ";
	In >> F.height;
	cout << "Enter the width of the fin (integer) >>> ";
	In >> F.width;

	int A; char B;
	cout << "Enter the height of the steampipe (integer) >>> ";
	In >> A;
	F.Pipe.setHeight(A);
	cout << "Enter the width of the steampipe (integer) >>> ";
	In >> A;
	F.Pipe.setWidth(A);
	cout << "Enter integer coordinates of lower left corner of the steampipe (X,Y) >>> ";
	In >> F.pipeLocationX >> B >> F.pipeLocationY;
	cout << "Enter the steam temperature (floating point) >>> ";
	In >> A;
	F.Pipe.setSteamT(A);
	cout << "Enter the temperature around the fin (floating point) >>> ";
	In >> F.boundaryTemp;

	return In;
}

ostream& operator<< (ostream& Out, const Fin& F)
{
	Out << endl;
	Out << "The width of the fin is " << F.width << endl;
	Out << "The height of the fin is " << F.height<< endl;
	Out << "The outside temperature is " << F.boundaryTemp<< endl;
	Out << "The lower left corner of the steam pipe is at (" << F.pipeLocationX
		<< "," << F.pipeLocationY << ")"<< endl;
	Out << "The steam pipe width is " << F.Pipe.getWidth()<< endl;
	Out << "The steam pipe height is " << F.Pipe.getHeight()<< endl;
	Out << "The temperature of the steam is " << F.Pipe.getSteamT()<< endl;
	Out << endl;

	// Output the Array
	for (int j=F.height-1; j>=0; j--)
	{
		for (int i=0; i<F.width; i++)
		{
			Out << F.GridArray[i][j].getSymbol();
		}
		Out << endl;
	}

	// Calculate remaining output for the gridpoint
	int X,Y;
	char Z;
	Out << endl;
	Out << "Enter the coordinates of the gridpoint of interest (X,Y) >>> ";
	cin >> X >> Z >> Y;
	if (F.GridArray[X][Y].getSymbol() == 'H')
	{
		Out << F.Pipe.getSteamT();
	}
	if (F.GridArray[X][Y].getSymbol() == 'C')
	{
		Out << F.boundaryTemp;
	}
	else
	{
		Out << "The temperature at location (" << X 
			<< "," << Y << ") is " << (F.Pipe.getSteamT()+F.boundaryTemp)/2.0
			<< endl;
	}

	return Out;
}
