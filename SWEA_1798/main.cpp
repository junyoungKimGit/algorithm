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
int gDay;

void push(int aA)
{
	gStack[++gStackIdx] = aA;
}

int pop(void)
{
	return gStack[gStackIdx--];
}

int calcIdx(int aA)
{
	for (int i = 0; i < N; i++)
	{
		if (gStack[i] == aA)
			return i;
	}

	return 0;

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
		sMin = min(sMin, gMap[aHere][i]);
		if (sMin == gMap[aHere][i])
		{
			*aHotelIdx = i;			
		}
	}
	return sMin;
}

void findSolve(int aTime, int aHere, int aPresure, int aTestcase)
{

	int sHotelIdx;
	bool sVisitedSpot = false;

	for (int i = 2; i <= gSpotCnt + 1; i++)
	{
		if (gVisited[i] != aTestcase &&
			(aTime + gMap[aHere][i] + gNode[i].mTime <= MAX_DAY))
		{
			sVisitedSpot = true;
			/*cout << "Here : " << aHere << " There : " << i << endl;
			cout << "CurrenTime : " << aTime << " DistTime : " << gMap[aHere][i] << " JoyTime : " << gNode[i].mTime << endl;*/
			gVisited[i] = aTestcase;
			push(i);
			findSolve(aTime + gMap[aHere][i] + gNode[i].mTime, i, aPresure + gNode[i].mPleasure, aTestcase);
			pop();
			gVisited[i] = 0;			
		}
	}

	if (gDay == M)
	{
		//공항으로 가야 한다.
		if (aTime + gMap[aHere][1] <= MAX_DAY)
		{
			gMaxPleasure = max(gMaxPleasure, aPresure);

			if (gMaxPleasure == aPresure)
			{
				//cout << "MAX VAL : " << gMaxPleasure << endl;	
				
				for (int j = 0; j <= gStackIdx; j++)
				{
					gPleasureArr[j] = gStack[j];
				}
				gVisitedCnt = gStackIdx;
			}
		}
		return;

	}
	else if (sVisitedSpot == false)
	{

		//cout << "DAY : " << aDay << endl;
		for(int j = gSpotCnt+ 2; j <= N; j++)
		{
			if (aTime + gMap[aHere][j] <= MAX_DAY)
			{
				gDay++;				
				push(j);
				findSolve(0, j, aPresure, aTestcase);
				pop();				
				gDay--;
			}
		}

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

	//test stack

	//push(1);
	//push(2);
	//push(3);
	//push(4);
	//cout << pop()<<endl;
	//cout << pop() << endl;
	//push(5);
	//push(6);
	//cout << pop() << endl;
	//cout << pop() << endl;
	//cout << pop() << endl;
	//cout << pop() << endl;

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

		gSpotCnt = 0;
		for (int i = 1; i <= N; i++)
		{
			cin >> sType;
			if (sType == 'P')
			{
				cin >> gNode[i].mTime;
				cin >> gNode[i].mPleasure;
				gSpotCnt++;
			}
		}

		//cout << "Spot cnt : " << gSpotCnt << endl;

		gDay = 1;
		findSolve(0, 1, 0, t);		

		cout << "#" << t << " " << gMaxPleasure<<" ";

		/*cout << "cnt : " << gVisitedCnt << endl;
		*/

		if( gMaxPleasure != 0)
		{ 

			for (int i = 0; i <= gVisitedCnt; i++)
				cout << gPleasureArr[i]<<" ";
			cout << "1";
		}

		cout << endl;

		gVisitedCnt = 0;
		gMaxPleasure = 0;		
		gStackIdx = -1;
	}

	return 0;
}
