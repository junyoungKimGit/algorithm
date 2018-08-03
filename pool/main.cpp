//1952. [모의 SW 역량테스트] 수영장

#include <iostream>
#include <cstring>

using namespace std;

#define FEE_CNT (4)
#define MONTH_CNT (12)
#define MAX_VALUE (100000)
#define DECEMBER (12)

int gMinPay = MAX_VALUE;

void findSolve(int aFee[], int aPlan[], int aCurrPay, int aMonth)
{
	//cout << "Month : "<< aMonth<<" Pay : "<< aCurrPay<< endl;
	if (aMonth > DECEMBER -1)
	{
		if (gMinPay > aCurrPay)
			gMinPay = aCurrPay;
		return;
	}

	findSolve(aFee, aPlan, aFee[0] * aPlan[aMonth] + aCurrPay, aMonth + 1);
	findSolve(aFee, aPlan, aFee[1] + aCurrPay, aMonth + 1);
	findSolve(aFee, aPlan, aFee[2] + aCurrPay, aMonth + 3);

}

int main()
{
	int sMax;
	int sFee[4];// = { 10, 40, 100, 300 };
	int sPlan[MONTH_CNT];// = { 0, 0, 2, 9, 1, 5, 0, 0, 0, 0, 0, 0 };
/*
	findSolve(sFee, sPlan, 0, 0);
	cout << gMinPay;*/

	//sample end

	int sT;
	cin >> sT;
	int sPay;
	for (int t = 0; t < sT; t++)
	{
		for (int j = 0; j < FEE_CNT; j++)
		{
			cin >> sFee[j];
		}
		for (int i = 0; i < DECEMBER; i++)
		{
			cin >> sPlan[i];
		}

		findSolve(sFee, sPlan, 0, 0);

		sPay = gMinPay < sFee[3] ? gMinPay : sFee[3];
		cout << "#" << t + 1 << " " << sPay << endl;

		gMinPay = MAX_VALUE;


	}
	return 0;
}