#include <iostream>
#include <math.h>
#include "CMyVektor.h"

using namespace std;

double f(CMyVektor a)
{
	double x = a.Get(0);
	double y = a.Get(1);
	return sin(x + (y * y)) + (y*y*y) - 6 * (y*y) + 9 * y;
}

double g(CMyVektor a)
{
	double x = a.Get(0);
	double y = a.Get(1);
	double z = a.Get(2);
	return -(2 * x*x - 2 * x*y + y*y + z*z - 2 * x - 4 * z);
}

int main()
{
	CMyVektor myVec = CMyVektor(5);
	cout << "Dimension: " << myVec.GetDimension() << endl;
	myVec.Set(0, 3);
	myVec.Set(1, 4);
	cout << "Length: " << myVec.GetLength() << endl;
	CMyVektor newVec = myVec.gradient(&f);
	newVec.print();
	system("PAUSE");
}