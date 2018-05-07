#include "CMyVektor.h"

CMyVektor::CMyVektor(unsigned dimension)
{
	values.resize(dimension);
	this->dimension = dimension;
}


CMyVektor::~CMyVektor()
{
}

unsigned CMyVektor::GetDimension()
{
	return dimension;
}

double CMyVektor::Get(unsigned at)
{
	if (at >= dimension)
		return 0.0;

	return values[at];
}

bool CMyVektor::Set(unsigned at, double value)
{
	if (at >= dimension)
		return false;

	values[at] = value;
	return true;
}

double CMyVektor::GetLength()
{
	double length = 0;
	for (int i = 0; i < dimension; i++)
	{
		length += values[i] * values[i];
	}
	return sqrt(length);
}

CMyVektor CMyVektor::append(CMyVektor b)
{
	CMyVektor newVector = CMyVektor(dimension + b.GetDimension());
	for (int i = 0; i < dimension; i++)
	{
		newVector.Set(i, this->Get(i));
	}
	for (int i = dimension; i < newVector.dimension; i++)
	{
		newVector.Set(i, b.Get(i));
	}
	return newVector;
}

CMyVektor CMyVektor::operator+(CMyVektor b)
{
	for (int i = 0; i < dimension; i++)
	{
		values[i] += b.Get(i);
	}
	return *this;
}

CMyVektor CMyVektor::operator*(double lambda)
{
	for (int i = 0; i < dimension; i++)
	{
		values[i] *= lambda;
	}
	return *this;
}

void CMyVektor::print()
{
	for (int i = 0; i < dimension; i++)
	{
		cout << i << ": " << values[i] << endl;
	}
}

CMyVektor CMyVektor::gradient(double(*funktion)(CMyVektor x))
{
	for (int i = 0; i < dimension; i++)
	{
		//TODO: fix this shit
		double cur = values[i];
		values[i] = (funktion(cur + h) - funktion(cur)) / h;
	}
	return *this;
}
