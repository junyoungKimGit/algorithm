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
	if (aX > -1 && aX < N && aY > -1 && aY < N)
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
		return 2;
	else if (sMod == 1)
		return 1;
	else if (sMod == 2)
		return 0;
}

//DFS
void findSolve(int aX, int aY, int aTime, int aTestcase)
{
	//cout << "Current X : " << aX << " aY : " << aY << " aTime : " << aTime << endl;
	if (aX == gX && aY == gY)
	{
		//cout << "FOUND!" << endl;
		gTime = min(aTime, gTime);		
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