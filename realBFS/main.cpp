/*
* main.cpp
*
*  Created on: 2018. 7. 20.
*      Author: HY
*
*      백준 2644 촌수 계산 응용
*
*      1855. 영준이의 진짜 BFS
*/

#if 1
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

//using std::cin;
//using std::cout;
//using std::endl;
using namespace std;

#define MAX_V (10000)
#define MAX_E (10000)

//int gGraph[MAX_V][MAX_V] ={0,};
int gDepth[MAX_V] = { 0, };
int gParents[MAX_V][17] = { -1, };

queue<int> gQ;
vector <vector<int>> gVector(MAX_V);

int calPathToAnc(int aPrev, int aCurrV)
{
	int sPathCnt = 0;

	if (gDepth[aPrev] == gDepth[aCurrV])
	{
		for (int i = gDepth[aCurrV] - 1; i > 0; i--)
		{
			if (gParents[aPrev][i] == gParents[aCurrV][i])
			{
				return gDepth[i];
			}
		}
	}
	else if (aPrev == gParents[aCurrV][0])
	{
		return gDepth[aPrev];
	}
	else
	{
	}

	return sPathCnt;
}



int BFSwithDepth(int aV, int aVNum)
{
	gQ.push(aV);

	int sPathCnt = 0;

	int sPrev = aV;
	int sCurrV = aV;
	int sCalAnc;
	int sLevel = 0;

	while (!gQ.empty())
	{
		sCurrV = gQ.front();
		gQ.pop();


		for (int i = 0; i < gVector[sCurrV].size(); i++)
		{
			//			gQ.push(i);
			gQ.push(gVector[sCurrV][i]);
			//			gDepth[i] = gDepth[sCurrV]+1;

			//			cout<<"Queue Curr: "<<sCurrV<<" pop : "<<i<<" depth : "<< gDepth[i]<<endl;
		}

		//cal
		sCalAnc = calPathToAnc(sPrev, sCurrV);
		sPathCnt = sPathCnt + gDepth[sPrev] + gDepth[sCurrV] - sCalAnc * 2;


		//		cout<<"Queue pop R : "<<sCurrV+1<<" path : "<<sPathCnt<<endl;
		sPrev = sCurrV;

		sLevel++;

		//		cout<<"WHILE ERROR"<<endl;
	}

	return sPathCnt;

}

int main()
{
	int sTest;
	int sVertexNum = 0;
	//	int sEdgeNum;


	int sV;

	int sPath = 0;

	gParents[0][0] = 0;

	cin >> sTest;
	for (int i = 0; i < sTest; i++)
	{


		/*
		* int gGraph[MAX_V][MAX_V] ={0,};
		int gVisted[MAX_V] = {0,};
		int gDepth[MAX_V] = {0,};
		int gParents[MAX_V][17] = {-1,};
		*/


		memset(gDepth, 0, sizeof(gDepth));
		for (int i = 0; i < MAX_V; i++)
		{
			//			memset(gGraph[i], 0, sizeof(int)*MAX_V);
			memset(gParents[i], -1, sizeof(int) * 17);
		}


		cin >> sVertexNum;


		for (int i = 0; i < sVertexNum - 1; i++)
		{
			cin >> sV;
			//			gGraph[sV-1][i+1] = 1;

			gParents[i + 1][0] = sV - 1;

			gVector[sV - 1].push_back(i + 1);
			gDepth[i + 1] = gDepth[gParents[i + 1][0]] + 1;

		}

		/*
		for(int j = 0; j < 17;j++)
		{
		for(int i = 0; i < sVertexNum; i++)
		{
		cout<<gParents[i][j]<<" ";
		}
		cout<<endl;
		}
		*/

		//		cout<<"Parent : "<<endl;

		for (int i = 1; i < sVertexNum; i++)
		{
			for (int j = 0; j <17 - 1; j++)
			{
				if (gParents[i][j] > 0)
				{
					gParents[i][j + 1] = gParents[gParents[i][j]][0];

				}
				//			cout<<gParents[i][j]<<" ";

			}
			//		cout<<endl;
		}


		//		cout<<"Input done"<<endl;

		sPath = BFSwithDepth(0, sVertexNum);
		cout << "#" << i + 1 << " " << sPath << endl;;

	}



	return 0;

}



#endif


#if 0
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int T, N;
int parent[100001][17];
int depth[100001];
long long ans;

long long distance(int prev, int now) {
	//printf("distance between %d and %d\n", prev, now);
	long long ans = 0LL;
	if (depth[prev] != depth[now]) {
		//printf("depth different.(%d, %d)\n", depth[prev], depth[now]);
		now = parent[now][0];
		++ans;
	}
	if (prev == now) {
		//printf("ans : %lld\n", ans);
		return ans;
	}
	int pos;
	for (pos = 16; pos >= 0; pos--) {
		if (parent[prev][pos] != parent[now][pos]) {
			ans += (1 << (pos + 1));
			prev = parent[prev][pos];
			now = parent[now][pos];
		}
	}
	//printf("ans : %lld\n", ans + 2);
	return ans + 2;
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		queue<int> q;
		vector<vector<int> > child(N + 1);
		ans = 0;
		parent[1][0] = 1;
		depth[1] = 0;
		for (int i = 2; i <= N; i++) {
			scanf("%d", &parent[i][0]);
			child[parent[i][0]].push_back(i);
			depth[i] = depth[parent[i][0]] + 1;
		}

		for (int j = 1; j < 17; j++) {
			for (int i = 1; i <= N; i++) {
				parent[i][j] = parent[parent[i][j - 1]][j - 1];
				printf("%d ", parent[i][j]);
			}
			printf("\n");
		}
		q.push(1);
		int now, prev = 1;
		while (!q.empty()) {
			now = q.front();
			q.pop();
			for (int i = 0; i < child[now].size(); i++) {
				q.push(child[now][i]);
			}
			ans += distance(prev, now);
			prev = now;
		}
		printf("#%d %lld\n", t, ans);
	}
}

#endif
