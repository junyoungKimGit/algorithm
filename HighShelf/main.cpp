//1486. 장훈이의 높은 선반

#include <iostream>

using namespace std;

#define MAX_N (20)
#define MAX_B (20 * 10000)

int min(int aA, int aB)
{
	return aA > aB ? aB : aA;
}

int gHeight[MAX_N];

int T, N, B;
int gTotalHigh;

void findSolve(int aIdx, int aCurrHigh)
{
	if (aIdx > N)
		return;
	if (aCurrHigh >= B)
	{
		//cout << "AAAAA : " << aCurrHigh << endl;
		gTotalHigh = min(gTotalHigh, aCurrHigh);
		return;
	}

	findSolve(aIdx + 1, gHeight[aIdx] + aCurrHigh);
	findSolve(aIdx + 1, aCurrHigh);
	
}

int main()
{

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> B;

		for (int i = 0; i < N; i++)
		{
			cin >> gHeight[i];
		}
		
		gTotalHigh = MAX_B;

		findSolve(0, 0);		
		//cout << "B : " << B << " TotalHigh : " << gTotalHigh << endl;

		cout << "#" << t << " " << gTotalHigh - B<< endl;;
	}

	return 0;
}