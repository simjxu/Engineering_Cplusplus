// Using Arrays to define Project Tasks

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


const int N=10; // initialize Number of rows, columns to 10
int events; // this will keep the number of events there are

// Function Prototype Min Time
int CalcMin(int x[][N],int a,int b); // Time is in integer hours

int main()
{
	// Get data from duration.dat file
	ifstream Input("duration.dat",ios::in);

	int DoubleArray[N][N]; // Initialize 10x10 array

	cout << "Enter the number of events in the project >>> ";
	cin >> events;

	// Plug in values to DoubleArray
	for (int i=0; i<events; i++)
	{
		for (int j=0; j<events; j++)
		{
			// Plugin Zeros (for diagonal, or if row # is larger than col #
			if (i == j || i > j)
			{
				DoubleArray[i][j] = 0;
			}
			else
			{
				// Input into array
				Input >> DoubleArray[i][j];
			}
		}
	}

	cout << "The minimum time to complete this project is " 
		<< CalcMin(DoubleArray,0,events-1) << " hours." << endl; // Remember event 1 is at 0.
	
	// Calculate the time before a certain event happens.
	int A,B;
	char dash;	

	cout << "Enter the activity number you wish to report on in the format \"i-j\" >>> ";
	cin >> A >> dash >> B;
	cout << "The earliest time that activity " << A << "-" << B <<
		" can be begun is " << CalcMin(DoubleArray,0,A-1) << //
		" hours after the start of the project." << endl;

	return 0;
}


/*---------------------------------------------------------------------------------*/
/*FUNCTIONS*/
int CalcMin(int x[][N],int a,int b)
{
	int Max = 0; // Set uninitialized minimum to 0, will check later
	for (int c = a+1; c <= b; c++)
	{
		int i = a; int Tot = 0;
		int j = c;

		while (j <= b)
		{
			// Condition: The nodes i-j don't connect
			if (x[i][j] == 0)
			{
				if (j == b)
				{
					Tot = 0;
				}
			}
			// Otherwise add the time in the node
			else
			{
				Tot += x[i][j];
				i = j;
			}
			j++;
		}
		// Enter new minimum, if Tot is smaller, or if Min is uninitialized.
		if (Tot != 0 && Tot > Max || Max == 0)
		{
			Max = Tot;
		}
	}
	return Max;
}
