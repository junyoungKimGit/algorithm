//https://www.acmicpc.net/problem/13308

#include <iostream>

using namespace std;

#define MAX_N (2500+1)
#define MAX_E (4000+1)

int gCost[MAX_N];
int gMap[MAX_E][MAX_E];

int N, E;
int gDP[MAX_N][MAX_N];

int gQueue[MAX_N];
int gQSize;
int gQHead;
int gQTail;

void EnQ(int aA)
{
	int sIdx = (gQTail + 1) % gQSize;
	gQueue[sIdx] = aA;
	gQTail++;
}

int DeQ()
{
	int sData = gQueue[gQHead];
	gQHead = (gQHead + 1) % gQSize;
}

void initDP()
{
	return;
}

void findSolve()
{
	//init DP
	initDP();

	

}
int main()
{
	gQHead = -1;
	gQTail = -1;
	gQSize = MAX_N;

	cin >> N >> E;

	for (int i = 0; i < N; i++)
	{
		cin >> gCost[i];
	}

	int x, y;
	for (int i = 0; i < E; i++)
	{
		cin >> x >> y;
		cin >> gMap[x][y];
	}

	findSolve();


	return 0;
}