#pragma once
#include <vector>
#include <iostream>
#include "CMyVektor.h"
using namespace std;

class CMyMatrix
{
private:
	vector<vector<double>> values;
	unsigned dimM = 0;
	unsigned dimN = 0;
public:
	CMyMatrix(unsigned m, unsigned n);
	~CMyMatrix();

	double Get(unsigned m, unsigned n);
	bool Set(unsigned m, unsigned n, double value);

	unsigned GetDimM();
	unsigned GetDimN();

	CMyMatrix invers();

	string ToString();
};

CMyVektor operator*(CMyMatrix A, CMyVektor x);
CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor x));
void newtonVerfahren(CMyVektor x, CMyVektor(*funktion)(CMyVektor x));