#include "CLotto.h"
#include <iostream>

vector<int> CLotto::ziehung6aus49()
{
	CZufall zufall;
	vector<int> ret = vector<int>(6);
	for (size_t i = 0; i < ret.size(); i++)
	{
		bool needsRepeat = false;
		do
		{
			needsRepeat = false;
			ret[i] = zufall.wert(1, 49);
			for (size_t j = 0; j < i; j++)
			{
				if (ret[i] == ret[j])
				{
					needsRepeat = true;
					break;
				}
			}
		} while (needsRepeat);
	}
	return ret;
}

CLotto::CLotto(int n)
{
	if (n < 0)
		srand(time(NULL));
	else
		srand(n);
}

CLotto::~CLotto()
{
}

void CLotto::setTipp(int a, int b, int c, int d, int e, int f)
{
	tippzettel = { a,b,c,d,e,f };
}

int CLotto::lottoZiehung(bool print)
{
	int count = 0;
	vector<int> ziehung = ziehung6aus49();
	if (print)
	{
		for (size_t i = 0; i < ziehung.size(); i++)
		{
			cout << "1: " << ziehung[i] << "; 2: " << tippzettel[i] << endl;
		}
	}
	for (size_t i = 0; i < ziehung.size(); i++)
	{
		for (size_t j = 0; j < tippzettel.size(); j++)
		{
			if (tippzettel[j] == ziehung[i])
			{
				count++;
				break;
			}
		}
	}
	return count;
}

int CLotto::lotto2Ziehung(bool print)
{
	int count = 0;
	vector<int> ziehung = ziehung6aus49();
	vector<int> ziehung2 = ziehung6aus49();
	if (print)
	{
		for (size_t i = 0; i < ziehung.size(); i++)
		{
			cout << "1: " << ziehung[i] << "; 2: " << ziehung2[i] << endl;
		}
	}
	for (size_t i = 0; i < ziehung.size(); i++)
	{
		for (size_t j = 0; j < ziehung2.size(); j++)
		{
			if (ziehung2[j] == ziehung[i])
			{
				count++;
				break;
			}
		}
	}
	return count;
}

