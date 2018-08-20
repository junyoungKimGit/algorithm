//2819. 격자판의 숫자 이어 붙이기

#include <iostream>
#include <cmath>

using namespace std;

#define MAX_N (4)

int gBoard[MAX_N][MAX_N];
int gVisited[10000000];
int T;
int MAX;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isRange(int aX, int aY)
{
	if (aX >= 0 && aX < MAX_N && aY >= 0 && aY < MAX_N)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void findSolve(int aX, int aY, int aCnt, int aNum, int aTestCase)
{

	//cout << "X : " << aX << " Y : " << aY << " Cnt : " << aCnt << " Num : " << aNum << endl;
	if (aCnt == 7)
	{
		if (gVisited[aNum] != aTestCase)
		{
			MAX++;
			gVisited[aNum] = aTestCase;

			cout << "FOUND : " << aNum << endl;
			
		}
		return;
	}

	int sX, sY;
	for (int i = 0; i < MAX_N; i++)
	{
		sX = aX + dx[i];
		sY = aY + dy[i];

		if (isRange(sX, sY) == true)
		{
			findSolve(sX, sY, aCnt + 1, aNum * 10 + gBoard[sX][sY], aTestCase);
			//findSolve(sX, sY, aCnt + 1, aNum + (pow(10, aCnt) * gBoard[sX][sY]), aTestCase);
		}
	}

}

int main()
{
	cin >> T;
	
	for (int t = 1; t <= T; t++)
	{
		for (int i = 0; i < MAX_N; i++)
			for (int j = 0; j < MAX_N; j++)
				cin >> gBoard[i][j];
		
		//for i for j
		for (int i = 0; i < MAX_N; i++)
			for (int j = 0; j < MAX_N; j++)
				findSolve(i, j, 1, gBoard[i][j], t);

		cout << "#" << t << " " << MAX << endl;
		MAX = 0;
	}

	cin >> T;
	return 0;
}