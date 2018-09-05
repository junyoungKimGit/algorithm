//5357. 터널 속의 기차

#include <iostream>

using namespace std;

#define MAX_N (100001)

typedef long long ll;

ll gTrainLength[MAX_N];
int gLight[MAX_N];

ll N, H;
int T;
ll gLigthCnt;

void findSolve(int aTestcase)
{
	ll sCurrentLight = 0;

	int sLightOffLength = 0;
	for (int i = 0; i < N; i++)
	{
		if (gLight[i] == aTestcase)
		{
			sLightOffLength = 1;
		}
		else
		{
			if (i == 0 && gLight[i] != aTestcase || i == N - 1 && gLight[i] != aTestcase)
			{
				sLightOffLength = H + 1;
			}
			else
			{
				sLightOffLength += gTrainLength[i];
			}

			if (sLightOffLength > H)
			{
				sLightOffLength = 1;
				//cout << " i : " << i << endl;
				gLigthCnt++;
			}
		}
	}
}

int main()
{
	cin >> T;
	int sLight;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> H;

		for (int i = 0; i < N; i++)
		{
			cin >> gTrainLength[i];
		}

		for (int i = 0; i < N; i++)
		{
			cin >> sLight;
			if (sLight == 1)
			{
				gLight[i] = tc;
			}
		}

		findSolve(tc);

		cout << "#" << tc << " " << gLigthCnt << endl;

		gLigthCnt = 0;
	}

	cin >> T;



	return 0;
}