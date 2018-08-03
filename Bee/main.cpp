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


#if 0 

#include <iostream>
using namespace std;

#define MAXN 10 // N의 최댓값
#define MAXM 7 // M의 최댓값

int h[MAXN][MAXN]; // 벌통의 최대 수익 정보
int r[MAXN][MAXN]; //  테스트케이스 변수

int tc, T;

int N, M, C;

// (y, x)를 가장 왼쪽 좌표로 두는 벌통에서의 최대 수익을 계산하는 재귀함수
int getPSum(int m, int y, int x, int sum, int psum) {
	if (m >= M) return psum;
	// 탐색한 경우의 수익을 저장하는 변수
	int nextSum;
	// 최대 수익을 저장하는 변수
	int max = 0;
	for (int i = m; i < M; ++i)
	{
		// c값을 넘지 않는 범위라면 (y, x+i) 위치의 용기를 채취해볼 수 있다.
		if (sum + h[y][x + i] <= C)
		{
			// (y, x+i) 위치의 용기를 채취할 때 수익을 탐색해본다.
			nextSum = getPSum(i + 1, y, x, sum + h[y][x + i], psum + h[y][x + i] * h[y][x + i]);

			// 최대 수익 갱신 가능한 경우 갱신
			if (max < nextSum) max = nextSum;
		}
		// (y, x+i) 위치의 용기를 채취하지 않는 경우도 탐색해본다.
		nextSum = getPSum(i + 1, y, x, sum, psum);
		// 최대 수익 갱신 가능한 경우 갱신
		if (max < nextSum) max = nextSum;
	}
	// 최대 수익 반환
	return max;
}

// (y,x)를 가장 왼쪽 좌표로 두는 벌통과 동시에 선택가능한 벌통 중 최대 수익을 내는 벌통의 수익을 찾는 함수
int getMaxPair(int y, int x)
{
	int maxR = 0;
	// 일단 같은 행에서 가로로 동시에 선택가능한 벌통 중 최대 수익을 찾는다
	for (int j = x + M; j <= N - M; ++j)
	{
		if (maxR < r[y][j]) maxR = r[y][j];
	}
	// 다른 행에 있는 벌통은 무조건 동시에 선택가능하므로 수익값을 다 확인해본다
	for (int i = y + 1; i < N; i++)
	{
		for (int j = 0; j <= N - M; ++j)
		{
			if (maxR < r[i][j]) maxR = r[i][j];
		}
	}
	return maxR;
}


int solve(void)
{
	//  i : 세로 순회용 변수, j : 가로 순회용 변수
	int i, j;
	// 동시에 선택가능한 두 벌통의 수익 합을 저장할 변수
	int sum;
	// 최대 수익값
	int ans = 0;

	// 모든 세로, 가로 좌표에 대해 수행한다
	for (i = 0; i < N; ++i)
	{
		// 단, (i, j)를 포함하여 가로로 M개의 용기가 자동선택되는 것이므로,
		// 실제 선택할  수 있는 경우의 수는 N -M +1 가지다 (M은 반드시 N 이하로만 주어진다)
		for (j = 0; j <= N - M; ++j)
		{
			// (i, j)을 가장 왼쪽 좌표로 두는 벌통을 설치했을 때의 최대 수익을 구한다
			r[i][j] = getPSum(0, i, j, 0, 0);
		}
	}

	// 모든 세로, 가로 좌표에 대해 동시에 선택가능한 두 벌통의 수익 합이 최대인 경우를 찾는다
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j <= N - M; ++j)
		{
			// (i, j) 벌통과 동시에 선택가능한 벌통 중 최대 수익을 내는 벌통의 수익을 찾는다
			sum = r[i][j] + getMaxPair(i, j);
			// 최대 수익이 갱신되는지 확인한다
			if (ans < sum) ans = sum;
		}
	}
	// 최대 수익값을 반환한다
	return ans;
}


int main(void)
{
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		//테스트케이스별로 다른 N, M, C 값을 입력받는다.
		cin >> N >> M >> C;
		// 각 (y,x)를 시작 좌표로 하는 벌통의 최대 수익 정보를 초기화한다
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; j++) r[i][j] = 0;
		// 각 용기별 꿀의 함량을 입력받는다
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)
			cin >> h[i][j];
		// 테스트케이스의 답을 출력한다 
		cout << "#" << tc << " " << solve() << endl;
	}
	return 0;
}

#endif