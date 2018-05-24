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
	/*CMyVektor myVec = CMyVektor(2);
	myVec.Set(0, 3);
	myVec.Set(1, 2);
	gradientenverfahren(myVec, &f);*/
	CMyVektor myVec = CMyVektor(3);
	gradientenverfahren(myVec, &g, 0.1);
	system("PAUSE");
}