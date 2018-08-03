/*
* main.cpp
*
*  Created on: 2018. 7. 19.
*      Author: HY
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned long gDivided = 1000000007;

unsigned long countPop(unsigned long aPR[50][3], int aMachNum, int aPopCnt)
{
	unsigned long sPop[50] = { 0, };
	unsigned long sSum[50] = { 0, };

	unsigned long sTotalPopcornCnt = 0;

	for (int i = 0; i < aMachNum; i++)
	{
		sPop[i] = 1;
	}

	for (int i = 0; i < aPopCnt; i++)
	{
		int j;
		for (j = 0; j < aMachNum; j++)
		{
			if (j == 0)
			{
				sSum[j] = aPR[j][1] * sPop[j] + aPR[j + 1][0] * sPop[j + 1];

			}
			else if (j == aMachNum - 1)
			{
				sSum[j] = aPR[j][1] * sPop[j] + aPR[j - 1][2] * sPop[j - 1];
			}
			else
			{
				sSum[j] = aPR[j][1] * sPop[j] + aPR[j - 1][2] * sPop[j - 1] + aPR[j + 1][0] * sPop[j + 1];
			}
			//
			if (j > 0)
			{
				//				cout<<sSum[j-1]<<endl;
				sPop[j - 1] = sSum[j - 1] %= gDivided;
				sTotalPopcornCnt += sPop[j - 1];
			}
		}
		//
		//		cout<<"JJJJ: "<<j<<"  "<<sSum[j-1]<<endl;
		sPop[j - 1] = sSum[j - 1] %= gDivided;
		sTotalPopcornCnt += sPop[j - 1];

		//		for(int j = 0; j < aMachNum; j++)
		//		{
		//			sPop[j] = sSum[j]  %= gDivided;
		//			sTotalPopcornCnt += sPop[j];
		//		}

	}

	return sTotalPopcornCnt;
}

int main()
{
	int sTestNum;

	cin >> sTestNum;


	int sMachineNum;
	int sPopCnt;


	unsigned long sResult;

	unsigned long sPR[50][3];


	for (int i = 0; i < sTestNum; i++)
	{
		cin >> sMachineNum >> sPopCnt;

		for (int j = 0; j < sMachineNum; j++)
		{
			cin >> sPR[j][0] >> sPR[j][1] >> sPR[j][2];
		}

		sResult = countPop(sPR, sMachineNum, sPopCnt);
		cout << sResult % gDivided << endl;

	}
	return 0;
}
