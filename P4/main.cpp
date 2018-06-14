#include <fstream>   
#include <vector>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "CKomplex.h"
using namespace std;

vector<CKomplex> fourierTransformation(vector<CKomplex> inputWerte, bool doHinTransformation = true);

vector<CKomplex>  werte_einlesen(char *dateiname)
{
	int i, N, idx;
	double re, im;
	vector<CKomplex> werte;
	// File oeffnen
	ifstream fp;
	fp.open(dateiname);
	// Dimension einlesen
	fp >> N;
	// Werte-Vektor anlegen
	werte.resize(N);
	CKomplex null(0, 0);
	for (i = 0; i<N; i++)
		werte[i] = null;
	// Eintraege einlesen und im Werte-Vektor ablegen
	while (!fp.eof())
	{
		fp >> idx >> re >> im;
		CKomplex a(re, im);
		werte[idx] = a;
	}
	// File schliessen
	fp.close();

	return werte;
}

void werte_ausgeben(char *dateiname, vector<CKomplex> werte, double epsilon = -1)
{
	int i;
	int N = werte.size();
	// File oeffnen
	ofstream fp;
	fp.open(dateiname);
	// Dimension in das File schreiben
	fp << N << endl;
	// Eintraege in das File schreiben
	fp.precision(10);
	for (i = 0; i < N; i++)
	{
		if (werte[i].abs() > epsilon)
			fp << i << "\t" << werte[i].re() << "\t" << werte[i].im() << endl;
	}
	// File schliessen
	fp.close();
}

double maxAbweichung(vector<CKomplex> base, vector<CKomplex> compare)
{
	double highest = 0;
	for (int i = 0; i < base.size(), i < compare.size(); i++)
	{
		double current = base[i].abs() - compare[i].abs();
		if (current > highest)
			highest = current;
	}
	return highest;
}

int main()
{
	//Einlesen
	vector<CKomplex> original = werte_einlesen("Daten_original.txt");

	//Fourier - Hintransformation
	vector<CKomplex> originalFourier = fourierTransformation(original);

	//Daten ausgeben mit default, 0.1, 1.0
	werte_ausgeben("Daten_ausgegeben.txt", originalFourier);
	werte_ausgeben("Daten_ausgegeben_0.1.txt", originalFourier, 0.1);
	werte_ausgeben("Daten_ausgegeben_1.0.txt", originalFourier, 1.0);

	//Wieder einlesen
	vector<CKomplex> originalDefault = werte_einlesen("Daten_ausgegeben.txt");
	vector<CKomplex> originalEpsilon01 = werte_einlesen("Daten_ausgegeben_0.1.txt");
	vector<CKomplex> originalEpsilon10 = werte_einlesen("Daten_ausgegeben_1.0.txt");
	
	//Rücktransformation //Takes ages
	vector<CKomplex> rueckDefault = fourierTransformation(originalDefault, false);
	vector<CKomplex> rueckEpsilon01 = fourierTransformation(originalEpsilon01, false);
	vector<CKomplex> rueckEpsilon10 = fourierTransformation(originalEpsilon10, false);

	//Abweichung berechnen
	cout << "Maximale Abweichung bei Standard-Epsilon: " << maxAbweichung(original, rueckDefault) << endl
		 << "Maximale Abweichung bei epsilon = 0.1: " << maxAbweichung(original, rueckEpsilon01) << endl
		 << "Maximale Abweichung bei epsilon = 1.0 : " << maxAbweichung(original, rueckEpsilon10) << endl;

	system("PAUSE");
}

vector<CKomplex> fourierTransformation(vector<CKomplex> input, bool doHinTransformation)
{
	unsigned N = input.size();
	vector<CKomplex> result = vector<CKomplex>(N);
	double factor = 1 / sqrt(N);
	if (doHinTransformation)
	{
		for (int n = 0; n < N; n++)
		{
			result[n].Set(0,0);
			for (int k = 0; k < N; k++)
			{
				//fk * e^-j((2pi*k*n)/N)
				result[n] += input[k] * CKomplex((-2 * M_PI * k * n) / N);
			}
			result[n] *= factor;
		}
	}
	else //Rück
	{
		for (int k = 0; k < N; k++)
		{
			result[k].Set(0,0);
			for (int n = 0; n < N; n++)
			{
				//cn * e^j((2pi*k*n)/N)
				result[k] += input[n] * CKomplex((2 * M_PI * k * n) / N);
			}
			result[k] *= factor;
		}
	}

	return result;
}