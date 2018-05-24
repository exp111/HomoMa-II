#include "C_DGLSolver.h"


CMyVektor C_DGLSolver::ableitungen(CMyVektor y, double x)
{
	if (_istDGLhoehererOrdnung)
	{
		if (_fDGLnterOrdnung == nullptr)
			return CMyVektor(0);

		//TODO: Umwandeln
		if (_fDGLSystem == nullptr) //schon umgeformt?
		{

		}
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
	//TODO:euler
	if (_istDGLhoehererOrdnung)
	{
		if (_fDGLnterOrdnung == nullptr)
			return;

	}

	if (_fDGLSystem == nullptr)
		return;
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
