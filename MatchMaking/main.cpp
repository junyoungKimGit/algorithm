//4701. 경시대회 매니저의 고민
//http://sangdo913.tistory.com/entry/SW-Expert-Academy-4701-%EA%B2%BD%EC%8B%9C%EB%8C%80%ED%9A%8C-%EB%A7%A4%EB%8B%88%EC%A0%80%EC%9D%98-%EA%B3%A0%EB%AF%BC?category=823156
#include <iostream>

using namespace std;

#define MAX_N (100)
#define MOD (1000000007)

void swap(int aArr[], int aA, int aB)
{
	int sTemp = aArr[aA];
	aArr[aA] = aArr[aB];
	aArr[aB] = sTemp;
}

void printArr(int aArr[], int aStart, int aEnd)
{
	cout << "ARR[ ";
	for (int i = aStart; i < aEnd; i++)
	{
		cout << aArr[i] << " ";
	}
	cout << "]"<<endl;
}

void quickSort(int aArr[], int aStart, int aEnd)
{
	/*cout << "before " << endl;
	printArr(aArr, aStart,aEnd);*/

	int sPivot = aArr[(aStart + aEnd) / 2];
	int sLeft = aStart;
	int sRight = aEnd;

	while (sLeft <= sRight)
	{
		while (aArr[sLeft] < sPivot)
			sLeft++;
		while (aArr[sRight] > sPivot)
			sRight--;

		if (sLeft <= sRight)
		{
			if (sLeft != sRight)
			{
				swap(aArr, sLeft, sRight);
			}
			sLeft++;
			sRight--;
		}
	}

	//cout << "After " << endl;
	//printArr(aArr, aStart, aEnd);

	if (sRight > aStart)
		quickSort(aArr, aStart, sRight);

	if (sLeft < aEnd)
		quickSort(aArr, sLeft, aEnd);
}

void merge(int aArr[], int aLeft, int aMid, int aRight)
{
	int sTempArr[MAX_N];

	int i, j, k, m;
	i = aLeft;
	j = aMid + 1;
	k = aLeft;

	while (i <= aMid && j <= aRight)
	{
		if (aArr[i] < aArr[j])
		{
			sTempArr[k] = aArr[i];			
			i++;
		}
		else
		{
			sTempArr[k] = aArr[j];			
			j++;
		}
		k++;
	}

	if (i <= aMid)
	{
		for (m = i; m <= aMid; m++)
		{
			sTempArr[k] = aArr[m];
			k++;
		}
	}
	else
	{
		for (m = j; m <= aRight; m++)
		{
			sTempArr[k] = aArr[m];
			k++;
		}
	}

	for (m = aLeft; m <= aRight; m++)
	{
		aArr[m] = sTempArr[m];
	}
}

void mergeSort(int aArr[], int aLeft, int aRight)
{
	if (aLeft < aRight)
	{
		int sMid = (aLeft + aRight) / 2;
		mergeSort(aArr, aLeft, sMid);
		mergeSort(aArr, sMid + 1, aRight);
		merge(aArr, aLeft, sMid, aRight);
	}
}

int T, N;

int gATeam[MAX_N];
int gBTeam[MAX_N];
int gDP[MAX_N+1][MAX_N+1];

void findSolve()
{

}

//int gArr[8] = { 12, 1, 5, 10, 2, 8, 3, 4 };
int main()
{

	//printArr(gArr, 0, 8);
	//mergeSort(gArr, 0, 7);
	////quickSort(gArr, 0, 7);
	//printArr(gArr, 0, 8);


	cin >> T;

	for (int t = 0; t <= T; t++)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> gATeam[i];

		for (int i = 0; i < N; i++)
			cin >> gBTeam[i];

		mergeSort(gATeam, 0, N-1);
		mergeSort(gBTeam, 0, N-1);

		findSolve();

		cout << "#" << t << " " << gDP[N][N];
	}

	cin >> T;
	return 0;
}


