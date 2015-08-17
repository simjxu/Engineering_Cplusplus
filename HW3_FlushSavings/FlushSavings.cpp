// Gathering data from outside data file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Declaration for "Flush" Class
class Flush
{
public: // Public Interface
    double installcost, newL, oldL, usage, ppt;
    Flush()
    {
        // Input data from file "constants.dat"
        string filename("constants.dat");
        ifstream constants;
        constants.open(filename.c_str());
        constants >> installcost; // cost to install each toilet
        constants >> newL; // number of liters per flush in new toilet
        constants >> oldL; // number of liters per flush in old toilet
        constants >> usage; // number of uses per day per toilet
        constants >> ppt; // number of people per toilet
    }
};

int main()
{
    // Call variables
    double pop, price, toi, totcost, h2osave, moneysave, breakeven;
    int newtoi; // integer number of toilets
    Flush NYC;

    // Ask for user inputs
    cout << "Please enter the population of the community >>> ";
    cin >> pop;
    cout << "Please enter the estimated cost of water ($/liter) >>> ";
    cin >> price;

    // Calculate number of toilets
    toi = pop/NYC.ppt + 0.5;
    newtoi = toi; // Round number of toilets to nearest integer

    // Calculate replacement cost
    totcost = newtoi*NYC.installcost;

    // Calculate liters saved
    h2osave = newtoi*NYC.usage*NYC.oldL - newtoi*NYC.usage*NYC.newL;

    // Calculate cost savings per day
    moneysave = h2osave*price;

    // Calculate break even point
    breakeven = totcost/moneysave;

    // Display Outputs
    cout << "A total of " << newtoi << " new toilets would be needed." << endl;
    cout << "Their total replacement cost would be $" << totcost << "." << endl;
    cout << "The potential flushed water savings is " << h2osave << " liters per day" << endl;
    cout << "The potential cost savings approaches $" << moneysave << " per day" << endl;
    cout << "The breakeven point will be reached after " << breakeven << " days of usage." << endl;

    return 0;
}

