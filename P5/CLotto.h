#pragma once
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "CZufall.h"
using namespace std;

class CLotto
{
private:
	vector<int> tippzettel = vector<int>(6);

	vector<int> ziehung6aus49();
public:
	CLotto(int n);
	~CLotto();
	void setTipp(int a, int b, int c, int d, int e, int f);
	int lottoZiehung(bool print = false);
	int lotto2Ziehung(bool print = false);
};

