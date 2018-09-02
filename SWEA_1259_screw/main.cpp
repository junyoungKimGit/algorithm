//1259.[S / W 문제해결 응용] 7일차 - 금속막대

#include <iostream>

using namespace std;

#define MAX_N (10001)
typedef struct
{
	int mLeft;
	int mRight;
} stScrew;

stScrew gMap[MAX_N];
int gVisited[MAX_N];
int gStack[MAX_N];
int gStackTop = -1;

void push(int aA)
{
	gStack[++gStackTop] = aA;
}

int pop()
{
	return gStack[gStackTop--];
}


int T, N;
bool gIsFound;

//DFS
void DFS(int aCurrent, int aCnt, int aTestcase)
{
	if (aCnt == N || gIsFound == true)
	{
		gIsFound = true;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (gVisited[i] != aTestcase && gMap[aCurrent].mRight == gMap[i].mLeft)
		{
			gVisited[i] = aTestcase;
			push(i);
			DFS(i, aCnt + 1, aTestcase);
			pop();
			gVisited[i] = 0;
		}
	}
}

void findSolve(int aTestcase)
{
	for (int i = 0; i < N; i++)
	{
		gVisited[i] = aTestcase;
		push(i);
		DFS(i, 1, aTestcase);

		if (gIsFound == true)
			return;
		pop();
		gVisited[i] = 0;
	}

}

void pritSolve()
{
	for (int i = 0; i < N; i++)
	{
		cout << gMap[gStack[i]].mLeft << " " << gMap[gStack[i]].mRight << " ";
	}
}

int main()
{
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> gMap[i].mLeft >> gMap[i].mRight;
		}

		findSolve(tc);

		cout << "#" << tc << " ";
		pritSolve();
		cout<< endl;
		gStackTop = -1;
		gIsFound = false;
	}
	cin >> T;

	return 0;
}