#include <fstream>   
#include <vector>
#include "CKomplex.h"
using namespace std;

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
		if (werte[i].abs() > epsilon)
			fp << i << "\t" << werte[i].re() << "\t" << werte[i].im() << endl;
	// File schliessen
	fp.close();
}

int main()
{
	//Einlesen
	vector<CKomplex> result = werte_einlesen("Daten_original.txt");

	//TODO: Fourier - Hintransformation

	//Daten ausgeben mit default, 0.1, 1.0
	werte_ausgeben("Daten_ausgegeben.txt", result);
	werte_ausgeben("Daten_ausgegeben_0.1.txt", result, 0.1);
	werte_ausgeben("Daten_ausgegeben_1.0.txt", result, 1.0);

	//Optional: Werte vergleichen

	//Wieder einlesen
	vector<CKomplex> resultDefault = werte_einlesen("Daten_ausgegeben.txt");
	vector<CKomplex> resultDefault = werte_einlesen("Daten_ausgegeben_0.1.txt");
	vector<CKomplex> resultDefault = werte_einlesen("Daten_ausgegeben_1.0.txt");

	//TODO: Rücktransformation

	//Abweichung berechnen
}