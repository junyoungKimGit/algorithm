//4301. Äá ¸¹ÀÌ ½É

#include <iostream>

using namespace std;

#define MAX_N (1000)

int gMap[MAX_N][MAX_N];
int gCnt;

int T, M, N;

bool isRange(int aX, int aY)
{
	if (aX > -1 && aX <= M && aY > -1 && aY < N)
		return true;
	else
		return false;
}

int main()
{
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> M >> N;

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				//remove using t
				if (gMap[i][j] != t)
				{
					if (isRange(i+2,j))
						gMap[i + 2][j] = t;

					if(isRange(i,j+2))
						gMap[i][j + 2] = t;
					gCnt++;
				}
			}
		}

		cout << "#" << t << " " << gCnt << endl;

		gCnt = 0;
	}

	return 0;
}