#include "C_DGLSolver.h"


CMyVektor C_DGLSolver::ableitungen(CMyVektor y, double x)
{
	if (_istDGLhoehererOrdnung)
	{
		if (_fDGLnterOrdnung == nullptr)
			return CMyVektor(0);

		//Umwandeln
		CMyVektor neu(y.GetDimension());
		for (int i = 1; i < y.GetDimension(); i++)
		{
			if (i != y.GetDimension() - 1) //yi == y'i+1
			{
				neu.Set(i - 1, y[i]);
			}
			else //last
			{
				neu.Set(i, _fDGLnterOrdnung(y, x));
			}
		}

		return neu;
	}
	
	if (_fDGLSystem == nullptr)
		return CMyVektor(0);

	return _fDGLSystem(y, x);
}

C_DGLSolver::C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x))
{
	_istDGLhoehererOrdnung = false;
	_fDGLSystem = f_DGL_System;
	_fDGLnterOrdnung = nullptr;
}

C_DGLSolver::C_DGLSolver(double(*f_DGL_nterOrdnung)(CMyVektor y, double x))
{
	_istDGLhoehererOrdnung = true;
	_fDGLSystem = nullptr;
	_fDGLnterOrdnung = f_DGL_nterOrdnung;
}

C_DGLSolver::~C_DGLSolver()
{
}

void C_DGLSolver::eulerVerfahren(int xStart, int xEnd, int schritte, CMyVektor yStart)
{
	//euler
	if (!_istDGLhoehererOrdnung &&_fDGLSystem == nullptr || _istDGLhoehererOrdnung && _fDGLnterOrdnung == nullptr)
		return;

	double h = (double)(xEnd - xStart) / schritte;

	cout << "h = " << h << endl;
	CMyVektor y = yStart;
	double x = xStart;
	for (unsigned schritt = 0; x < xEnd; x += h, schritt++)
	{
		cout << endl << endl;


		cout << "Schritt " << schritt << ":" << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y.ToString() << endl;
		//y(x) + h * y'(x)
		//y(x) + h * f(x,y)
		//y(x) + h * ableitung(y,x);
		CMyVektor yStrich = ableitungen(y, x);
		cout << "y' = " << yStrich.ToString() << endl;
		y = y + yStrich * h;
	}

	cout << endl << endl << "Ende bei" << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y.ToString() << endl;
	
}

void C_DGLSolver::heunVerfahren(int xStart, int xEnd, int schritte, CMyVektor yStart)
{
	//TODO:Heun
	if (_istDGLhoehererOrdnung)
	{
		if (_fDGLnterOrdnung == nullptr)
			return;

	}

	if (_fDGLSystem == nullptr)
		return;
}
