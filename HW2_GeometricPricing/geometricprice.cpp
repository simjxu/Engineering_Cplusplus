// Calculating Geometry-based Pricing (Algorithms, Conditional Expressions)
// The price of these genometric solids is based upon surface area

#include <iostream>
#include <cmath>
using namespace std;

// Declaration for "Value" Class
class Tank
{
public: // Public Interface
        double PricePrism, PricePyr;
        Tank()
        {
                PricePrism = 300.0;
                PricePyr = 400.0;
        }
};

int main()
{
        double Height(10), Length(10), PyrHeight(5), Volume, Width, SurfaceAreaPrism, SurfaceAreaPyr,
                        Price1, Price2;
        Tank Tank1;
        // Ask user for volume, store in "Volume" variable
        cout << "Enter tank volume >>> ";
        cin >> Volume;
        // Calculate the width from this volume
        Width = Volume/(Height*Length+PyrHeight*Length/3);

        // Surface Area of Prism (not including top face)
        // Surface Area of Pyramid (not including bottom face)
        SurfaceAreaPrism = 2*Height*Length+2*Height*Width+Length*Width;
        SurfaceAreaPyr = 2*sqrt((0.5*0.5*Width*Width+PyrHeight*PyrHeight))*0.5*Length
                        + 2*sqrt((0.5*0.5*Length*Length+PyrHeight*PyrHeight))*0.5*Width;

        // The Prism Pricing (varies depending on total surface area)
        if (SurfaceAreaPrism > 300)
        {
                if (SurfaceAreaPrism > 500)
                {
                        Price1 = Tank1.PricePrism*(0.85)*(SurfaceAreaPrism-500)
                                        + Tank1.PricePrism*(0.9*(200))
                                        + Tank1.PricePrism*300;
                }
                else
                        Price1 = Tank1.PricePrism*(0.9)*(SurfaceAreaPrism-300)
                        + Tank1.PricePrism*300;
        }
        else
                Price1 = Tank1.PricePrism*SurfaceAreaPrism;

        // The Pyramid Pricing (varies depending on total surface area)
        if (SurfaceAreaPyr > 150)
        {
                if (SurfaceAreaPyr > 300)
                {
                        Price2 = Tank1.PricePyr*(0.6)*(SurfaceAreaPyr-300)
                                        + Tank1.PricePyr*(0.8*(300))
                                        + Tank1.PricePyr*150;
                }
                else
                        Price2 = Tank1.PricePyr*(0.8)*(SurfaceAreaPyr-150)
                        + Tank1.PricePyr*150;
        }
        else
                Price2 = Tank1.PricePyr*SurfaceAreaPyr;

        // Output solution
        cout << "The total cost of the tank is $" << Price1 + Price2 << "." << endl;
        cout << "The width of the tank is " << Width <<        " meters." << endl;

        return 0;
}
