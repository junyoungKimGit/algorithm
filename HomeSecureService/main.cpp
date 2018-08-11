//2117. [모의 SW 역량테스트] 홈 방범 서비스

#include <iostream>

using namespace std;

#define MAX_N (20)

int T;
int N, M;

int gSecureValue[MAX_N + 2];
int gMaxValue;
int gMap[MAX_N][MAX_N];


void initSecureValue()
{
	gSecureValue[1] = 1;

	for (int i = 1; i < MAX_N+2; i++)
	{
		gSecureValue[i + 1] = i * i + (i + 1) * (i + 1);
	}
}

bool isRange(int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N)
		return true;
	else
		return false;
}

void findSolve()
{
	int sHeight = 0;
	int sWidth = 0;
	int sHouseCnt = 0;
	int sStartY = 0;
	int sTempValue = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 1; k <= N + 1; k++)
			{

				/*if (i == 3 && j == 3 && k == 4)
					cout << "BREAK" << endl;*/
				//Up Triangle //k = 4
				sHeight = k-1; //3
				sWidth = 2 * (k - 1) + 1; //7
				
				for (int u = 1; u <= sHeight; u++)
				{
					sStartY = j - (sWidth/2) + (u); // s = j - 3
					for (int w = 0; w < sWidth - (u * 2); w++)
					{
						if (isRange(i + u, sStartY + w) && gMap[i + u][sStartY + w] == 1)
							sHouseCnt++;
					}
				}
				
				//Down Triangle
				for (int u = 1; u <= sHeight; u++)
				{
					sStartY = j - (sWidth / 2) + (u);
					for (int w = 0; w < sWidth - (u * 2); w++)
					{
						if (isRange(i - u, sStartY + w) && gMap[i - u][sStartY + w] == 1)
							sHouseCnt++;
					}
				}

				//Horizen
				sStartY = j - (sWidth / 2);
				for (int w = 0; w < sWidth; w++)
				{
					if (isRange(i, sStartY + w) && gMap[i][sStartY + w] == 1)
						sHouseCnt++;
				}


				//calculate Value
				sTempValue = (sHouseCnt * M) - gSecureValue[k];
				if(sTempValue >= 0)
				{
					if (gMaxValue < sHouseCnt)
					{
						gMaxValue = sHouseCnt;

						/*cout << "i : " << i << " j : " << j << " k : " << k << " HouseCnt : " << sHouseCnt << endl;
						cout << "sTempVal : " << sTempValue << " SecureVla : " << gSecureValue[k] << endl;*/
					}
				}
				sTempValue = 0;
				sHouseCnt = 0;
			}

		}
	}
}

int main()
{
	cin >> T;

	//init val
	initSecureValue();

	/*for (int i = 0; i < MAX_N + 1; i++)
		cout << gSecureValue[i] << " ";
	cout<<endl;*/

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> gMap[i][j];

		findSolve();

		cout << "#" << t << " " << gMaxValue << endl;

		gMaxValue = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				gMap[i][j] = 0;
	}

	return 0;

}