//BOJ 7576 tomato

#include <iostream>

using namespace std;

#define MAX_N (1001)

int gMap[MAX_N][MAX_N];
int gNextMap[MAX_N][MAX_N];

int dx[4] = { -1, 0, 1,  0};
int dy[4] = { 0, 1, 0, -1 };

int R, C;
int gTime;
int gChageCnt;

void printBox()
{
	cout << "PRINTBOX" << endl;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << gMap[i][j] << " ";
		}
		cout << endl;
	}
}

bool isRange(int x, int y)
{
	if (x > -1 && x < R && y > -1 && y < C)
		return true;
	else
		return false;
}

bool isChange(int x, int y)
{
	int ddx = 0;
	int ddy = 0;
	bool sIsChaged = false;

	for (int i = 0; i < 4; i++)
	{
		ddx = x + dx[i];
		ddy = y + dy[i];

		if (isRange(ddx, ddy))
		{
			if (gMap[ddx][ddy] == 0)
			{
				sIsChaged = true;
				
				gMap[ddx][ddy] = gTime + 1;
				gChageCnt++;
				
			}

		}
	}

	return sIsChaged;
}

void copyMapAndReset()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			gMap[i][j] = gMap[i][j] | gNextMap[i][j];
			gNextMap[i][j] = 0;
		}
	}
}

void bfs()
{
	bool sIsChage = false;

	do
	{	
		sIsChage = false;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (gMap[i][j] == gTime)
				{
					if (isChange(i, j))
						sIsChage = true;
				}
			}
		}
		gTime++;
		/*cout << "Time " << gTime<<endl;*/
		//printBox();
		//copyMapAndReset();
	} while (sIsChage == true);
	gTime--;
}

int main()
{
	int sMaxBox = 0;
	int sState = 0;
	cin >> C >> R;
	gTime = 1;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> sState;
			gMap[i][j] = sState;

			if (sState == 0)
				sMaxBox++;
		}
	}

	bfs();

	//cout << "MAXBOX : " << sMaxBox << " CHNCNT : " << gChageCnt << endl;
	if (gChageCnt == sMaxBox)
		cout << --gTime;
	else
		cout << "-1";

	cin >> C;

	return 0;
}