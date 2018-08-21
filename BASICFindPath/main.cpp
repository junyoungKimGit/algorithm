//1219.[S / W 문제해결 기본] 4일차 - 길찾기

#include <iostream>

using namespace std;

#define MAX_N (100)
#define DEST (99)

int gMap[MAX_N][MAX_N];

int T, N;
int gExistPath;

void printMap()
{
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_N; j++)
		{
			cout << gMap[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void isExistPath(int aCurrNode, int aTC)
{
	//cout << "Currn Node : " << aCurrNode << endl;
	if (aCurrNode == DEST)
	{
		gExistPath = 1;
		return;
	}

	for (int i = 0; i < MAX_N; i++)
	{
		if (gMap[aCurrNode][i] == aTC)
		{
			isExistPath(i, aTC);
		}
	}
}

int main()
{
	
	int x, y;
	for (int t = 1; t <= 10; t++)
	{
		cin >> T >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> x >> y;
			gMap[x][y] = T;
		}

		//printMap();
		gExistPath = 0;
		isExistPath(0, T);
		cout << "#" << T << " " << gExistPath << endl;
		
	}

	return 0;
}