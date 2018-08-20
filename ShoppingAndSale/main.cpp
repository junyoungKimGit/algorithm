//4050. 재관이의 대량 할인

#include <iostream>

using namespace std;

#define MAX_N (100000)

long long gMax;
int gPrice[MAX_N];
int T, N;

void merge(int aArr[], int aLeft, int aMid, int aRight)
{
	int i, j, k, m;

	i = aLeft;
	j = aMid + 1;
	k = aLeft;

	int sTempArr[MAX_N];

	while (i <= aMid && j <= aRight)
	{
		if (aArr[i] <= aArr[j])
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

void findSolve()
{
	int sMod= N % 3;

	for (int i = 0; i < N; i++)
	{
		if (i % 3 != sMod)
		{
			gMax += gPrice[i];
		}
	}
}
 
//int gTempArr[10] = { 10, 5, 3, 8, 3, 9, 1, 2, 7, 4 };

int main()
{
	//mergeSort(gTempArr, 0, 10-1);
	//for (int i = 0; i < 10; i++)
	//	cout << gTempArr[i] << " ";

	cin >> T;
	
	for (int t = 1; t <= T; t++)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> gPrice[i];

		mergeSort(gPrice, 0, N - 1);

		findSolve();

		cout << "#" << t << " " << gMax << endl;
		gMax = 0;


	}

	cin >> T;
	return 0;
}