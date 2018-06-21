#include <iostream>
#include <vector>
#include "CZufall.h"
#include "CLotto.h"
using namespace std;

int monteCarloStuff(CLotto lotto, int numZiehungen, int (*func)(CLotto), int wantedEreignis)
{
	int timesItHappened = 0;
	for (int i = 0; i < numZiehungen; i++)
	{
		if (func(lotto) == wantedEreignis)
			timesItHappened++;
	}
	return timesItHappened;
}

int rapper(CLotto lotto)
{
	return lotto.lottoZiehung();
}

int lilpump(CLotto lotto)
{
	return lotto.lotto2Ziehung();
}

int main()
{
	/*CZufall pseudoRand;
	pseudoRand.initialisiere(20);

	vector<int> test = pseudoRand.test(3, 7, 10000);
	for (size_t i = 0; i < test.size(); i++)
	{
		cout << test[i] << endl;
	}

	vector<int> testFalsch = pseudoRand.test_falsch(3, 7, 10000);
	for (size_t i = 0; i < test.size(); i++)
	{
		cout << testFalsch[i] << endl;
	}*/

	/*CLotto lotto = CLotto(100);
	lotto.setTipp(1, 2, 3, 4, 5, 6);
	cout << lotto.lottoZiehung(true) << endl;
	cout << lotto.lotto2Ziehung(true) << endl;*/

	const int monteCarloZiehungen = 1000000;
	CLotto lotto = CLotto(1337);
	lotto.setTipp(2, 6, 9, 13, 28, 42);
	cout << (double)monteCarloStuff(lotto, monteCarloZiehungen, &rapper, 3) / monteCarloZiehungen << endl;
	cout << (double)monteCarloStuff(lotto, monteCarloZiehungen, &lilpump, 3) / monteCarloZiehungen << endl;
	system("PAUSE");
}