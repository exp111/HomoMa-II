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

double fDGLSystemDritterOrdnung(CMyVektor y, double x)
{
	return 2 * x * y[1] * y[2] + 2 * y[0] * y[0] * y[1];
}

int main()
{
	/*C_DGLSolver dglSolver(fDGLSystemErsterOrdnung);
	CMyVektor yStart(2);
	yStart.Set(0, 0);
	yStart.Set(1, 1);
	//dglSolver.eulerVerfahren(0, 2, 100, yStart);
	dglSolver.heunVerfahren(0, 2, 100, yStart);*/

	C_DGLSolver dglSolver(fDGLSystemDritterOrdnung);
	CMyVektor yStart(3);
	yStart.Set(0, 1);
	yStart.Set(1, 1);
	yStart.Set(2, 2);
	CMyVektor ergebnis = dglSolver.eulerVerfahren(1, 2, 10, yStart);
	cout << 0.5 - ergebnis[0] << endl;
	system("PAUSE");
}