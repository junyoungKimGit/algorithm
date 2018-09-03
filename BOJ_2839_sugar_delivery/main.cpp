//BOJ 2839 º≥≈¡ πË¥ﬁ

#include <iostream>

using namespace std;

#define FIVE (5)
#define THREE (3)

int gFiveCnt;
int gThreeCnt;

int findSolve(int aSugar)
{
	int sMaxFive = aSugar / FIVE;
	int sMaxThree = aSugar / THREE;

	for (int i = sMaxFive; i > -1; i--)
	{
		for (int j = sMaxThree; j > -1; j--)
		{
			if (aSugar == i * FIVE + j * THREE)
			{
				return i + j;
			}
		}
	}


	return -1;
}

int main()
{

	int sSugar;

	cin >> sSugar;

	cout << findSolve(sSugar) << endl;	

	return 0;
}