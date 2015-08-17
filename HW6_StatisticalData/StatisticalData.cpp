/* Statistical Analysis: this program will take a data set and compute:
   - Arithmetic Mean
   - Root-mean square average
   - Maximum surface height
   - Standard deviation                                                    */

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Function Prototypes
int Count(ifstream&);                              // counts datafile
double Mean(ifstream&, int count);                 // calculates arithmetic mean
double RMS(ifstream&, int count);                  // calculates root mean square
double Max(ifstream&);                             // calculates max surface height
double SD(ifstream&, double ArithMean, int count); // calculates standard deviation

int main()
{
	int datacount;
	double ArithMean, RootMeanSquare, MaxSurfHeight, StandardDev;

	// Get data from surface.dat file
	ifstream Input("surface.dat",ios::in);

	// Count values in the data file
	datacount = Count(Input);

	// Compute values for the data file
	ArithMean = Mean(Input, datacount);
	RootMeanSquare = RMS(Input, datacount);
	MaxSurfHeight = Max(Input);
	StandardDev = SD(Input, ArithMean, datacount);

	// Set Precision
	cout.setf(ios::fixed); // display decimal notation
	cout.precision(2); // display 2 digit to right of decimal

	// Output solution
	cout << "Arithmetic Mean Value:       " << ArithMean << endl;
	cout << "Root-Mean-Square Average:    " << RootMeanSquare << endl;
	cout << "Maximum roughness Height:   " << MaxSurfHeight << endl;
	cout << "Standard Deviation:          " << StandardDev << endl;

	return 0;
}

/*---------------------------------------------------------------------------------*/
/*FUNCTIONS*/

// Counts the number of pieces of data in the file.
int Count(ifstream& Loc)
{
	// Loc refers to the location of the data in memory
	Loc.clear(); // Clear eof flag
	Loc.seekg(0); // Rewind file to its beginning
	int count = 0;
	double data;
	for (Loc >> data; !Loc.eof(); Loc >> data)
	{
		count++;
	}
	return count;
}

// Finds Arithmetic mean
double Mean(ifstream& Loc, int count)
{
	double Sum(0); // Total sum

	// Loc refers to the location of the data in memory
	Loc.clear(); // Clear eof flag
	Loc.seekg(0); // Rewind file to its beginning

	double data;
	for (Loc >> data; !Loc.eof(); Loc >> data)
	{
		Sum = Sum + fabs(data);
	}
	return Sum/count;
}

// Finds Root Mean Square
double RMS(ifstream& Loc, int count)
{
	double squareSum(0); // Squared sum

	Loc.clear(); // Clear eof flag
	Loc.seekg(0); // Rewind file to its beginning
	
	double data;
	for (Loc >> data; !Loc.eof(); Loc >> data)
	{
		squareSum = squareSum + pow(fabs(data),2);
	}
	return sqrt(squareSum/count);
}

// Finds Maximum Surface Height
double Max(ifstream& Loc)
{
	double MaxValue(0); // The max positive value
	double MinValue(0); // The min negative value

	Loc.clear(); // Clear eof flag
	Loc.seekg(0); // Rewind file to its beginning
	
	double data;
	for (Loc >> data; !Loc.eof(); Loc >> data)
	{
		if (data > MaxValue)
		{
			MaxValue = data;
		}
		if (data < MinValue)
		{
			MinValue = data;
		}
	}
	return MaxValue-MinValue;
}

// Finds StandardDeviation
double SD(ifstream& Loc, double Mean, int count)
{
	double Variance(0); // Variance, which will be summed

	Loc.clear(); // Clear eof flag
	Loc.seekg(0); // Rewind file to its beginning
	
	double data;
	for (Loc >> data; !Loc.eof(); Loc >> data)
	{
		Variance = Variance + pow((fabs(data)-Mean),2)/(count-1);
	}
	return sqrt(Variance); // STD = square root of variance
}

/*---------------------------------------------------------------------------------*/
