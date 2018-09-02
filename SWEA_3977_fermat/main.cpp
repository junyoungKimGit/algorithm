//3977. 페르마의 크리스마스 정리

#include <iostream>

using namespace std;

#define MAX_N (1000001)

bool gPrime[MAX_N];
int gDP[MAX_N];

// 에라토스테네스의 체
void initPrime()
{
	gPrime[0] = gPrime[1] == false;

	for (int i = 2; i < MAX_N; i++)
		gPrime[i] = true;

	for (int i = 2; i * i < MAX_N; i++)
	{
		if (gPrime[i] == true)
		{	
			for (int j = i + i; j < MAX_N; j = i + j)
			{
				gPrime[j] = false;
			}
		}
	}

	return;
}

void initDP()
{
	int sCnt = 1;
	gDP[0] = gDP[1] = 0;
	gDP[2] = sCnt;
	for (int i = 3; i < MAX_N; i++)
	{
		if (gPrime[i] == true && i % 4 == 1)
		{
			sCnt++;
		}
		gDP[i] = sCnt;
	}
	
	return;
}

int T;

int main()
{
	initPrime();
	initDP();

	int sStart, sEnd;

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> sStart >> sEnd;

		cout << "#" << tc << " " << gDP[sEnd] - gDP[sStart-1] << endl;
	}

	cin >> T;

	return 0;
}
