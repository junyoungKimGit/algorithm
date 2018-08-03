/*
* main.cpp
*
*  Created on: 2018. 7. 25.
*      Author: HY
*
*      Samsung SW B Type
*
input

5 5
1 2
2 3
3 4
4 5
5 1

3 2
2 3
3 2

output
odd cnt
even cnt


*/

#include <iostream>
#include <cstring>

using namespace std;

#define MAX_V (10000)
#define MAX_E (100000)
#define INF (100000)
int gGraph[MAX_V][MAX_V] = { 0, };
int gVisited[MAX_V] = { 0, };

int gOddsCnt;
int gEvenCnt;

void makeFloyd(int aNodeCnt)
{
	for (int k = 0; k < aNodeCnt; k++)
	{
		for (int i = 0; i < aNodeCnt; i++)
		{
			for (int j = 0; j < aNodeCnt; j++)
			{
				if (gGraph[i][j] > gGraph[i][k] + gGraph[k][j])
					gGraph[i][j] = gGraph[i][k] + gGraph[k][j];
			}
		}
	}
}

void dfs(int aNodeCnt, int aNode, int aEndNode, int * aDepth)
{

	if (aNode == aEndNode)
	{
		cout << "FOUND!!" << endl;
		cout << "Node : " << aNode << " endNode : " << aEndNode << " depth : " << *aDepth << endl;
		if (*aDepth % 2 == 0)
		{
			gEvenCnt++;
		}
		else
		{
			gOddsCnt++;
		}
		return;
	}

	for (int i = 0; i < aNodeCnt; i++)
	{
		if (gGraph[aNode][i] == 1 && gVisited[i] == 0)
		{
			//더 멀어진다
			if (gGraph[i][aEndNode] > gGraph[aNode][aEndNode])
			{
				//Nothing
			}
			else
			{
				cout << "Node : " << aNode << " i : " << i << " depth : " << *aDepth << endl;
				*aDepth = *aDepth + 1;
				gVisited[i] = 1;
				dfs(aNodeCnt, i, aEndNode, aDepth);
				gVisited[i] = 0;
				*aDepth = *aDepth - 1;
			}

		}
	}

	return;
}

void cntOddsEvenPath(int aNodeCnt)
{
	for (int i = 1; i < aNodeCnt; i++)
	{
		memset(gVisited, 0, sizeof(gVisited));
		gVisited[0] = 1;
		int sDepth = 0;

		dfs(aNodeCnt, 0, i, &sDepth);
	}

	cout << "Odds : " << gOddsCnt << endl;
	cout << "Even : " << gEvenCnt + 1 << endl;



}



int main()
{
	int sNodeCnt, sEdgeCnt;

	cin >> sNodeCnt >> sEdgeCnt;

	for (int i = 0; i < sNodeCnt; i++)
	{
		for (int j = 0; j < sNodeCnt; j++)
		{
			if (i != j)
				gGraph[i][j] = INF;
		}
	}

	int sX, sY;
	for (int i = 0; i < sEdgeCnt; i++)
	{
		cin >> sX >> sY;
		gGraph[sX - 1][sY - 1] = 1;
		gGraph[sY - 1][sX - 1] = 1;
	}

	makeFloyd(sNodeCnt);

	for (int i = 0; i < sNodeCnt; i++)
	{
		for (int j = 0; j < sNodeCnt; j++)
		{
			cout << gGraph[i][j] << " ";
		}
		cout << endl;
	}

	cntOddsEvenPath(sNodeCnt);

	return 0;
}
