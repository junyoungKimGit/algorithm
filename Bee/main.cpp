//2115. [���� SW �����׽�Ʈ] ����ä��

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

#define MAXN 10 // N�� �ִ�
#define MAXM 7 // M�� �ִ�

int h[MAXN][MAXN]; // ������ �ִ� ���� ����
int r[MAXN][MAXN]; //  �׽�Ʈ���̽� ����

int tc, T;

int N, M, C;

// (y, x)�� ���� ���� ��ǥ�� �δ� ���뿡���� �ִ� ������ ����ϴ� ����Լ�
int getPSum(int m, int y, int x, int sum, int psum) {
	if (m >= M) return psum;
	// Ž���� ����� ������ �����ϴ� ����
	int nextSum;
	// �ִ� ������ �����ϴ� ����
	int max = 0;
	for (int i = m; i < M; ++i)
	{
		// c���� ���� �ʴ� ������� (y, x+i) ��ġ�� ��⸦ ä���غ� �� �ִ�.
		if (sum + h[y][x + i] <= C)
		{
			// (y, x+i) ��ġ�� ��⸦ ä���� �� ������ Ž���غ���.
			nextSum = getPSum(i + 1, y, x, sum + h[y][x + i], psum + h[y][x + i] * h[y][x + i]);

			// �ִ� ���� ���� ������ ��� ����
			if (max < nextSum) max = nextSum;
		}
		// (y, x+i) ��ġ�� ��⸦ ä������ �ʴ� ��쵵 Ž���غ���.
		nextSum = getPSum(i + 1, y, x, sum, psum);
		// �ִ� ���� ���� ������ ��� ����
		if (max < nextSum) max = nextSum;
	}
	// �ִ� ���� ��ȯ
	return max;
}

// (y,x)�� ���� ���� ��ǥ�� �δ� ����� ���ÿ� ���ð����� ���� �� �ִ� ������ ���� ������ ������ ã�� �Լ�
int getMaxPair(int y, int x)
{
	int maxR = 0;
	// �ϴ� ���� �࿡�� ���η� ���ÿ� ���ð����� ���� �� �ִ� ������ ã�´�
	for (int j = x + M; j <= N - M; ++j)
	{
		if (maxR < r[y][j]) maxR = r[y][j];
	}
	// �ٸ� �࿡ �ִ� ������ ������ ���ÿ� ���ð����ϹǷ� ���Ͱ��� �� Ȯ���غ���
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
	//  i : ���� ��ȸ�� ����, j : ���� ��ȸ�� ����
	int i, j;
	// ���ÿ� ���ð����� �� ������ ���� ���� ������ ����
	int sum;
	// �ִ� ���Ͱ�
	int ans = 0;

	// ��� ����, ���� ��ǥ�� ���� �����Ѵ�
	for (i = 0; i < N; ++i)
	{
		// ��, (i, j)�� �����Ͽ� ���η� M���� ��Ⱑ �ڵ����õǴ� ���̹Ƿ�,
		// ���� ������  �� �ִ� ����� ���� N -M +1 ������ (M�� �ݵ�� N ���Ϸθ� �־�����)
		for (j = 0; j <= N - M; ++j)
		{
			// (i, j)�� ���� ���� ��ǥ�� �δ� ������ ��ġ���� ���� �ִ� ������ ���Ѵ�
			r[i][j] = getPSum(0, i, j, 0, 0);
		}
	}

	// ��� ����, ���� ��ǥ�� ���� ���ÿ� ���ð����� �� ������ ���� ���� �ִ��� ��츦 ã�´�
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j <= N - M; ++j)
		{
			// (i, j) ����� ���ÿ� ���ð����� ���� �� �ִ� ������ ���� ������ ������ ã�´�
			sum = r[i][j] + getMaxPair(i, j);
			// �ִ� ������ ���ŵǴ��� Ȯ���Ѵ�
			if (ans < sum) ans = sum;
		}
	}
	// �ִ� ���Ͱ��� ��ȯ�Ѵ�
	return ans;
}


int main(void)
{
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		//�׽�Ʈ���̽����� �ٸ� N, M, C ���� �Է¹޴´�.
		cin >> N >> M >> C;
		// �� (y,x)�� ���� ��ǥ�� �ϴ� ������ �ִ� ���� ������ �ʱ�ȭ�Ѵ�
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; j++) r[i][j] = 0;
		// �� ��⺰ ���� �Է��� �Է¹޴´�
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)
			cin >> h[i][j];
		// �׽�Ʈ���̽��� ���� ����Ѵ� 
		cout << "#" << tc << " " << solve() << endl;
	}
	return 0;
}

#endif