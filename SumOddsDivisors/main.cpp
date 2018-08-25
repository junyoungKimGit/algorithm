//5213. 진수의 홀수 약수

#include <iostream>
#include <cstring>

using namespace std;

#define MAX_N (1000001)

int gVisited[MAX_N];
long long gSumArr[MAX_N+10];

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

//timeout!!
void findSolve()
{
	int sInitStart = 0;
	int sTempSum = 0;;
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

int oddNum(int aA)
{
	return (aA % 2) == 1 ? aA : 0;
}

void findSolve2()
{
	//int sTempMax = 11;;

	for (int i = 1; i < MAX_N; i++)
	{
		for (int j = i; j * i < MAX_N; j++)
		{
			if (i * j > MAX_N)
				break;
			if (i == j)
			{
				gSumArr[i*j] += oddNum(j);
			}
			else
			{
				gSumArr[i*j] += oddNum(i) + oddNum(j);
			}
		}
		if (i * i > MAX_N)
			break;
	}

	//for (int i = 1; i < 20; i++)
	//	cout << gSumArr[i] << " ";
	//cout << endl;

	for (int i = 2; i < MAX_N+1; i++)
		gSumArr[i] += gSumArr[i-1];

	/*for (int i = 1; i < 20; i++)
		cout << gSumArr[i] << " ";
	cout << endl;

	cout << "init : " << gSumArr[1000000] - gSumArr[1000-1] << endl;*/

}

int main()
{

	findSolve2();
	
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M;

		//findSolve();

		gSUM = gSumArr[M] - gSumArr[N-1];

		cout << "#" <<t<< " " << gSUM << endl;

		gSUM = 0;
	}	

	return 0;
}