#pragma once
#include <math.h>

class CKomplex
{
private:
	double _realTeil = 0;
	double _imagTeil = 0;
public:
	CKomplex();
	CKomplex(double a, double b);
	CKomplex(double phi);
	~CKomplex();

	double re();
	double im();
	void Set(double a, double b);

	CKomplex operator+(CKomplex b);
	void operator+=(CKomplex b);
	CKomplex operator*(CKomplex b);
	CKomplex operator*(double b);
	void operator*=(double b);

	double abs();
};

