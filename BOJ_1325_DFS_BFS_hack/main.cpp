//BOJ 1325 효율적인 해킹

#include <iostream>

using namespace std;

#define MAX_N (10001)

short gMap[MAX_N][MAX_N];
short gVisited[MAX_N];
short gRank[MAX_N];

int N, M;

int max(int aA, int aB)
{
	return aA > aB ? aA : aB;
}

void dfs(int aCurrent, int aCnt, int aTestcase)
{
	for (int i = 1; i <= N; i++)
	{
		if (gVisited[i] != aTestcase && gMap[aCurrent][i] == 1)
		{
			dfs(i, aCnt + 1, aTestcase);
		}
	}

	gRank[aCurrent] = max(gRank[aCurrent], aCnt);
}

void findSolve()
{
	for (int i = 1; i <= N; i++)
	{
		if(gRank[i] == -1)
			dfs(i, 0, i);
	}
}

int main()
{
	int sChild = 0;
	int sParent = 0;
	int sMaxRank = 0;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> sChild >> sParent;
		gMap[sChild][sParent] = 1;
		gRank[sChild] = -1;
	}

	findSolve();

	for (int i = 1; i <= N; i++)
	{
		sMaxRank = max(sMaxRank, gRank[i]);		
		//cout << "gRank : " << gRank[i] << endl;
	}

	

	bool sIsFirst = true;

	for (int i = 1; i <= N; i++)
	{
		if (sMaxRank == gRank[i])
		{
			if (sIsFirst == false)
			{
				cout << " ";
			}
			cout << i;
			sIsFirst = false;
		}
	}
	
	
	return 0;
}