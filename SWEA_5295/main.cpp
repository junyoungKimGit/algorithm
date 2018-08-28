//5295. Èê·¯¶ó ½Ã°£! µý Áþ ÇÏ±â

#include <iostream>

using namespace std;

#define MAX_N (100001)

int gMap[3][MAX_N];
int gCntNum[MAX_N];

int T, N, REMOVE_CNT;

void findTargetAndRemove(int aTarget);

void printCnt()
{
	cout << "COUNT NUM : " << endl;
	for (int i = 1; i <= N; i++)
		cout <<i<<": "<<gCntNum[i] << ", ";
	cout << endl;
}

void removeCol(int aCol, int aTarget)
{

	//cout << "REMOVE COL : " << aCol << endl;
	//printCnt();

	for (int i = 0; i < 3; i++)
	{
		gCntNum[gMap[i][aCol]]--;
		gMap[i][aCol] = 0;
		if (gMap[i][aCol] != aTarget)
		{
			if (gCntNum[gMap[i][aCol]] <= 2 && gCntNum[gMap[i][aCol]] >= 0)
			{
				findTargetAndRemove(gMap[i][aCol]);
			}
		}
	}
	REMOVE_CNT++;
}

void findTargetAndRemove(int aTarget)
{
	if (aTarget == 0)
		return;

	//cout << "TARGET : " << aTarget << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (gMap[i][j] == aTarget)
			{
				removeCol(j, aTarget);
				return;
			}
		}
	}
}

int countLeftNum()
{
	int sCnt = 0;

	for (int i = 1; i <= N; i++)
	{
		if (gCntNum[i] > 0)
			sCnt++;
	}

	return sCnt;

}

void findSolve()
{	
	while (N - REMOVE_CNT > 3)
	{
		for (int i = 1; i <= N; i++)
		{
			if (gCntNum[i] <= 2)
			{
				findTargetAndRemove(i);
				continue;
			}
		}
	}
}

int main()
{
	int sInput;

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> sInput;
				gMap[i][j] = sInput;				
				gCntNum[sInput]++;
			}
		}

		findSolve();

		for (int i = 1; i <= N; i++)
		{
			gCntNum[i] = 0;
		}

		cout << "#" << t << " " << REMOVE_CNT << endl;
	}

	cin >> T;

	return 0;
}