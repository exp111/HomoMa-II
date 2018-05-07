#include <iostream>
#include "CMyVektor.h"

using namespace std;

int main()
{
	CMyVektor myVec = CMyVektor(5);
	cout << "Dimension: " << myVec.GetDimension() << endl;
	myVec.Set(0, 3);
	myVec.Set(1, 4);
	cout << "Length: " << myVec.GetLength() << endl;
	CMyVektor newVec = myVec * 3;
	newVec.print();
	system("PAUSE");
}