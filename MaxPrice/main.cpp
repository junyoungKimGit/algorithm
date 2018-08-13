//1244. [S/W 문제해결 응용] 2일차 - 최대 상금

#include <iostream>

using namespace std;

#define MAX_N (6)

int gNUM[MAX_N];

int T, N, MAX, DIGIT;

int max(int aA, int aB)
{
	return aA > aB ? aA : aB;
}

void swap(int * aA, int * aB)
{
	int sTemp = *aA;
	*aA = *aB;
	*aB = sTemp;
}

int getValue()
{
	int sTempVal = 0;
	for (int i = 0; i <= DIGIT; i++)
	{
		sTempVal = gNUM[i] +sTempVal * 10;
	}

	return sTempVal;

	
}

void findSolve(int aCnt, int aCurr)
{

	//cout << "aCnt : " << aCnt << " aCurr : " << aCurr << endl;
	if (aCnt == 0)
	{
		int sTempResult = 0;

		MAX = max(MAX, getValue());

		return;
	}

	for (int i = aCurr; i <= DIGIT; i++)
	{
		for (int j = i; j <= DIGIT; j++)
		{
			if (i == j)
				continue;
			swap(gNUM[i], gNUM[j]);
			findSolve(aCnt - 1, i);
			swap(gNUM[i], gNUM[j]);

		}
	}
}

int main()
{
	int sNum;
	DIGIT = 0;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> sNum>>N;

		while (sNum / 10)
		{
			gNUM[DIGIT] = sNum % 10;
			sNum /= 10;
			DIGIT++;
		}
		gNUM[DIGIT] = sNum;

		for (int i = 0; i <= DIGIT / 2; i++)
		{
			swap(gNUM[i], gNUM[DIGIT - i]);
		}

		//cout << "INPUT : " << endl;
		//for (int i = 0; i <= sO; i++)
		//	cout << gNUM[i] << " ";
		//cout << endl;

		//cout << "getV : " << endl;
		//cout << getValue();
		

		findSolve(N, 0);

		cout << "#" <<t<< " " << MAX << endl;

		DIGIT = 0;
		MAX = 0;
	}
	cin >> T;
	
	return 0;

}