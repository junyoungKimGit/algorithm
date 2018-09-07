//4193. 수영대회 결승전 ( 완전 탐색 + 구현 )

#include <iostream>

using namespace std;

#define MAX_N (15)
#define PASSTIME (3)

int T, N, gX, gY, gTime;

int dx[4] = { -1, 0, 1,  0 };
int dy[4] = {  0, 1, 0, -1 };

int gMap[MAX_N][MAX_N];
int gVisited[MAX_N][MAX_N];

int min(int aA, int aB)
{
	return aA > aB ? aB : aA;
}

bool isRange(int aX, int aY)
{
	if (aX > -1 && aX < N && aY > -1 && aY < N && gMap[aX][aY] != 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int waitTime(int aCurrentTime)
{
	int sMod = aCurrentTime % PASSTIME;

	if (sMod == 0)
		return 0;
	else if (sMod == 1)
		return 2;
	else if (sMod == 2)
		return 1;
}

//timeout!
#if 0
//DFS
void findSolve(int aX, int aY, int aTime, int aTestcase)
{

	if (aTime > gTime)
		return;

	//cout << "Current X : " << aX << " aY : " << aY << " aTime : " << aTime << endl;
	if (aX == gX && aY == gY)
	{
		//cout << "FOUND!" << endl;
		gTime = min(aTime, gTime);		
		return;
	}

	int sDX, sDY;
	for (int i = 0; i < 4; i++)
	{
		sDX = aX + dx[i];
		sDY = aY + dy[i];

		if (isRange(sDX, sDY) && gVisited[sDX][sDY] != aTestcase)
		{
			if (gMap[sDX][sDY] == 0)
			{
				gVisited[sDX][sDY] = aTestcase;
				findSolve(sDX, sDY, aTime + 1, aTestcase);
				gVisited[sDX][sDY] = 0;
			}
			else if (gMap[sDX][sDY] == 2)
			{
				gVisited[sDX][sDY] = aTestcase;
				findSolve(sDX, sDY, aTime + waitTime(aTime) + 1, aTestcase);
				gVisited[sDX][sDY] = 0;
			}
		}
	}
}

int main()
{
	
	cin >> T;
	int sStartX, sStartY;

	for (int tc = 1; tc <= T; tc++)
	{
		gTime = 15 * 15 * 15;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> gMap[i][j];
			}
		}

		cin >> sStartX >> sStartY;
		cin >> gX >> gY;

		gVisited[sStartX][sStartY] = tc;
		findSolve(sStartX, sStartY, 0, tc);

		cout << "#" << tc << " " << gTime << endl;

	}

	cin >> T;

	return 0;
}

#endif

//VER2

#define MAX_TIME (15 * 15 * 15)

void initVisit()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			gVisited[i][j] = MAX_TIME;
		}
	}
}


//BFS
void findSolve(int aX, int aY, int aTime, int aTestcase)
{

	int sDX, sDY;
	for (int i = 0; i < 4; i++)
	{
		sDX = aX + dx[i];
		sDY = aY + dy[i];

		if (isRange(sDX, sDY) && (gVisited[sDX][sDY] > aTime))
		{
			if (gMap[sDX][sDY] == 0)
			{
				gVisited[sDX][sDY] = aTime + 1;
				findSolve(sDX, sDY, aTime + 1, aTestcase);
			}
			else
			{
				gVisited[sDX][sDY] = aTime + waitTime(aTime + 1)+ 1;
				findSolve(sDX, sDY, aTime + waitTime(aTime + 1) + 1, aTestcase);
			}
		}
	}
}

void printVisited()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << gVisited[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{

	cin >> T;
	int sStartX, sStartY;

	for (int tc = 1; tc <= T; tc++)
	{
		gTime = MAX_TIME;
		cin >> N;
		initVisit();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> gMap[i][j];				
			}
		}

		cin >> sStartX >> sStartY;
		cin >> gX >> gY;

		gVisited[sStartX][sStartY] = 0;
		findSolve(sStartX, sStartY, 0, tc);

		//printVisited();
		cout << "#" << tc << " " << gVisited[gX][gY] << endl;

	}

	cin >> T;

	return 0;
}
