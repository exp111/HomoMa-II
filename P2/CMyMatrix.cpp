#include "CMyMatrix.h"



CMyMatrix::CMyMatrix()
{
}


CMyMatrix::CMyMatrix(unsigned m, unsigned n)
{
	//values.resize()
	this->dimM = m;
	this->dimN = n;
}

CMyMatrix::~CMyMatrix()
{
}

double CMyMatrix::Get(unsigned m, unsigned n)
{
	if (m > this->dimM || n > this->dimN)
		return 0.0;
	
	//return values[m][n];
}

bool CMyMatrix::Set(unsigned m, unsigned n, double value)
{
	if (m > this->dimM || n > this->dimN)
		return false;

	//values[m][n] = value;
	return true;
}

CMyMatrix CMyMatrix::invers()
{
	//(1/(ab-dc)) * CMyMatrix(d, -c, -b, a)
	return
}
