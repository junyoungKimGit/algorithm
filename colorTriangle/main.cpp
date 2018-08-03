//5172. 같은 변을 가진 삼각형

#include <iostream>
#include <cstring>

using namespace std;

#define MAX_N (1000)

int gGraph[MAX_N][MAX_N] = { 0, };
int gNumT = 0;
void solve(int aN, int aFirst, int aSecond, int aDepth, int aColor)
{
	switch (aDepth)
	{
	case 0 :
		for (int i = 0; i < aN; i++)
		{
			for(int j = i + 1; j < aN; j++)
				solve(aN, i, j, aDepth + 1, gGraph[i][j]);
		}
		break;

	case 1:
		for (int i = aSecond + 1; i < aN; i++)
		{
			if (gGraph[aSecond][i] == aColor &&(gGraph[aFirst][i] == aColor))
			{
				//solve(aN, aFirst, aSecond, i, aDepth + 1, aColor);
				//if (gGraph[aFirst][i] == aColor)

					gNumT++;

			}
		}
		break;
	default :
		break;
	}
}

int main()
{
	//gGraph[0][1] = 1;
	//gGraph[0][2] = 1;
	//gGraph[0][3] = 0;
	//gGraph[0][4] = 1;
	//gGraph[1][2] = 0;
	//gGraph[1][3] = 0;
	//gGraph[1][4] = 0;
	//gGraph[2][3] = 0;
	//gGraph[2][4] = 1;
	//gGraph[3][4] = 1;

	/*gGraph[0][1] = 1;
	gGraph[0][2] = 1;
	gGraph[0][3] = 1;
	gGraph[0][4] = 1;
	gGraph[1][2] = 0;
	gGraph[1][3] = 0;
	gGraph[1][4] = 1;
	gGraph[2][3] = 0;
	gGraph[2][4] = 1;
	gGraph[3][4] = 1;

	for (int i = 0; i < 5; i++)
	{
		solve(5, i, 0, 0, 0, 1);
		solve(5, i, 0, 0, 0, 0);
	}

	cout << "SOLVE : " << gNumT << endl;*/

	int sT = 1;
	cin >> sT;
	int sN;
	int sInput;
	int sTemp;
	int sDec = 10;
	for(int t = 1; t <= sT; t++)
	{
		cin >> sN;
		for (int i = 0; i < sN-1; i++)
		{
			cin >> sInput;
			sTemp = sInput;
			int sCnt = 1;
			while (sTemp)
			{
				gGraph[i][sN - sCnt] = sTemp % sDec;
				sTemp /= sDec;
				sCnt++;
			}
		/*	for (int j = i + 1; j < sN; j++)
			{
				cin >> gGraph[i][j];
			}*/
		}

	/*	cout << "PRINT" << endl;
		for (int i = 0; i < sN; i++)
		{
			for (int j = 0; j < sN; j++)
			{
				cout << gGraph[i][j] << " ";
			}

			cout << endl;
		}*/


		solve(sN, 0, 0, 0, 0);
		
		cout << "#" << t << " " << gNumT << endl;
		gNumT = 0;
	}



	cin >> sT;


	return 0;
}