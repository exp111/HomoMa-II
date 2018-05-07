#pragma once
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

class CMyVektor
{
private:
	vector<double> values;
	unsigned dimension = 0;

	const double h = 0.00000001;
public:
	CMyVektor(unsigned dimension);
	~CMyVektor();

	unsigned GetDimension();
	double Get(unsigned at);
	bool Set(unsigned at, double value);

	double GetLength();
	CMyVektor append(CMyVektor b);	CMyVektor operator+(CMyVektor b);	CMyVektor operator*(double lambda);
	void print();

	CMyVektor gradient(double(*function)(CMyVektor x));
};

