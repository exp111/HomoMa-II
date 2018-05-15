#include "CMyMatrix.h"

CMyMatrix::CMyMatrix(unsigned m, unsigned n)
{
	values.resize(m);
	for (auto &value : values)
	{
		value.resize(n);
	}
	this->dimM = m;
	this->dimN = n;
}

CMyMatrix::~CMyMatrix()
{
}

double CMyMatrix::Get(unsigned m, unsigned n)
{
	if (m > this->dimM - 1 || n > this->dimN - 1)
		return 0.0;
	
	return values[m][n];
}

bool CMyMatrix::Set(unsigned m, unsigned n, double value)
{
	if (m > this->dimM - 1 || n > this->dimN - 1)
		return false;

	values[m][n] = value;
	return true;
}

unsigned CMyMatrix::GetDimM()
{
	return this->dimM;
}

unsigned CMyMatrix::GetDimN()
{
	return this->dimN;
}

CMyMatrix CMyMatrix::invers()
{
	if (this->dimM != 2 || this->dimN != 2)
	{
		//Fehlermeldung und dann quitten
		cout << "Error: Wrong Dimensions!" << endl;
		return *this;
	}

	double a = Get(0, 0);
	double b = Get(0, 1);
	double c = Get(1, 0);
	double d = Get(1, 1);


	double datBoi = a*b - d*c;
	if (datBoi == 0)
	{
		//Fehlermeldung und dann quitten
		cout << "Error: det A == 0!" << endl;
		return *this;
	}
	
	double mod = (1 / datBoi);

	CMyMatrix changed = CMyMatrix(2, 2);
	
	changed.Set(0, 0, mod * d);
	changed.Set(0, 1, mod * -b);
	changed.Set(1, 0, mod * -c);
	changed.Set(1, 1, mod * a);

	return changed;
}

CMyVektor operator*(CMyMatrix A, CMyVektor x)
{
	//Check for right dimensions

	//Berechnung
	CMyVektor neu = CMyVektor(x.GetDimension());

	for (int m = 0; m < A.GetDimM(); m++)
	{
		double value = 0;
		for (int n = 0; n < A.GetDimN(); n++)
		{
			value += A.Get(m, n) * x.Get(n);
		}
		neu.Set(m, value);
	}

	return neu;
}

CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor x))
{
	static const double h = 10e-4;
	CMyVektor neuVek = funktion(x);
	CMyMatrix neu = CMyMatrix(x.GetDimension(), neuVek.GetDimension());

	for (int i = 0; i < neuVek.GetDimension(); i++)
	{
		double backupX = neuVek[i];

		for (int j = 0; j < x.GetDimension(); j++)
		{
			CMyVektor newVec = x;
			newVec.Set(j, newVec[j] + h);
			CMyVektor fXH = funktion(newVec);
			neu.Set(i, j, (fXH[i] - backupX) / h);
		}
	}
	return neu;
}
