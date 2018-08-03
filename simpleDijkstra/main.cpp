/*
* main.cpp
*
*  Created on: 2018. 7. 24.
*      Author: JY
*
*      ROUTING (algorithm book)
*
*
input

7 14
0 1 1.3
0 2 1.1
0 3 1.24
3 4 1.17
3 5 1.24
3 1 2
1 2 1.31
1 2 1.26
1 4 1.11
1 5 1.37
5 4 1.24
4 6 1.77
5 6 1.11
2 6 1.2

out
1.32
*/

#include <iostream>

using namespace std;

#define MAX_N (10000)
#define MAX_E (20000)

#define INF (10000)

float gGraph[MAX_N][MAX_N];
int gVisited[MAX_N] = { 0, };
float gDist[MAX_N];

int dijkstra(int aNodeCnt, int aStart)
{
	gDist[aStart] = 1;

	for (int i = 0; i < aNodeCnt; i++)
	{
		int sMin = INF;
		int sHere;
		for (int j = 0; j < aNodeCnt; j++)
		{
			if (sMin > gDist[j] && gVisited[j] == 0)
			{
				sMin = gDist[j];
				sHere = j;
			}
		}

		if (sMin == INF)
			continue;

		gVisited[sHere] = 1;

		for (int j = 0; j < aNodeCnt; j++)
		{
			if (gDist[j] > gDist[sHere] * gGraph[sHere][j])
				gDist[j] = gDist[sHere] * gGraph[sHere][j];

		}
	}
}

int main()
{
	int sNodeCnt;
	int sEdgeCnt;
	cin >> sNodeCnt >> sEdgeCnt;

	for (int i = 0; i < sNodeCnt; i++)
	{
		for (int j = 0; j < sNodeCnt; j++)
		{
			gGraph[i][j] = INF;
		}
		gDist[i] = INF;
	}

	int sX, sY;
	float sW;
	for (int i = 0; i < sEdgeCnt; i++)
	{
		cin >> sX >> sY >> sW;
		gGraph[sX][sY] = sW;
	}
	//	for(int i = 0; i < sNodeCnt; i++)
	//	{
	//		for(int j = 0; j < sNodeCnt; j++)
	//		{
	//			cout<<gGraph[i][j]<<" ";
	//		}
	//		cout<<endl;
	//	}

	dijkstra(sNodeCnt, 0);

	//	for(int j = 0; j < sNodeCnt; j++)
	//	{
	//		cout<<gDist[j]<<" ";
	//	}
	//	cout<<endl;

	float sResult = gDist[sNodeCnt - 1];
	cout.precision(6);
	cout << sResult;


	return 0;
}


