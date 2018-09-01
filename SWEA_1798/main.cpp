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

int gStack[MAX_N];
int gStackIdx = -1;

int T, N, M;
int gMaxPleasure;
int gPleasureArr[MAX_N];
int gVisitedCnt;
int gSpotCnt;

void push(int aA)
{
	gStack[++gStackIdx] = aA;
}

int pop(void)
{
	return gStack[gStackIdx--];
}

int max(int aA, int aB)
{
	return aA > aB ? aA : aB;
}

int min(int aA, int aB)
{
	return aA > aB ? aB : aA;
}

int findNearestHolte(int aHere, int * aHotelIdx)
{
	int sMin = MAX_DAY;
	for (int i = gSpotCnt; i <= N; i++) 
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
		for (int i = 2; i < gSpotCnt; i++)
		{
			if (gVisited[i] != aTestcase &&
				(aTime + gMap[aHere][i] + gNode[i].mTime + gMap[i][1] <= MAX_DAY))
			{
				/*cout << "Here : " << aHere << " There : " << i << endl;
				cout << "CurrenTime : " << aTime << " DistTime : " << gMap[aHere][i] << " JoyTime : " << gNode[i].mTime << endl;*/
				gVisited[i] = aTestcase;
				push(i);
				findSolve(aDay, aTime + gMap[aHere][i] + gNode[i].mTime, i, aPresure + gNode[i].mPleasure, aTestcase);
				pop();
				gVisited[i] = 0;
				
			}			
		}

		gMaxPleasure = max(gMaxPleasure, aPresure );				
		if (gMaxPleasure == aPresure)
		{
			//cout << "MAX VAL : " << gMaxPleasure << endl;	
			int j = 0;
			for (j = 0; j < gStackIdx; j++)
			{
				gPleasureArr[j] = gStack[j];
			}
			gVisitedCnt = j;
		}				

	}
	else
	{
		//호텔로 가야한다.
		for (int i = 2; i < gSpotCnt; i++)
		{
			if (gVisited[i] != aTestcase &&
				(aTime + gMap[aHere][i] + gNode[i].mTime + findNearestHolte(i, &sHotelIdx) <= MAX_DAY))
			{
				/*cout << "Here : " << aHere << " There : " << i << endl;
				cout << "CurrenTime : " << aTime << " DistTime : " << gMap[aHere][i] << " JoyTime : " << gNode[i].mTime << endl;*/
				gVisited[i] = aTestcase;
				push(i);
				findSolve(aDay, aTime + gMap[aHere][i] + gNode[i].mTime, i, aPresure + gNode[i].mPleasure, aTestcase);
				pop();
				gVisited[i] = 0;
			}			
		}

		//cout << "DAY : " << aDay << endl;
		findNearestHolte(aHere, &sHotelIdx);
		findSolve(aDay + 1, 0, sHotelIdx, aPresure, aTestcase);

	}


}

void printDist()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << gMap[i][j] << " ";
		}
		cout << endl;
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

		for (int i = 1; i <= N; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				cin >> sDist;
				gMap[i][j] = sDist;
				gMap[j][i] = sDist;
			}

		}

		//printDist();

		for (int i = 0; i < N; i++)
		{
			gMap[i][i] = MAX_DAY;
		}

		gSpotCnt = 2;
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

		//cout << "Spot cnt : " << gSpotCnt << endl;

		findSolve(1, 0, 1, 0, t);
		

		cout << "#" << t << " " << gMaxPleasure<<" ";

		/*cout << "cnt : " << gVisitedCnt << endl;

		for (int i = 0; i <= gVisitedCnt; i++)
			cout << gPleasureArr[i]<<" ";
		cout<<"1";*/

		cout << endl;

		gVisitedCnt = 0;
		gMaxPleasure = 0;		
		gStackIdx = -1;
	}

	cin >> T;

	return 0;
}
