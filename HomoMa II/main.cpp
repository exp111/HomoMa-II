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

const double h = 0.00000001;
void gradientenverfahren(CMyVektor a, double(*function)(CMyVektor x));

int main()
{
	CMyVektor myVec = CMyVektor(2);
	myVec.Set(0, 3);
	myVec.Set(1, 2);
	gradientenverfahren(myVec, &f);
	system("PAUSE");
}

CMyVektor gradient(CMyVektor x, double(*funktion)(CMyVektor x))
{
	CMyVektor backup = x;
	for (int i = 0; i < x.GetDimension(); i++)
	{
		CMyVektor newVec = backup;
		newVec.Set(i, newVec.Get(i) + h);
		x.Set(i, (funktion(newVec) - funktion(backup)) / h);
	}
	return x;
}

void gradientenverfahren(CMyVektor a, double(*function)(CMyVektor x))
{
	CMyVektor x = a;
	double lambda = 1.0f;
	CMyVektor xNeu = x + gradient(x, function) * lambda;

	unsigned schritt = 0;
	do
	{
		cout << "Schritt " << schritt << ":" << endl;
		cout << "x = " << x.ToString() << endl;
		cout << "lambda = " << lambda << endl;
		double fXNeu = function(xNeu);
		double fX = function(x);
		cout << "f(x) = " << fX << endl;
		cout << "grad f(x) = " << gradient(x, &f).ToString() << endl;
		if (fXNeu > fX)
		{
			CMyVektor xTest = x + gradient(x, function) * (2 *lambda);
			if (function(xTest) > fXNeu)
			{
				x = xTest;
				lambda *= 2;
			}
			else
			{
				x = xNeu;
			}
		}
		else
		{
			do
			{
				lambda *= 0.5;
				xNeu = x + gradient(x, function) * lambda;
			} while (fX > function(xNeu));
		}

		schritt++;
	} while (schritt < 50);
}