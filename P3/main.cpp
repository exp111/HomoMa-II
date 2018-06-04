#include <iostream>
#include "C_DGLSolver.h"
using namespace std;

CMyVektor fDGLSystemErsterOrdnung(CMyVektor y, double x)
{
	/*y′1 = 2y2 − xy1,
	  y′2 = y1y2 − 2x3*/
	CMyVektor neu(2);
	neu.Set(0, 2 * y[1] - x * y[0]);
	neu.Set(1, y[0] * y[1] - 2 * (x * x * x));

	return neu;
}

int main()
{
	C_DGLSolver dglSolver(fDGLSystemErsterOrdnung);
	CMyVektor yStart(2);
	yStart.Set(0, 0);
	yStart.Set(1, 1);
	dglSolver.eulerVerfahren(0, 2, 100, yStart);
	system("PAUSE");
}