/*
* main.cpp
*
*  Created on: 2018. 7. 26.
*      Author: HY
*
http://dyngina.tistory.com/16
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int LIS_V1(int aArr[])
{
	int sArrSize = sizeof(aArr) / sizeof(int);
	int sDP[sArrSize] = { 0, };

	int sMax = 0;
	sDP[0] = 1;

	for (int i = 1; i < sArrSize; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (aArr[i] > aArr[j] && sDP[i] < sDP[j] + 1)
				sDP[i] = sDP[j] + 1;
		}
		if (sMax < sDP[i])
		{
			sMax = sDP[i];
		}
	}

	return sMax;
}

//return val : lower index of aArr
int myLowerBound(int aArr[], int aN, int aKey)
{
	int sStart = 0;
	int sEnd = aN;
	int sMid;

	while (sStart < sEnd)
	{
		sMid = (sStart + sEnd) / 2;
		if (aArr[sMid] > aKey)
		{
			sEnd = sMid;
		}
		else
		{
			sStart = sMid + 1;
		}
	}

	return sEnd;
}

int LIS_V2(int aArr[], int aArrSize)
{

	int sDP[aArrSize] = { 0, };

	int sSize = 1;
	sDP[0] = aArr[0];
	int sLowerBoundIdx;

	for (int i = 1; i < aArrSize; i++)
	{
		if (sDP[sSize - 1] < aArr[i])
		{
			sDP[sSize] = aArr[i];
			sSize++;
			continue;
		}

		sLowerBoundIdx = myLowerBound(sDP, sSize, aArr[i]);
		sDP[sLowerBoundIdx] = aArr[i];

	}


	cout << "Final sDP :";
	for (int j = 0; j < sSize; j++)
	{
		cout << sDP[j] << " ";
	}
	cout << endl;

	return sSize;
}

int main(void)
{

	int sArr[9] = { 20, 10, 40, 25, 20, 50, 30, 70, 85 };
	int sRet = LIS_V2(sArr, 9);
	cout << sRet << endl;


	return 0;


}
