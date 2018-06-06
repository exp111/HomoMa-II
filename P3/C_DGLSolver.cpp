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
			neu.Set(i - 1, y[i]); //yi-1 = y'i
		}
		neu.Set(y.GetDimension() - 1, _fDGLnterOrdnung(y, x));

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

CMyVektor C_DGLSolver::eulerVerfahren(int xStart, int xEnd, int schritte, CMyVektor yStart)
{
	//euler
	if (!_istDGLhoehererOrdnung &&_fDGLSystem == nullptr || _istDGLhoehererOrdnung && _fDGLnterOrdnung == nullptr)
		return CMyVektor(0);

	double h = (double)(xEnd - xStart) / schritte;

	cout << "h = " << h << endl;
	CMyVektor y = yStart;
	double x = xStart;
	for (unsigned schritt = 0; schritt < schritte; x += h, schritt++)
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
	
	return y;
}

CMyVektor C_DGLSolver::heunVerfahren(int xStart, int xEnd, int schritte, CMyVektor yStart)
{
	//Heun
	if (!_istDGLhoehererOrdnung &&_fDGLSystem == nullptr || _istDGLhoehererOrdnung && _fDGLnterOrdnung == nullptr)
		return CMyVektor(0);

	const long double h = (double)(xEnd - xStart) / schritte;

	cout << "h = " << h << endl;
	CMyVektor y = yStart;
	double x = xStart;
	double xTest = x + h;
	for (unsigned schritt = 0; schritt < schritte; x = xTest, schritt++)
	{
		cout << endl << endl;

		cout << "Schritt " << schritt << ":" << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y.ToString() << endl;
		CMyVektor yStrich = ableitungen(y, x);
		cout << "y'_orig = " << yStrich.ToString() << endl;
		//y(x) + h * y'mittel; y'mittel = 0.5 * f(x0, y(x0)) + f(x1, y1)
		
		CMyVektor yTest = y + yStrich * h;
		xTest = x + h;
		cout << endl << "y_Test = " << yTest.ToString() << endl;
		CMyVektor yTestStrich = ableitungen(yTest, xTest);
		cout << "y'_Test = " << yTestStrich.ToString() << endl;

		CMyVektor yMittel = (yStrich + yTestStrich) * 0.5;
		cout << endl << "y'_Mittel = " << yMittel.ToString() << endl;
		y = y + yMittel * h;

	}

	cout << endl << endl << "Ende bei" << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y.ToString() << endl;

	return y;
}
