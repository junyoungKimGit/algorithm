//4583. ¼¼ºì Ä«µå ¼¯±â °ÔÀÓ

#include <iostream>

using namespace std;

int gCard[7];
int gSwapM[21][2];

void initCard()
{
	for (int i = 0; i < 7; i++)
	{
		gCard[i] = i;
	}
}

void printCard()
{
	for (int i = 0; i < 7; i++)
	{
		cout << gCard[i];
	}
	cout << endl;
}

void swap(int aIdxA, int aIdxB)
{
	int sTemp = gCard[aIdxA - 1];
	gCard[aIdxA - 1] = gCard[aIdxB-1];
	gCard[aIdxB - 1] = sTemp;
}

bool isInitState()
{
	for (int i = 0; i < 7; i++)
	{
		if (gCard[i] != i)
		{
			return false;
		}
	}

	return true;
}

int M, K, T;

int main()
{

	cin >> T;
	int sMCnt;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> M >> K;
		initCard();

		/*cout << "INIT" << endl;
		printCard();*/

		for (int i = 0; i < M; i++)
		{
			cin >> gSwapM[i][0] >> gSwapM[i][1];
		}

		sMCnt = 0;
		for (long long i = 0; i < K; i++)
		{
			swap(gSwapM[sMCnt][0], gSwapM[sMCnt][1]);
			sMCnt++;

			/*cout << "SWAP : ";
			printCard();*/

				if (sMCnt >= M)
				{
					sMCnt = 0;
					if (isInitState())
					{
						K = K % (i + 1);
						i = -1;
					}
				}
		}

		cout << "#" << tc << " ";
		printCard();
	}

	return 0;
}

