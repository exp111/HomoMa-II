#include <iostream>
#include "CMyMatrix.h"
using namespace std;

CMyVektor f(CMyVektor x)
{
	CMyVektor neu(3);
	neu.Set(0, x[0] * x[1] * exp(x[2]));
	neu.Set(1, x[1] * x[2] * x[3]);
	neu.Set(2, x[3]);
	return neu;
}

CMyVektor g(CMyVektor x)
{
	CMyVektor neu(2);
	neu.Set(0, (x[0] * x[0] * x[0]) * (x[1] * x[1] * x[1]) - 2 * x[1]);
	neu.Set(1, x[0] - 2);
	return neu;
}

int main()
{
	/*CMyVektor x = CMyVektor(4);
	x.Set(0, 1);
	x.Set(1, 2);
	x.Set(2, 0);
	x.Set(3, 3);
	
	CMyMatrix neuM = jacobi(x, &f);
	cout << "M = " << neuM.ToString();*/
	CMyVektor x(2);
	x.Set(0, 1);
	x.Set(1, 1);
	newtonVerfahren(x, &g);

	system("PAUSE");
}