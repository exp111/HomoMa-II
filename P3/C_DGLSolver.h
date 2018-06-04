#pragma once
#include "CMyVektor.h"

class C_DGLSolver
{
private:
	typedef CMyVektor(*DGLSystemFunction)(CMyVektor y, double x);
	typedef double(*DGLnterOrdnungFunction)(CMyVektor y, double x);
	
	DGLSystemFunction _fDGLSystem = nullptr;  //CMyVektor (*f_DGL_System)(CMyVektor y, double x)
	DGLnterOrdnungFunction _fDGLnterOrdnung = nullptr; //double (*f DGL nterOrdnung)(CMyVektor y, double x)

	bool _istDGLhoehererOrdnung = false; 

	CMyVektor ableitungen(CMyVektor y, double x);
public:
	C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x));
	C_DGLSolver(double(*f_DGL_nterOrdnung)(CMyVektor y, double x));
	~C_DGLSolver();

	CMyVektor eulerVerfahren(int xStart, int xEnd, int schritte, CMyVektor yStart);
	CMyVektor heunVerfahren(int xStart, int xEnd, int schritte, CMyVektor yStart);
};

