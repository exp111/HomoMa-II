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

CMyVektor gradient(CMyVektor x, double(*funktion)(CMyVektor x))
{
	static const double h = 0.00000001;
	CMyVektor backup = x;
	double backupX = funktion(x);
	for (int i = 0; i < x.GetDimension(); i++)
	{
		CMyVektor newVec = backup;
		newVec.Set(i, newVec.Get(i) + h);
		x.Set(i, (funktion(newVec) - backupX) / h);
	}
	return x;
}

void gradientenverfahren(CMyVektor a, double(*function)(CMyVektor x), double halfLife3)
{
	CMyVektor x = a;
	double lambda = halfLife3;

	unsigned schritt = 0;
	CMyVektor gradfX = CMyVektor(0);
	do
	{
		cout << endl << "Schritt " << schritt << ":" << endl;
		cout << "x = " << x.ToString() << endl;
		cout << "lambda = " << lambda << endl;
		CMyVektor xNeu = x + gradient(x, function) * lambda;
		double fXNeu = function(xNeu);
		double fX = function(x);
		cout << "f(x) = " << fX << endl;
		gradfX = gradient(x, function);
		cout << "grad f(x) = " << gradfX.ToString() << endl;
		cout << "||grad f(x)|| = " << gradfX.GetLength() << endl << endl;

		cout << "x_neu = " << xNeu.ToString() << endl;
		cout << "f(x_neu) = " << fXNeu << endl << endl;

		if (fXNeu > fX)
		{
			cout << "Test mit doppelter Schrittweite (lambda = 2) :" << endl;
			CMyVektor xTest = x + gradient(x, function) * (2 * lambda);
			cout << "x_test = " << xTest.ToString() << endl;
			double fXTest = function(xTest);
			cout << "f(x_test) = " << fXTest << endl;
			if (fXTest > fXNeu)
			{
				x = xTest;
				lambda *= 2;
				cout << "verdoppele Schrittweite!" << endl;
			}
			else
			{
				x = xNeu;
				cout << "behalte alte Schrittweite!" << endl;
			}
		}
		else
		{
			do
			{
				lambda *= 0.5;
				cout << "halbiere Schrittweite (lambda = " << lambda << "):" << endl;
				xNeu = x + gradient(x, function) * lambda;
				cout << "x_neu = " << xNeu.ToString() << endl;
				fXNeu = function(xNeu);
				cout << "f(x_neu) = " << fXNeu << endl;
			} while (fX > fXNeu);

			x = xNeu;
		}

		schritt++;
	} while (gradient(x, function).GetLength() >= 0.00001 && schritt < 50);


	if (schritt >= 50)
	{
		cout << endl << "Ende wegen Schrittanzahl = 50 bei" << endl;

	}
	else
	{
		cout << endl << "Ende wegen ||grad f(x)||<1e-5 bei" << endl;
	}
	cout << "x = " << x.ToString() << endl;
	cout << "lambda = " << lambda << endl;
	cout << "f(x) = " << function(x) << endl;
	cout << "grad f(x) = " << gradient(x, function).ToString() << endl;
	cout << "||grad f(x)|| = " << gradient(x, function).GetLength() << endl;
}