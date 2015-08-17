#include <iostream>
#include <cmath>
using namespace std;

// Declaration for "Tank" Class
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
        double Height(10), Length, LengthMin, PyrHeight, Volume, Width, SurfaceAreaPrism,
                        SurfaceAreaPyr, Price1, Price2, PriceRound, PriceMin(1e308);
        Tank Tank1;
        // Ask user for volume, store in "Volume" variable
        cout << "Enter tank volume >>> ";
        cin >> Volume;

        // Loop through different lengths 2.0-40.0 meters (+0.1 meter per iteration)
        for (Length = 2.0; Length <= 40.0; Length += 0.1)
        {
                PyrHeight = Length/2;
                Width = Volume/(Height*Length+PyrHeight*Length/3);
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
                                                + Tank1.PricePyr*(0.8*(150))
                                                + Tank1.PricePyr*150;
                        }
                        else
                                Price2 = Tank1.PricePyr*(0.8)*(SurfaceAreaPyr-150)
                                + Tank1.PricePyr*150;
                }
                else
                        Price2 = Tank1.PricePyr*SurfaceAreaPyr;
                if (Price1 + Price2 < PriceMin)
                {
                        PriceMin = Price1 + Price2;
                        LengthMin = Length;
                }
        } // End For loop

        // Round value of PriceMin to nearest 1000
        PriceRound = floor(PriceMin/1000 + 0.5)*1000;

        // Output solution
        cout << "The optimal length is " << LengthMin << " meters." << endl;
        cout << "The cost at this length is $" << PriceRound <<        "." << endl;

        return 0;
}
