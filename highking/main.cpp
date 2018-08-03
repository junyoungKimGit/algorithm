/*
* main.cpp
*
*  Created on: 2018. 7. 27.
*      Author: HY
1949. [모의 SW 역량테스트] 등산로 조성
*/

#include <iostream>

using namespace std;

#define MAX_N (8)

class cPoint
{
public:
	int mX;
	int mY;
};

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int gGraph[MAX_N][MAX_N] = { 0, };
int gVisited[MAX_N][MAX_N] = { 0, };

int gTempMaxLength = 0;


int findTops(cPoint aTops[], int aBound)
{
	int sMax = 0;
	int sCnt = 0;

	for (int i = 0; i < aBound; i++)
	{
		for (int j = 0; j < aBound; j++)
		{
			if (sMax < gGraph[i][j])
			{
				sMax = gGraph[i][j];
			}

		}
	}

	for (int i = 0; i < aBound; i++)
	{
		for (int j = 0; j < aBound; j++)
		{
			if (sMax == gGraph[i][j])
			{
				aTops[sCnt].mX = i;
				aTops[sCnt].mY = j;
				sCnt++;
			}

		}
	}
	return sCnt;
}

void findPath(int aBound, cPoint aPoint, int * aLength, int aDeeper, bool aUsedDeeper)
{
	//	cout<<"position : "<<aPoint.mX<<" "<<aPoint.mY<<" lenght : "<<*aLength<<endl;

	if (gTempMaxLength < *aLength)
		gTempMaxLength = *aLength;

	int sDX, sDY;

	for (int i = 0; i < 4; i++)
	{
		sDX = aPoint.mX + dx[i];
		sDY = aPoint.mY + dy[i];

		if (sDX < aBound && sDX > -1 &&
			sDY < aBound && sDY > -1 &&
			gVisited[sDX][sDY] == 0)
		{
			//lower && NOT used
			if (gGraph[sDX][sDY] < gGraph[aPoint.mX][aPoint.mY])
			{
				cPoint sTempPoint;
				sTempPoint.mX = sDX;
				sTempPoint.mY = sDY;
				*aLength = *aLength + 1;
				gVisited[sDX][sDY] = 1;
				findPath(aBound, sTempPoint, aLength, aDeeper, aUsedDeeper);

				gVisited[sDX][sDY] = 0;
				*aLength = *aLength - 1;

			}
			else if (gGraph[sDX][sDY] >= gGraph[aPoint.mX][aPoint.mY] &&
				aUsedDeeper == false)
			{
				for (int j = 1; j <= aDeeper; j++)
				{
					if (gGraph[sDX][sDY] - j < gGraph[aPoint.mX][aPoint.mY])
					{
						gGraph[sDX][sDY] -= j;

						cPoint sTempPoint;
						sTempPoint.mX = sDX;
						sTempPoint.mY = sDY;
						*aLength = *aLength + 1;
						gVisited[sDX][sDY] = 1;
						findPath(aBound, sTempPoint, aLength, aDeeper, true);

						gGraph[sDX][sDY] += j;
						gVisited[sDX][sDY] = 0;
						*aLength = *aLength - 1;

					}
				}
			}


		}
		else
		{
			/* Nothing to do */
		}
	}

	return;
}


int main()
{
	int sTestCnt;
	cin >> sTestCnt;

	int sBound;
	int sDeeper;
	for (int i = 0; i< sTestCnt; i++)
	{
		cin >> sBound >> sDeeper;

		for (int j = 0; j < sBound; j++)
		{
			for (int k = 0; k < sBound; k++)
			{
				cin >> gGraph[j][k];
			}
		}

		cPoint sTops[5];
		int sTopsCnt;

		sTopsCnt = findTops(sTops, sBound);

		int sMaxLength = 0;
		int sLength = 1;
		for (int j = 0; j < sTopsCnt; j++)
		{
			gVisited[sTops[j].mX][sTops[j].mY] = 1;
			findPath(sBound, sTops[j], &sLength, sDeeper, false);

			if (sMaxLength  < gTempMaxLength)
			{
				sMaxLength = gTempMaxLength;
			}
			//			cout<<"temp : "<<gTempMaxLength<<endl;
			sLength = 1;
			gTempMaxLength = 0;
			gVisited[sTops[j].mX][sTops[j].mY] = 0;

		}
		cout << "#" << i + 1 << " " << sMaxLength << endl;;

	}

	return 0;
}
