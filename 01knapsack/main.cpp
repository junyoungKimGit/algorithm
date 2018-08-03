//3282. 0 / 1 Knapsack

#include <iostream>
#include <cstring>

using namespace std;

#define MAX_N (100)
#define MAX_VOL (1000)

typedef struct stObject
{
	int mValue;
	int mVolume;
};

stObject gObject[MAX_N];
//int gKeep[MAX_N] = { 0, };
int gMaxValue = 0;
//int gDP[MAX_N][MAX_VOL] = { 0, };

int max(int a, int b)
{
	return (a > b) ? a : b;
}

/*
void solveMaxValue(int aObjCnt, int aLimit, int aCurrVol, int aCurrVal)
{
if (aCurrVol > aLimit)
return;

if (gMaxValue < aCurrVal)
gMaxValue = aCurrVal;

for (int i = 0; i < aObjCnt; i++)
{
if (gKeep[i] == 0)
{
gKeep[i] = 1;
solveMaxValue(aObjCnt, aLimit, aCurrVol + gObject[i].mVolume, aCurrVal + gObject[i].mValue);
gKeep[i] = 0;
}
}
}
*/
void solveMaxValueWithDFS(int aObjCnt, int aLimit, int aCurrVol, int aCurrVal, int aIdx)
{
	if (aCurrVol + gObject[aIdx].mVolume > aLimit)
		return;

	if (aCurrVal + gObject[aIdx].mValue > gMaxValue)
		gMaxValue = aCurrVal + gObject[aIdx].mValue;

	if (aIdx == aObjCnt)
		return;

	solveMaxValueWithDFS(aObjCnt, aLimit, aCurrVol, aCurrVal, aIdx + 1);
	solveMaxValueWithDFS(aObjCnt, aLimit, aCurrVol + gObject[aIdx].mVolume, aCurrVal + gObject[aIdx].mValue, aIdx + 1);

}
//
//int solveMaxValueWithDP(int aObjCnt, int aLimit)
//{
//  for (int i = 0; i <= aObjCnt; i++)
//      gDP[i][0] = 0;
//  
//  for (int i = 0; i <= aLimit; i++)
//      gDP[0][i] = 0;
//
//  for (int i = 1; i <= aObjCnt; i++)
//  {
//      for (int j = 0; j <= aLimit; j++)
//      {
//          if (gObject[i - 1].mVolume > j)
//          {
//              gDP[i][j] = gDP[i - 1][j];
//          }
//          else
//          {
//              gDP[i][j] = max(gDP[i - 1][j], gObject[i - 1].mValue + gDP[i - 1][j - gObject[i - 1].mVolume]);
//          }
//      }
//  }
//
//  return gDP[aObjCnt][aLimit];
//}

int solveMaxValueWithDPRecursively(int aObjectCnt, int aLimit)
{
	if (aObjectCnt == 0 || aLimit == 0)
		return 0;

	if (gObject[aObjectCnt - 1].mVolume > aLimit)
	{
		solveMaxValueWithDPRecursively(aObjectCnt - 1, aLimit);
	}
	else
	{
		return max(solveMaxValueWithDPRecursively(aObjectCnt - 1, aLimit),
			gObject[aObjectCnt - 1].mValue + solveMaxValueWithDPRecursively(aObjectCnt - 1, aLimit - gObject[aObjectCnt - 1].mVolume));
	}
}

int main()
{

	//sample
	//cObject sObj[4];
	//int sLimit = 5;

	//gObject[0].mVolume = 1;
	//gObject[0].mValue = 2;
	//gObject[1].mVolume = 3;
	//gObject[1].mValue = 2;
	//gObject[2].mVolume = 4;
	//gObject[2].mValue = 4;
	//gObject[3].mVolume = 2;
	//gObject[3].mValue = 3;

	int sT;

	cin >> sT;

	int sN, sLimit;

	for (int t = 1; t <= sT; t++)
	{
		cin >> sN >> sLimit;
		for (int i = 0; i < sN; i++)
		{
			cin >> gObject[i].mVolume >> gObject[i].mValue;
		}
		//solveMaxValue(sN, sLimit, 0, 0);
		//for (int i = 0; i < sN; i++)
		//{
		//  solveMaxValueWithDFS(sN, sLimit, 0, 0, i);
		//}

		/*cout << "#" << t << " " << solveMaxValueWithDP(sN,sLimit) << endl;*/
		cout << "#" << t << " " << solveMaxValueWithDPRecursively(sN, sLimit) << endl;

		gMaxValue = 0;
		//memset(gKeep, 0x00, sizeof(gKeep));
	}

	return 0;


}