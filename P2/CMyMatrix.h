#pragma once
class CMyMatrix
{
private:
	//double[m][n] values;
	unsigned dimM = 0;
	unsigned dimN = 0;
public:
	CMyMatrix(unsigned m, unsigned n);
	~CMyMatrix();

	double Get(unsigned m, unsigned n);
	bool Set(unsigned m, unsigned n, double value);

	CMyMatrix invers();
};

