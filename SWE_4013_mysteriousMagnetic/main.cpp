//4013. [모의 SW 역량테스트] 특이한 자석

#include <iostream>

using namespace std;

int gMag[4][8];
int gVisit[4];

int T, N;
int gVal;

void initVisit()
{
	for (int i = 0; i < 4; i++)
		gVisit[i] = 0;
}

void calVal()
{
	for (int i = 0; i < 4; i++)
	{
		if(gMag[i][0] == 1)
			gVal += (1 << i);
	}
}

void clockWise(int aIdx, int aRiverse)
{
	int sTemp;

	if (aRiverse == 1)
	{
		sTemp = gMag[aIdx][7];
		//clockwise
		for (int i = 7; i > 0; i--)
		{
			gMag[aIdx][i] = gMag[aIdx][i - 1];
		}
		gMag[aIdx][0] = sTemp;
	}
	else //aRiverse == -1
	{
		//countClockWise
		sTemp = gMag[aIdx][0];
		for (int i = 0; i < 7; i++)
		{
			gMag[aIdx][i] = gMag[aIdx][i + 1];
		}
		gMag[aIdx][7] = sTemp;

	}
}

void rotateMag(int aIdx, int aDir)
{
	gVisit[aIdx] = 1;

	//left
	if (aIdx -1 > -1 && gVisit[aIdx - 1] == 0
		&& gMag[aIdx][6] != gMag[aIdx - 1][2])
	{
		rotateMag(aIdx - 1, aDir * -1);
	}

	//right

	if (aIdx + 1 < 4 && gVisit[aIdx + 1] == 0
		&& gMag[aIdx][2] != gMag[aIdx + 1][6])
	{
		rotateMag(aIdx + 1, aDir * -1);
	}

	clockWise(aIdx, aDir);

}

int main()
{
	cin >> T;
	
	int sIdx, sDir;

	for (int t = 1; t <= T; t++)
	{
		cin >> N;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> gMag[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			cin >> sIdx >> sDir;
			rotateMag(sIdx-1, sDir);
			initVisit();
		}

		calVal();

		cout << "#" << t << " " << gVal << endl;
		gVal = 0;
	}

	cin >> T;
	return 0;
}