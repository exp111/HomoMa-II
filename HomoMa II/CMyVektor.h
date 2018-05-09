#pragma once
#include <math.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class CMyVektor
{
private:
	vector<double> values;
	unsigned dimension = 0;

	void SetDimension(unsigned dimension);
public:
	CMyVektor(unsigned dimension);
	~CMyVektor();

	
	unsigned GetDimension();
	double Get(unsigned at);
	bool Set(unsigned at, double value);

	double GetLength();
	CMyVektor append(CMyVektor b);
	CMyVektor operator+(CMyVektor b);
	CMyVektor operator*(double lambda);
	void print();
	string ToString();

	CMyVektor operator=(CMyVektor b);
};

