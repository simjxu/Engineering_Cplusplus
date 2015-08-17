////////////////////////////////////////////////////////////////
// Engineering Problem                                        // 
// Solving with C++                                           //
////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>

using namespace std;

#include "Trucks_header.h"

int main()
{
	// Create objects and variables
	TruckLoad small(10,6,5,10000); // inputs are truck length, 
								   // width, height and payload 
								   // weight
	TruckLoad midsize(12,8,8,40000);
	TruckLoad large(20,8,10,80000);
	int number_boxes;
	double length_box, weight_box;

	// Input manufacturer's requirements
	cout << "How many boxes are being shipped? >>> ";
	cin >> number_boxes;
	cout << "What is the side length (in feet) of the box type being shipped? >>> ";
	cin >> length_box;
	cout << "What is the weight (in pounds) of the box type being shipped? >>> ";
	cin >> weight_box;

	// Determine the number of boxes that fit on a truck
	int number_per_small_truck = small.NumBox(length_box);
	int number_per_midsize_truck = midsize.NumBox(length_box);
	int number_per_large_truck = large.NumBox(length_box);

	// Output results
	cout << endl;
	cout << number_per_small_truck << " boxes will fit in one of our small trucks." << endl;
	cout << number_per_midsize_truck << " boxes will fit in one of our midsize trucks." << endl;
	cout << number_per_large_truck << " boxes will fit in one of our large trucks." << endl;

	// Determine the number of trucks needed to ship the boxes
	int number_small_trucks = small.NumTruck(number_boxes, length_box, weight_box);
	int number_midsize_trucks = midsize.NumTruck(number_boxes, length_box, weight_box);
	int number_large_trucks = large.NumTruck(number_boxes, length_box, weight_box);

	// Output results
	cout << endl;
	cout << "Considering weight restrictions, you will need " 
		<< number_small_trucks << " of our small trucks or " 
		<< number_midsize_trucks << " of our midsize trucks or " 
		<< number_large_trucks 
		<< " of our large trucks to ship your product." << endl;

	// Exit program	
	return 0;
}
