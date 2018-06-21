#include <iostream>
#include <vector>
#include "CZufall.h"
#include "CLotto.h"
using namespace std;

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

	CLotto lotto = CLotto(100);
	lotto.setTipp(1, 2, 3, 4, 5, 6);
	cout << lotto.lottoZiehung(true) << endl;
	cout << lotto.lotto2Ziehung(true) << endl;
	system("PAUSE");
}