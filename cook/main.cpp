//4128. [모의 SW 역량테스트] 요리사

#include <iostream>

using namespace std;

#define MAX_N (16)

int gMAP[MAX_N][MAX_N];
int gVisited[MAX_N];
int gDiff;

int T, N;

int abs(int aA, int aB)
{
	return aA - aB > 0 ? aA - aB : aB - aA;
}

int min(int aA, int aB)
{
	return aA > aB ? aB : aA;
}

void findSolve(int aFoodCnt, int aAFood)
{
	//cout << "FoodCnt : " << aFoodCnt << endl;
	//for (int i = 0; i < N; i++)
	//	cout << gVisited[i] << " ";
	//cout << endl;
	if (aFoodCnt == N)
	{
		int sA = 0, sB = 0;

		for (int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if (i == j)
					continue;
				if (gVisited[i] == 1 && gVisited[j] == 1)
				{
					sA += gMAP[i][j];
				}
				else if(gVisited[i] == 0 && gVisited[j] == 0)
				{
					sB += gMAP[i][j];
				}
			}
		}

		gDiff = min(gDiff, abs(sA, sB));

		//cout << "DIFF : " << gDiff << endl;

		return;
	}

	if(aAFood > 0)
	{
		//A가 고르느 경우
		gVisited[aFoodCnt] = 1;
		findSolve(aFoodCnt+1, aAFood - 1);
		gVisited[aFoodCnt] = 0;
	}
		
	findSolve(aFoodCnt + 1, aAFood);	
	
}

int main()
{
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		gDiff = 100000000;
		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> gMAP[i][j];

		findSolve(0, N/2);


		cout << "#" <<t<< " " << gDiff << endl;;
	}

	//cin >> T;
	return 0;
}