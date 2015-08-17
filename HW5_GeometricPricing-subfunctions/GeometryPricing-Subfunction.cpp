/* Calculating Geometry-based Pricing, using function to arrive at answer */

#include <iostream>
#include <cmath>
using namespace std;

// Function Prototype
void optimizeprism(double height, int volume);

// Declaration for "Price" Class. The prices are stored here.
class Price
{
public: // Public Interface

    double Prism, Pyr;
    Price()
    {
        Prism = 300;
        Pyr = 400;
    }
};

// Declaration for "Optimal" Class. The optimal lengths/widths are stored here.
class Optimal
{
public: // Public Interface
    double LengthPrism, WidthPrism, HeightPrism, Price;
    Optimal()
    {
        HeightPrism = 0;
		LengthPrism = 0;
		WidthPrism = 0;
        Price = 0;
    }
};

// Initialize Class Members
Price PriceX;
Optimal Cheapest;

int main()
{
	// Initialize the variables
	double prismHeightmin(0.0), prismHeightmax(0.0),          // user inputs
		FinalHeight(0.0), FinalLength(0.0), FinalWidth(0.0), 
		FinalCost(99999999999999);                            // final outputted answers 
	int volume;                                            // user input

    // Ask user for volume, store in "Volume" variable
    cout << "Enter the minimum prism height (decimal number, meters) >>> ";
    cin >> prismHeightmin;
    cout << "Enter the maximum prism height (decimal number, meters) >>> ";
    cin >> prismHeightmax;
    cout << "Enter the tank volume (integer, cubic meters) >>> ";
    cin >> volume;

	// Output Table, preceded by an empty line.
	cout << " " << endl;
    cout << "   Prism Height (m)   Prism Length (m)   Prism Width (m)   Minimum Cost ($)"
                    << endl;
    cout << "---------------------------------------------------------------------------"
                    << endl;

	// Loop through different heights (+0.1 meter per iteration)
	for (double height = prismHeightmin; 
		height <= prismHeightmax; height += 0.1)
	{
		optimizeprism(height, volume);

		cout.setf(ios::fixed); // display decimal notation

		cout.precision(1); // display 1 digit to right of decimal
		cout << "         " 
			<< Cheapest.HeightPrism << "              "
			<< Cheapest.LengthPrism << "              " 
			<< Cheapest.WidthPrism << "          " ;

		cout.precision(2); // display 2 digits to right of decimal
		cout << Cheapest.Price << endl;

		// Change the final output answers to new answer when it is minimum.
		if (Cheapest.Price < FinalCost)
		{
			FinalHeight = Cheapest.HeightPrism;
			FinalLength = Cheapest.LengthPrism;
			FinalWidth = Cheapest.WidthPrism;
			FinalCost = Cheapest.Price;
		}
	}

	// Display minimum cost, preceded by an empty line
	cout << " " << endl;
	cout << "The minimum cost is $" << FinalCost << "." << endl;

	// Display the dimensions, single signficant digit to right of decimal
	cout.precision(1); 
	cout << "It is achieved with a prism height of " << FinalHeight <<
		", a length of " << FinalLength << " and a width of " << endl;
	cout << FinalWidth << "." << endl;

    return 0;
}


/*--------------------------------------------------------------------------------------*/
/* This function evaluates the optimizeprism function.                                  */

void optimizeprism(double height, int volume)
{

	double PyrHeight(0), width(0), 
	SurfaceAreaPrism(0), SurfaceAreaPyr(0),
	Price1(0), Price2(0);

	// Set equal to a large number, to find optimal at each length.
	Cheapest.Price = 999999999.99;

	// Loop through different lengths (+0.1 meter per iteration)
	for (double length = 2.0; length <= 40.0; length += 0.1)
	{
		// Calculate pyramid values and Surface area
		PyrHeight = length/2;
		width = volume/(height*length+PyrHeight*length/3);
		SurfaceAreaPrism = 2*height*length+2*height*width+length*width;
		SurfaceAreaPyr = 2*sqrt((0.5*0.5*width*width+PyrHeight*PyrHeight))
						*0.5*length+ 2*sqrt((0.5*0.5*length*length+PyrHeight
						*PyrHeight))*0.5*width;

		// The Prism Pricing (varies depending on total surface area)
		if (SurfaceAreaPrism > 300)
		{
			if (SurfaceAreaPrism > 500)
			{
				Price1 = PriceX.Prism*(0.85)*(SurfaceAreaPrism-500)
								+ PriceX.Prism*(0.9*(200))
								+ PriceX.Prism*300;
			}
			else
				Price1 = PriceX.Prism*(0.9)*(SurfaceAreaPrism-300)
				+ PriceX.Prism*300;
		}
		else
			Price1 = PriceX.Prism*SurfaceAreaPrism;

		// The Pyramid Pricing (varies depending on total surface area)
		if (SurfaceAreaPyr > 150)
		{
			if (SurfaceAreaPyr > 300)
			{
					Price2 = PriceX.Pyr*(0.6)*(SurfaceAreaPyr-300)
									+ PriceX.Pyr*(0.8*(150))
									+ PriceX.Pyr*150;
			}
			else
					Price2 = PriceX.Pyr*(0.8)*(SurfaceAreaPyr-150)
					+ PriceX.Pyr*150;
		}
		else
			Price2 = PriceX.Pyr*SurfaceAreaPyr;

		// Check to see if it is the cheapest so far
		if (Price1 + Price2 < Cheapest.Price)
		{
			Cheapest.Price = Price1 + Price2;
			Cheapest.HeightPrism = height;
			Cheapest.LengthPrism = length;
			Cheapest.WidthPrism = width;
		}

	} // End For loop
} // End void

/*--------------------------------------------------------------------------------------*/
/* End Function.                                                                        */

