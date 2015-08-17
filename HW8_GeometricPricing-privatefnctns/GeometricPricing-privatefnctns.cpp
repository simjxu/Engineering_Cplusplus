#include "GeometricPricing-privatefnctns(header).h"
									
int main()
{
  double radius, height, base, width;

  cout << setiosflags (ios::fixed | ios::showpoint) << setprecision (2);

  cout << "Enter cylinder height and radius >>> ";
  cin >> height >> radius;
  Cylinder one (radius, height);
  cout << "The cylinder volume is " << volume (one) << endl;
  cout << "The cylinder surface area is " << surface_area (one) << endl;
  cout << one << endl;

  cout << "Enter sphere radius >>> ";
  cin >> radius;
  Sphere two (radius);
  cout << "The sphere volume is " << volume (two) << endl;
  cout << "The sphere surface area is " << surface_area (two) << endl;
  cout << two << endl;

  cout << "Enter rectangular prism base length, height, and width >>> ";
  cin >> base >> height >> width;
  Prism three (base, height, width);
  cout << "The rectangular prism volume is " << volume (three) << endl;
  cout << "The rectangular prism surface area is " << surface_area (three) << endl;
  cout << three << endl;

  cout << "Enter cone height and radius >>> ";
  cin >> height >> radius;
  Cone four (radius, height);
  cout << "The cone volume is " << volume (four) << endl;
  cout << "The cone surface area is " << surface_area (four) << endl;
  cout << four << endl;

  cout << "Enter pyramid base side length and height >>> ";
  cin >> base >> height;
  Pyramid five (base, height);
  cout << "The pyramid volume is " << volume (five) << endl;
  cout << "The pyramid surface area is " << surface_area (five) << endl;
  cout << five << endl;

  return 0;
}