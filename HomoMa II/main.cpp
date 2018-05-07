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
void gradientenverfahren(CMyVektor a, double(*function)(CMyVektor x), double lambda);

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

void gradientenverfahren(CMyVektor a, double(*function)(CMyVektor x), double halfLife3 = 1.0)
{
	CMyVektor x = a;
	double lambda = halfLife3;

	unsigned schritt = 0;
	CMyVektor gradfX = CMyVektor(0);
	do
	{
		cout << endl << "Schritt " << schritt << ":" << endl;
		cout << "x = " << x.ToString() << endl;
		cout << "lambda = " << lambda << endl;
		CMyVektor xNeu = x + gradient(x, function) * lambda;
		double fXNeu = function(xNeu);
		double fX = function(x);
		cout << "f(x) = " << fX << endl;
		gradfX = gradient(x, function);
		cout << "grad f(x) = " << gradfX.ToString() << endl;
		cout << "||grad f(x)|| = " << gradfX.GetLength() << endl << endl;

		cout << "x_neu = " << xNeu.ToString() << endl;
		cout << "f(x_neu) = " << fXNeu << endl << endl;

		if (fXNeu > fX)
		{
			cout << "Test mit doppelter Schrittweite (lambda = 2) :" << endl;
			CMyVektor xTest = x + gradient(x, function) * (2 *lambda);
			cout << "x_test = " << xTest.ToString() << endl;
			double fXTest = function(xTest);
			cout << "f(x_test) = " << fXTest << endl;
			if (fXTest > fXNeu)
			{
				x = xTest;
				lambda *= 2;
				cout << "verdoppele Schrittweite!" << endl;
			}
			else
			{
				x = xNeu;
				cout << "behalte alte Schrittweite!" << endl;
			}
		}
		else
		{
			do
			{
				lambda *= 0.5;
				cout << "halbiere Schrittweite (lambda = " << lambda << "):" << endl;
				xNeu = x + gradient(x, function) * lambda;
				cout << "x_neu = " << xNeu.ToString() << endl;
				fXNeu = function(xNeu);
				cout << "f(x_neu) = " << fXNeu << endl;
			} while (fX > fXNeu);

			x = xNeu;
		}

		schritt++;
	} while (gradient(x, function).GetLength() >= 0.00001 && schritt < 50);


	if (schritt >= 50)
	{
		cout << endl << "Ende wegen Schrittanzahl = 50 bei" << endl;
		
	}
	else
	{
		cout << endl << "Ende wegen ||grad f(x)||<1e-5 bei" << endl;
	}
	cout << "x = " << x.ToString() << endl;
	cout << "lambda = " << lambda << endl;
	cout << "f(x) = " << function(x) << endl;
	cout << "grad f(x) = " << gradient(x, function).ToString() << endl;
	cout << "||grad f(x)|| = " << gradient(x, function).GetLength() << endl;
}