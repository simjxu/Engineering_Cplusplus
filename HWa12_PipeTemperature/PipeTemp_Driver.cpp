#include "pipetemp.h"

int main()
{
	Fin one; 
	cin >> one;
	one.initialize();
	cout << one;
	one.compute();
	cout << one; 
	return 0;
}
