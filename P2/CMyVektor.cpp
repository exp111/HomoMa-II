#include "CMyVektor.h"

CMyVektor::CMyVektor(unsigned dimension)
{
	values.resize(dimension);
	this->dimension = dimension;
}


CMyVektor::~CMyVektor()
{
}

void CMyVektor::SetDimension(unsigned dimension)
{
	if (this->dimension == dimension)
		return;

	this->dimension = dimension;
	values.resize(dimension);
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
	CMyVektor newVec = CMyVektor(dimension);
	for (int i = 0; i < dimension; i++)
	{
		newVec.Set(i, values[i] + b.Get(i));
	}
	return newVec;
}

CMyVektor CMyVektor::operator*(double lambda)
{
	CMyVektor newVec = CMyVektor(dimension);
	for (int i = 0; i < dimension; i++)
	{
		newVec.Set(i, values[i] * lambda);
	}
	return newVec;
}

void CMyVektor::print()
{
	for (int i = 0; i < dimension; i++)
	{
		cout << i << ": " << values[i] << endl;
	}
}

string CMyVektor::ToString()
{
	string ret = "(";
	for (int i = 0; i < dimension; i++)
	{
		ret += " " + to_string(values[i]) + ";";
	}
	ret.pop_back();
	ret += ");";
	return ret;
}

CMyVektor CMyVektor::operator=(CMyVektor b)
{
	this->SetDimension(b.GetDimension());
	for (int i = 0; i < dimension; i++)
	{
		values[i] = b.Get(i);
	}
	return *this;
}

double CMyVektor::operator[](unsigned at)
{
	return this->values[at];
}