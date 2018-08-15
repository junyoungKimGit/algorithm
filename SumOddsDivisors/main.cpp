//5213. 진수의 홀수 약수

#include <iostream>
#include <cstring>

using namespace std;

#define MAX_N (1000001)

int gVisited[MAX_N];
int gSum[MAX_N];

int T, N, M;
long long gSUM;

int max(int aA, int aB)
{
	return aA > aB ? aA : aB;
}

void initVisted(int aStart, int aN)
{
	for (int i = aStart; i < aN; i++)
		gVisited[i] = 0;
}

void findSolve()
{
	int sInitStart = 0;;
	for (int i = N; i <= M; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (gVisited[j] == 1)
			{
				sInitStart = j;
				break;
			}

			if (i % j == 0)
			{
				//cout << "FOUND i : " << i << " j : " << j << endl;
				gVisited[i / j] = 1;
				if(j % 2 == 1)
					gSUM += j;
				if( (i/j)% 2 == 1)
					gSUM += i/j;

				if (j == i / j)
				{
					gSUM -= i / j;
					j--;

				}
			}

		}

		//cout << " i : " << i << " Sum : " << gSUM << endl;
		
		initVisted(sInitStart, i);
		sInitStart = 0;
		//memset(gVisited, 0, sizeof(gVisited));
	}
}

int main()
{

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M;

		findSolve();

		cout << "#" << " " << gSUM << endl;

		gSUM = 0;
	}
	cin >> T;

	return 0;
}