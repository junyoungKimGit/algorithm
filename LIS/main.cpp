//http://dyngina.tistory.com/16
//3307. 최장 증가 부분 수열

#include <iostream>

using namespace std;

#define MAX_N (1001)

unsigned int gArr[MAX_N];
int T, N;

//O(N^2)
int LIS_V1(int aArr[])
{
	int sArrSize = sizeof(aArr) / sizeof(int);
	int sDP[MAX_N] = { 0, };

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

//return val : lower index of aArr for LISV2
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

//O(NLOGN)
int LIS_V2(unsigned int aArr[], int aArrSize)
{

	int sDP[MAX_N] = { 0, };

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


	//cout << "Final sDP :";
	//for (int j = 0; j < sSize; j++)
	//{
	//	cout << sDP[j] << " ";
	//}
	//cout << endl;

	return sSize;
}

int main(void)
{

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> gArr[i];
		}

		cout << "#" << t << " " << LIS_V2(gArr, N) << endl;
	}

	//cin >> T;


	return 0;


}
