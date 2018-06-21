#include "CZufall.h"



CZufall::CZufall()
{
}


CZufall::~CZufall()
{
}

int CZufall::wert(int a, int b)
{
	return (rand() % (b - a)) + a;
}

void CZufall::initialisiere(int n)
{
	srand(n);
}

vector<int> CZufall::test(int a, int b, int N)
{
	vector<int> ret(b - a);
	for (int i = 0; i < N; i++)
	{
		ret[wert(a, b) - a]++;
	}
	return ret;
}

vector<int> CZufall::test_falsch(int a, int b, int N)
{
	vector<int> ret(b - a);
	for (int i = 0; i < N; i++)
	{
		srand(time(NULL));
		ret[wert(a, b) - a]++;
	}
	return ret;
}
