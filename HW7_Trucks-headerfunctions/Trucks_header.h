/* 
Using Header Files: Calculating Number of Trucks Necessary  
*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Declaration of TruckLoad class
class TruckLoad
{
// All data members are private
private:
	// Data Members
	double length, width, height, weight;

// Only the methods and functions are public
public:
	// Constructor (must be public)
	TruckLoad(double L, double W, double H, double M) 
	{length = L; width = W; height = H; weight = M;}

	// Accessor Methods
	double getLength()const {return length;}
	double getWidth()const {return width;}
	double getHeight()const {return height;}
	double getWeight()const {return weight;}

/* Function NumBox ---------------------------------------------------------------- */
	int NumBox(double length_box)
	{
		// Calculate the integer number of boxes (truncated).
		int lengthFit, widthFit, heightFit;
		lengthFit = (int) (getLength()/length_box);
		widthFit = (int) (getWidth()/length_box);
		heightFit = (int) (getHeight()/length_box);

		// Return Answer
		return lengthFit * widthFit * heightFit;
	}
/* Function NumBox ----------------------------------------------------------------- */


/* Function NumTruck --------------------------------------------------------------- */
	int NumTruck(int number_boxes, double length_box, double weight_box)
	{
		int boxesleft(number_boxes); // Number of boxes, if = 0, means we're done.
		int count(0); // Counts the number of trucks that we need.

		// Calculate how many boxes can fit (not counting weight)
		int numberFit = NumBox(length_box);

		// 
		while (boxesleft > 0)
		{
			// Check to see if weight is too much for the truck
			if (numberFit * weight_box > getWeight())
			{
				int num = (int) (getWeight()/weight_box);
				count++; // One more truck needed
				boxesleft = boxesleft - num; // subtract out boxes from filled truck
			}
			// Else we have a "full" truck, with the max that can fit
			else
			{
				count++; // One more truck needed
				boxesleft = boxesleft - numberFit; // Fit total number of boxes
			}
		}
		return count; // count is the number of trucks
	}
/* Function NumTruck --------------------------------------------------------------- */

};
