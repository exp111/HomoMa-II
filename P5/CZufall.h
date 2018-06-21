#pragma once
#include <stdlib.h>
#include <vector>
#include <time.h>
using namespace std;
class CZufall
{
public:
	CZufall();
	~CZufall();

	int wert(int a, int b);
	void initialisiere(int n);
	vector<int> test(int a, int b, int N);
	vector<int> test_falsch(int a, int b, int N);
};

