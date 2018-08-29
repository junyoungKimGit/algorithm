//1798. 범준이의 제주도 여행 계획

#include <iostream>

using namespace std;

#define MAX_N (36)
#define MAX_DAY (540)

int gMap[MAX_N][MAX_N];

enum
{
	eAirPort = 0,
	eHotel,
	eSpot
};

typedef struct 
{
	int mType;
	int mPleasure;
	int mTime;
	int mX;
	int mY;

} Node;

Node gNode[MAX_N];
int gVisited[MAX_N];

int T, N, M;
int gMaxPleasure;
int gPleasureArr[MAX_N];
int gVisitedCnt;
int gSpotCnt;

int max(int aA, int aB)
{
	return aA > aB ? aA : aB;
}

int min(int aA, int aB)
{
	return aA > aB ? aA : aB;
}

int findNearestHolte(int aHere, int * aHotelIdx)
{
	int sMin = MAX_DAY;
	for (int i = gSpotCnt + 1; i < N; i++) 
	{
		if (sMin == min(sMin, gMap[aHere][i]))
			*aHotelIdx = i;
		sMin = min(sMin, gMap[aHere][i]);
	}

	return sMin;
}

void findSolve(int aDay, int aTime, int aHere, int aPresure, int aTestcase)
{
	int sHotelIdx;

	if (aDay == M)
	{
		//공항으로 가야 한다.
		for (int i = 1; i < gSpotCnt; i++)
		{
			if (gVisited[i] != aTestcase &&
				(gMap[aHere][i] + gNode[i].mTime + gMap[i][0] <= MAX_DAY))
			{
				gVisited[i] = aTestcase;
				findSolve(aDay, aTime + gMap[aHere][i] + gNode[i].mTime, i, aPresure + gNode[i].mPleasure, aTestcase);
				gVisited[i] = 0;
			}
			else
			{
				gMaxPleasure = max(gMaxPleasure, aPresure );
				return;
			}
		}

	}
	else
	{
		//호텔로 가야한다.

		for (int i = 1; i < gSpotCnt; i++)
		{
			if (gVisited[i] != aTestcase &&
				(gMap[aHere][i] + gNode[i].mTime + findNearestHolte(i, &sHotelIdx) <= MAX_DAY))
			{
				gVisited[i] = aTestcase;
				findSolve(aDay, aTime + gMap[aHere][i] + gNode[i].mTime, i, aPresure + gNode[i].mPleasure, aTestcase);
				gVisited[i] = 0;
			}
			else
			{
				findNearestHolte(aHere, &sHotelIdx);
				findSolve(aDay + 1, 0, sHotelIdx, aPresure, aTestcase);
			}
		}
	}


}

int main()
{
	cin >> T;

	int sDist;
	char sType;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				cin >> sDist;
				gMap[i][j] = sDist;
				gMap[j][i] = sDist;
			}

		}
		for (int i = 0; i < N; i++)
		{
			gMap[i][i] = MAX_DAY;
		}

		for (int i = 0; i < N; i++)
		{
			cin >> sType;
			if (sType == 'P')
			{
				cin >> gNode[gSpotCnt].mTime;
				cin >> gNode[gSpotCnt].mPleasure;
				gSpotCnt++;
			}
		}

		findSolve(0, 0, 0, 0, t);
		

		cout << "#" << t << " " << gMaxPleasure;

		for (int i = 0; i < gVisitedCnt; i++)
			cout << gPleasureArr[i];
		cout << endl;

		gVisitedCnt = 0;
		gMaxPleasure = 0;
		gSpotCnt = 0;
	}

	cin >> T;

	return 0;
}
