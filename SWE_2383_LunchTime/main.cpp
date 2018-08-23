//2383 ���� �Ļ�ð�

#include <iostream>

using namespace std;

#define MAX_N (10)
#define MAX_MAN (10)
#define MAX_STAIR (2)
#define MAX_STAIR_LENGTH (10)
#define MAX_TIME (MAX_MAN * MAX_MAN + MAX_N * 2)


int T, N;
int gMinTime;
int gMap[MAX_N][MAX_N];
int gManIdx;

typedef struct
{
	int mX;
	int mY;
} stMan;

typedef struct
{
	int mX;
	int mY;
	int mStairLength;
} stStair;

stMan gMAN[MAX_MAN];
stStair gStair[MAX_STAIR];

int gMatchManWithStair[MAX_N];//i ��° ����� �̿��ϴ� ��� idx (0 or 1)


int min(int aA, int aB)
{
	return aA > aB ? aB : aA;
}

int max(int aA, int aB)
{
	return aA > aB ? aA : aB;
}

int abs(int aA, int aB)
{
	return (aA - aB) > 0 ? aA - aB : aB - aA;
}

//��ܰ� ������� �Ÿ�
int dist(int aManIdx, int aStaitIdx)
{
	int dx = abs(gMAN[aManIdx].mX - gStair[aStaitIdx].mX);
	int dy = abs(gMAN[aManIdx].mY - gStair[aStaitIdx].mY);

	return dx + dy;
}



//��� ����� �� dfs�� ���Ͽ� �ּ� �� ���
void calcTime()
{
	int sTotalMinTime = 0;
	for (int sStaitIdx = 0; sStaitIdx < MAX_STAIR; sStaitIdx++)
	{
		int sArriveManCntAtTime[MAX_N * 2] = { 0, };
		//�ð� t���� ��ܿ� �����ϴ� ��� ��
		int sCurrStair[MAX_TIME] = { 0, };
		//�ð� t���� ����� �������� ����� ��

		for (int sManIdx = 0; sManIdx < gManIdx; sManIdx++)
		{
			if (gMatchManWithStair[sManIdx] == sStaitIdx)
			{
				sArriveManCntAtTime[dist(sManIdx, sStaitIdx) + 1]++;
			}
		}
		//����� �������� ����� ��� �۾��� ��ġ�� ���� �ʿ��� �ּ� �ð�
		int sNowMinTime = 0;
		for (int sTime = 1; sTime <= 20; sTime++)
		{
			while (sArriveManCntAtTime[sTime] > 0)
			{
				sArriveManCntAtTime[sTime]--;

				int sRemainTime = gStair[sStaitIdx].mStairLength;

				//��ܿ� ������ ������ ��� 3���� ���ÿ� �������� ���� ���� ���� 
				//1ĭ�� ������ ���� ����
				for (int sWalkTime = sTime; sWalkTime < MAX_TIME; sWalkTime++)
				{
					if (sCurrStair[sWalkTime] < 3)
					{
						sCurrStair[sWalkTime]++;
						sRemainTime--;

						if (sRemainTime == 0)
						{
							sNowMinTime = max(sNowMinTime, sWalkTime + 1);
							break;
						}
					}
				}
			}
		}
		//"��ü ����� �������µ� �ʿ��� �ּ� �ð�"
		// = (�� ����� �������µ� �ʿ��� �ּ� �ð�) �� �ִ�
		sTotalMinTime = max(sTotalMinTime, sNowMinTime);
	}

	gMinTime = min(gMinTime, sTotalMinTime);
}

//��� ����� �� dfs
void findSolve( int aManCnt)
{
	
	if (aManCnt == gManIdx)
	{
		calcTime();
		return;
	}

	for (int i = 0; i < MAX_STAIR; i++)
	{
		gMatchManWithStair[aManCnt] = i;
		findSolve(aManCnt + 1);
	}

}
int main()
{

	cin >> T;

	int sStairIdx = 0;

	for (int t = 1; t <= T; t++)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> gMap[i][j];

				if (gMap[i][j] == 1)
				{
					gMAN[gManIdx].mX = i;
					gMAN[gManIdx].mY = j;
					gManIdx++;
				}
				else if(gMap[i][j] > 1)
				{
					gStair[sStairIdx].mX = i;
					gStair[sStairIdx].mY = j;
					gStair[sStairIdx].mStairLength = gMap[i][j];
					sStairIdx++;
				}
			}
		}

		gMinTime = 10e9;

		findSolve(0);

		cout << "#" << t << " " << gMinTime << endl;

		gManIdx = 0;
		sStairIdx = 0;



	}

	cin >> T;
	return 0;
}