#include <iostream>
#include "CMyMatrix.h"
using namespace std;

int main()
{
	CMyMatrix A = CMyMatrix(2, 2);
	A.Set(0, 0, 1);
	A.Set(0, 1, 3);
	A.Set(1, 0, 2);
	A.Set(1, 1, 4);

	CMyVektor x = CMyVektor(2);
	x.Set(0, 2);
	x.Set(1, 4);

	CMyVektor r = A * x;
	cout << "r = " << r.ToString() << endl;
	system("PAUSE");
}