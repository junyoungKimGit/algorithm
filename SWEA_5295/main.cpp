//5295. Èê·¯¶ó ½Ã°£! µý Áþ ÇÏ±â

#include <iostream>

using namespace std;

#define MAX_N (100001)

int gMap[3][MAX_N];
int gCntNum[MAX_N];

int T, N, REMOVE_CNT, REMOVE_NUMBER_CNT;

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
	int sPrevVal = 0;
	for (int i = 0; i < 3; i++)
	{
		gCntNum[gMap[i][aCol]]--;
		sPrevVal = gMap[i][aCol];
		gMap[i][aCol] = 0;
		//if (sPrevVal != aTarget)
		//{
		//	if (gCntNum[sPrevVal] <= 2 && gCntNum[sPrevVal] >= 0)
		//	{
		//		findTargetAndRemove(gMap[i][aCol]);
		//	}
		//}
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
	while(countLeftNum() > 3)
	{
		for (int i = 1; i <= N; i++)
		{
			if (gCntNum[i] <= 2 && gCntNum[i] >0)
			{
				findTargetAndRemove(i);
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
		REMOVE_CNT = 0;
	}

	cin >> T;

	return 0;
}