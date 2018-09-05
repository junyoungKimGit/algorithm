//5521. 상원이의 생일파티

#include <iostream>

using namespace std;

#define MAX_N (501)
#define MAX_M (10001)

int gMap[MAX_N][MAX_N];
int gVisited[MAX_N];
int gQ[MAX_M];
int gQSize = MAX_M;
int gQHead = 0;
int gQTail = 0;

void EnQ(int aA)
{
	gQ[gQTail] = aA;
	gQTail = (gQTail + 1) % gQSize;
}

int DeQ()
{
	int sData = gQ[gQHead];

	gQHead = (gQHead + 1) % gQSize;

	return sData;
}

bool isQEmpty()
{
	return gQHead == gQTail ? true : false;
}

int CurrentQSize()
{
	return gQTail - gQHead;
}

int N, M, T;
int gCnt;

//bfs
void findSolve(int aTestcase)
{
	int sLoopCnt = 0;
	gVisited[1] = aTestcase;
	for (int i = 1; i <= N; i++)
	{
		if (gMap[1][i] == aTestcase)
		{
			EnQ(i);
			gVisited[i] = aTestcase;
			
		}
	}

	int sData;
	int sQsize;
	while (isQEmpty() == false && sLoopCnt < 2)
	{
		sQsize = CurrentQSize();
		while (sQsize--)
		{
			sData = DeQ();
			gCnt++;
			//cout << "sData : " << sData << endl;

			for (int i = 1; i <= N; i++)
			{
				if (gMap[sData][i] == aTestcase && gVisited[i] != aTestcase)
				{
					EnQ(i);
					gVisited[i] = aTestcase;
				}
			}
		}
		sLoopCnt++;
	}
}
int main()
{

	cin >> T;

	int sFriendA;
	int sFriendB;

	for(int tc = 1; tc <= T; tc++)
	{
	
		cin >> N >> M;

		for (int i = 0; i < M; i++)
		{
			cin >> sFriendA >> sFriendB;
			gMap[sFriendA][sFriendB] = tc;
			gMap[sFriendB][sFriendA] = tc;
		}

		findSolve(tc);

		cout << "#" << tc << " " << gCnt << endl;

		gCnt = 0;
		gQTail = gQHead = 0;
	}

	return 0;
}