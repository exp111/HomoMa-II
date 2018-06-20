#include "CKomplex.h"


CKomplex::CKomplex()
{
}

CKomplex::CKomplex(double a, double b)
{
	_realTeil = a;
	_imagTeil = b;
}

CKomplex::CKomplex(double phi)
{
	_realTeil = cos(phi);
	_imagTeil = sin(phi);
}

CKomplex::~CKomplex()
{
}

double CKomplex::re() const
{
	return _realTeil;
}

double CKomplex::im() const
{
	return _imagTeil;
}

void CKomplex::Set(double a, double b)
{
	_realTeil = a;
	_imagTeil = b;
}

CKomplex CKomplex::operator+(CKomplex b)
{
	return CKomplex(re() + b.re(), im() + b.im());
}

void CKomplex::operator+=(CKomplex b)
{
	*this = *this + b;
}

CKomplex CKomplex::operator*(CKomplex b)
{
	return CKomplex(re() * b.re() - im() * b.im(), re() * b.im() + im() * b.re());
}

CKomplex CKomplex::operator*(double b)
{
	return CKomplex(re() * b, im() * b);
}

void CKomplex::operator*=(double b)
{
	*this = *this * b;
}

double CKomplex::abs()
{
	return sqrt(re() * re() + im() * im());
}


