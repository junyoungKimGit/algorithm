//2806. N-Queen 

#include <iostream>

using namespace std;


int gMap[10][10];

int T, N;
int gMax;

void printMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << gMap[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool checkPlace(int aX, int aY, int aTestCase)
{
	//col
	for (int sCol = aX; sCol >= 0 ; sCol--)
	{
		if (gMap[sCol][aY] == aTestCase)
		{
			return false;
		}
	}

	//right upper diagonal
	int sX = 0;
	int sY = 0;
	for (sX = aX, sY = aY; sX >= 0 && sY < N; sX--, sY++)
	{
		if (gMap[sX][sY] == aTestCase)
		{
			return false;
		}
	}

	//left upper diagonal
	for (sX = aX, sY = aY; sX >= 0 && sY >= 0; sX--, sY--)
	{
		if (gMap[sX][sY] == aTestCase)
		{
			return false;
		}
	}

	return true;
}

void findSolve(int aColIdx, int aTestCase)
{
	if (N == aColIdx)
	{
		gMax++;
		printMap();
		return;
	}

	for (int sRowIdx = 0; sRowIdx < N; sRowIdx++)
	{
		if (checkPlace(aColIdx, sRowIdx, aTestCase))
		{
			gMap[aColIdx][sRowIdx] = aTestCase;
			findSolve(aColIdx + 1, aTestCase);
			gMap[aColIdx][sRowIdx] = 0;
		}
	}


}

int main()
{
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N;

		findSolve(0, t);

		cout << "#" << t << " " << gMax << endl;
		gMax = 0;
	}

	return 0;
}


