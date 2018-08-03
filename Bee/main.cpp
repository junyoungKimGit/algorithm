//2115. [모의 SW 역량테스트] 벌꿀채취

#include <iostream>
#include <cstring>

using namespace std;

#define MAX_N (10)

int gGraph[MAX_N][MAX_N] = { 0, };
int gVisited[MAX_N];
//int sample[MAX_N*MAX_N] = { 7, 2, 9, 6, 6, 6, 5, 5, 7 };
int sample[MAX_N*MAX_N] = { 8, 5, 2, 4, 3, 1, 
							4, 3, 6, 1, 1, 8, 
							4, 4, 1, 2, 3, 1, 
							1, 7, 4, 9, 6, 1, 
							6, 5, 1, 2, 8, 4,
							3, 1, 4, 5, 1, 3 };

int gMaxValRow = 0;

class cMaxVal
{
public:
	int mVal;
	int mX;
	int mY;
};

void mySwap(cMaxVal aA, cMaxVal aB)
{
	cMaxVal sTemp = aA;
	aA = aB;
	aB = sTemp;
}

void findMaxValInRow(int aX, int aY, int aSlide, int aLimit, int aCurrVal)
{
	//cout << "CurrVal : " << aCurrVal << endl;

	if (aCurrVal > aLimit)
		return;

	int sRowVal = 0;
	for (int i = 0; i < aSlide; i++)
	{
		if (gVisited[i] == 1)
		{
			sRowVal += (gGraph[aX][aY + i] * gGraph[aX][aY + i]);
		}
	}

	if (gMaxValRow < sRowVal)
		gMaxValRow = sRowVal;

	for (int i = 0; i < aSlide; i++)
	{
		if(gVisited[i] == 0)
		{
			gVisited[i] = 1;
			findMaxValInRow(aX, aY, aSlide, aLimit, aCurrVal + gGraph[aX][aY + i]);
			gVisited[i] = 0;
		}
	}
}

void updateMax(cMaxVal aMaxArr[], int aVal, int aPosX, int aPosY, int aSlide)
{


	if (aMaxArr[0].mVal == 0)
	{
		aMaxArr[0].mVal = aVal;
		aMaxArr[0].mX = aPosX;
		aMaxArr[0].mY = aPosY;
		
		return;
	}

	if (aMaxArr[1].mVal == 0)
	{
		if (aMaxArr[0].mX == aPosX && aMaxArr[0].mY + aSlide > aPosY)
		{
			if( aVal <= aMaxArr[0].mVal)
				return;
			else
			{
				aMaxArr[0].mVal = aVal;
				aMaxArr[0].mX = aPosX;
				aMaxArr[0].mY = aPosY;
				return;

			}
		}
		else
		{

		}

		aMaxArr[1].mVal = aVal;
		aMaxArr[1].mX = aPosX;
		aMaxArr[1].mY = aPosY;

		if (aMaxArr[0].mVal < aMaxArr[1].mVal)
		{
			mySwap(aMaxArr[0], aMaxArr[1]);
		}
		return;
	}

	if (aMaxArr[1].mVal > aVal)
	{
		return;
	}

	if (aMaxArr[1].mVal < aVal && aMaxArr[0].mVal >=aVal)
	{
		if (aMaxArr[0].mX == aPosX && aMaxArr[0].mY + aSlide > aPosY )
		{
			return;
		}

		aMaxArr[1].mVal = aVal;
		aMaxArr[1].mX = aPosX;
		aMaxArr[1].mY = aPosY;
		return;
	}

	if (aMaxArr[0].mVal < aVal)
	{
		if (aMaxArr[0].mX == aPosX && aMaxArr[0].mY + aSlide > aPosY && aMaxArr[0].mVal == aVal)
		{
			return;
		}
		
		aMaxArr[1].mVal = aMaxArr[0].mVal;
		aMaxArr[1].mX = aMaxArr[0].mX;
		aMaxArr[1].mY = aMaxArr[0].mY;

		aMaxArr[0].mVal = aVal;
		aMaxArr[0].mX= aPosX;
		aMaxArr[0].mY = aPosY;

		//cout <<"MAXPOS : "<< gMaxPosition[0] << " " << gMaxPosition[1] << " " << aPosX << " " << aPosY << endl;
		//cout << "MAX1 : " << aMaxArr[0] << " MAX2 : " << aMaxArr[1] << endl;
		return;
	}

	//cout << "MAX1 : " << aMaxArr[0] << " MAX2 : " << aMaxArr[1] << endl;
	return;
}

int findSolve(int aN, int aSlide, int aCatchLimit)
{
	int sFirstMax = 0;
	int sSecondMax = 0;

	int sTempCatch;
	int sValue;

	cMaxVal sMaxVal[2];

	sMaxVal[0].mVal = 0;
	sMaxVal[1].mVal = 0;
	

	int s;
	for (int i = 0; i < aN; i++)
	{
		for (int j = 0; j < aN -aSlide + 1; j++)
		{
			gMaxValRow = 0;
			memset(gVisited, 0, sizeof(gVisited));
			
			findMaxValInRow(i, j, aSlide, aCatchLimit, 0);
			//cout << "MAX VAL L " << gMaxValRow << endl;
			/*
			for (int k = 0; k < aSlide; k++)
			{

				//cout << "aCatchL : " << aCatchLimit << " sTempCatch : " << sTempCatch << " aGraph[" << i << " + " << k << "][" << j<<"] : " << gGraph[i + k][j] << endl;
				if (j + k >= aN)
					break;
				
				//cin >> s;
				if (aCatchLimit >= sTempCatch + gGraph[i][j+k])
				{
					sTempCatch += gGraph[i][j+k];
					sValue += gGraph[i][j+k] * gGraph[i][j+k];	
				}
				else
				{
					
				}


			}	
			*/
			//cout << i<<" "<<j<<" "<<"sVal :" << sValue << endl;
			updateMax(sMaxVal, gMaxValRow, i, j, aSlide);
		}
	}

	//cout << "MAX1 : " << sMaxVal[0].mVal<<" "<<sMaxVal[0].mX<< " "<<sMaxVal[0].mY<<" " << " MAX2 : " << sMaxVal[1].mVal<<" " << sMaxVal[1].mX << " " << sMaxVal[1].mY << endl;

	return sMaxVal[0].mVal + sMaxVal[1].mVal;
}

int main()
{
	//
	//int cnt = 0;
	//for (int i = 0; i < MAX_N; i++)
	//{
	//	for (int j = 0; j < MAX_N; j++)
	//	{
	//		gGraph[i][j] = sample[cnt++];
	//	}	
	//}
	//
	//for (int i = 0; i < MAX_N; i++)
	//{
	//	for (int j = 0; j < MAX_N; j++)
	//	{
	//		cout << gGraph[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	//cout<<"sol : "<<findSolve(MAX_N, 3, 20)<<endl;
	//

	

	int sTest;
	cin >> sTest;

	int sN, sSlide, sLimit;
	for (int t = 0; t < sTest; t++)
	{
		cin >> sN >> sSlide >> sLimit;
		for (int i = 0; i < sN; i++)
		{
			for(int j = 0; j < sN;j++)
			{
				cin >> gGraph[i][j];
			}
		}

		cout << "#" << t + 1 << " "<<findSolve(sN, sSlide, sLimit) << endl;;



		for (int i = 0; i < sN; i++)
		{
			for(int j = 0; j < sN;j++)
			{
				gGraph[i][j] = 0;
			}
		}

	}

	return 0;
}