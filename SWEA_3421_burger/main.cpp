//3421. 수제 버거 장인

#include <iostream>

using namespace std;

#define MAX_N (400)
int T, N, M;

int gMap[MAX_N][MAX_N];
int gVisited[MAX_N];
int gCnt;

int gComb[MAX_N];

void swap(int * aA, int * aB)
{
	int sTemp = *aA;
	*aA = *aB;
	*aB = sTemp;
}

void printVisited()
{
	for (int i = 1; i <= N; i++)
	{
		cout << gVisited[i] << " ";
	}
	cout << endl;
}

void findSolve(int aCurrent, int aCnt, int aTestcase)
{
	if (aCnt == N)
	{
		gCnt++;
		printVisited();
		return;
	}

	for (int i = aCurrent+ 1; i <= N; i++)
	{
		if (gMap[aCurrent][i] != aTestcase)
		{
			if (gVisited[i] != aTestcase)
			{
				gVisited[i] = aTestcase;
				findSolve(i, aCnt + 1, aTestcase);
				gVisited[i] = 0;
			}
			else
			{
				findSolve(i, aCnt + 1, aTestcase);				
			}
		}
	}
}

int main()
{

	cin >> T;
	int sFirst, sSecond;
	int sTemp;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M;

		for (int i = 0; i < M; i++)
		{
			cin >> sFirst >> sSecond;

			if (sFirst > sSecond)
			{
				swap(&sFirst, &sSecond);
			}
			//gMap[sFirst][sSecond] = tc;
			gComb[i] = (1 << (sFirst - 1)) | (1 << (sSecond - 1));
		}

		//findSolve(0, 0, tc);

		gCnt = 1 << N;

		for (int i = 0; i < (1 << N); i++)
		{
			for (int j = 0; j < M; j++)
			{
				sTemp = i & gComb[j];
				if (sTemp == gComb[j])
				{
					gCnt--;
					break;
				}
			}
		}

		cout << "#" << tc <<" "<< gCnt << endl;

		gCnt = 0;
	}

	cin >> T;
	return 0;
}

