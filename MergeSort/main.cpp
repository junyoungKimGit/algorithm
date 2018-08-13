//1966. 숫자를 정렬하자

#include <iostream>

#define MAX_N (51)

using namespace std;

int gNumber[MAX_N];
int gTempNum[MAX_N];

int T, N;

void printNum()
{
	for (int i = 0; i < N; i++)
		cout << gNumber[i] << " ";
	cout << endl;
}

void merge(int aLeft, int aMid, int aRight)
{
	int i, j, k;

	i = aLeft;
	j = aMid + 1;
	k = aLeft;

	/*cout << "aLeft : " << aLeft << " aRight : " << aRight << " aMid : " << aMid << endl;
	printNum();

	if (aLeft == 0 && aRight == 39 && aMid == 19)
		cout << "BREAK";
*/
	while (i <= aMid && j <= aRight)
	{
		if (gNumber[i] <= gNumber[j])
		{
			gTempNum[k] = gNumber[i];
			i++;			
		}
		else
		{
			gTempNum[k] = gNumber[j];
			j++;
		}
		k++;
	}

	//left
	if (i > aMid)
	{
		for (int m = j; m <= aRight; m++)
		{
			gTempNum[k] = gNumber[m];
			k++;
		}
	}

	if (j > aRight)
	{
		for (int m = i; m <= aMid; m++)
		{
			gTempNum[k] = gNumber[m];
			k++;
		}
	}

	for (k = aLeft; k <= aRight; k++)
	{
		gNumber[k] = gTempNum[k];
	}

	/*cout << "END : " << endl;;
	printNum();*/
}

void mergeSort(int aLeft, int aRight)
{
	if (aLeft < aRight)
	{
		int sMid = (aLeft + aRight) / 2;

		mergeSort(aLeft, sMid);
		mergeSort(sMid + 1, aRight);
		merge(aLeft, sMid, aRight);
	}
}

int main()
{
	cin >> T;

	for(int t = 1; t <= T; t++)
	{
		cin >> N;
		for(int i = 0; i < N; i++)
			cin >> gNumber[i];
		mergeSort(0, N - 1);

		cout << "#"<<t<<" ";
		printNum();
	}
	
	//cin >> T;
	

}