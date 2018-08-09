//2105. [모의 SW 역량테스트] 디저트 카페

#include <iostream>
#include <cstring>

using namespace std;

//upper right, lower right, lower left, upper left
int dx[4] = {-1, 1, 1, -1 };
int dy[4] = {1, 1, -1, -1 };

int MAX;
int N;
int T;
int MAP[20][20];
int VISITEDMAP[20][20];
int VISITEDKIND[100];
int A, B, D;
int MAX_A, MAX_B;
int STARTX, STARTY;

int max(int aA, int aB)
{
	return aA > aB ? aA : aB;
}

bool isWall(int aX, int aY)
{
	if (aX >= 0 && aX < N && aY >= 0 && aY < N )
		return false;
	else
		return true;
}

void findPath(int aX, int aY, int aD, int aCnt)
{
	if (aD == 4 || VISITEDMAP[aX][aY] != 0 || VISITEDKIND[MAP[aX][aY]] != 0)
		return;

	VISITEDMAP[aX][aY] = aCnt;
	VISITEDKIND[MAP[aX][aY]] = 1;

	int sX, sY;
	sX = aX + dx[aD];
	sY = aY + dy[aD];

	if (!isWall(sX, sY))
	{
		if (VISITEDMAP[sX][sY] == 1)
			MAX = max(MAX, aCnt);

		findPath(sX, sY, aD, aCnt + 1);
		findPath(sX, sY, aD + 1, aCnt + 1);
	}

	VISITEDMAP[aX][aY] = 0;
	VISITEDKIND[MAP[aX][aY]] = 0;


}

void findSolve()
{
	for (int i = 1; i < N-1; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			
			STARTX = i;
			STARTY = j;
			findPath(i, j, 0, 1);

			memset(VISITEDKIND, 0, sizeof(VISITEDKIND));
			for (int i = 0; i < N; i++)
			{
				memset(VISITEDMAP[i], 0, sizeof(VISITEDMAP[i]));
			}

		}
	}
}

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> MAP[i][j];
			}
		}

		findSolve();

		if (MAX == 0)
			MAX = -1;
		cout << "#" <<t<<" "<< MAX << endl;
		MAX = 0;
	}
	
	return 0;
}
