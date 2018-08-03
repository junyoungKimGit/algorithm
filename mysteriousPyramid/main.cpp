//4112 이상한 피라미드 탐험

#include <iostream>

using namespace std;

#define MAX_N (10000)

int gLevelFirstVal[200];
int gMaxLevel;

void initTree()
{
	int sStart = 1;
	int sFirstVal = sStart;
	int sLevel = 1;
	gLevelFirstVal[0] = 1;

	while (sFirstVal < MAX_N)
	{
		sFirstVal += sLevel;
		gLevelFirstVal[sLevel] = sFirstVal;
		sLevel++;
	}
	gMaxLevel = sLevel;

	return;
}

void swap(int &aA, int &aB)
{
	int temp = aA;
	aA = aB;
	aB = temp;
}
int findPath(int aStart, int aEnd)
{	
	int sResult = 0;
	if (aStart > aEnd)
		swap(aStart, aEnd);

	int sStartLevel = 0;
	int sEndLevel = 0;

	//cout << aStart << " " << aEnd<<endl;

	for (int i = 0; i < gMaxLevel-1; i++)	
	{
		//cout << i << " " << gLevelFirstVal[i] << " " << gLevelFirstVal[i + 1] << endl;
		if (gLevelFirstVal[i] <= aStart && gLevelFirstVal[i + 1] > aStart)
		{
			sStartLevel = i;
		}

		if (gLevelFirstVal[i] <= aEnd && gLevelFirstVal[i + 1] > aEnd)
		{
			sEndLevel = i;			
			break;
		}
	}

	//cout << " start L " << sStartLevel << " End L : " << sEndLevel << endl;

	if (sStartLevel == sEndLevel)
		return aEnd - aStart;

	sResult += (sEndLevel -sStartLevel); //diff levels

	int sLeft = gLevelFirstVal[sEndLevel] - gLevelFirstVal[sStartLevel] + aStart;
	int sRight = sLeft + sResult;

	cout << sLeft << " " << sRight<<endl;

	if (aEnd < sLeft)
		sResult += (sLeft - aEnd);
	else if( aEnd > sRight)
		sResult += (aEnd - sRight);

	return sResult;
}

int main()
{
	initTree();
	
	int sTest;

	cin >> sTest;

	int sStart, sEnd;
	for (int i = 0; i < sTest; i++)
	{
		cin >> sStart >> sEnd;
		cout << "#" << i + 1 << " " << findPath(sStart, sEnd) << endl;
	}

	return 0;
}