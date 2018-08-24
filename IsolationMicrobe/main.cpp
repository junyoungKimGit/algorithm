//2382. [모의 SW 역량테스트] 미생물 격리

#include <iostream>

using namespace std;

#define MAX_N (101)
#define MAX_K (1001)
#define MAX_M (1001)

int T, N, M, K;
int gMaxMicro;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

class cMicro
{
public:

	cMicro() {};
	~cMicro() {};
	
	cMicro(int aX, int aY, int aDir, int aCnt);	
	int mX;
	int mY;
	int mDir;
	int mCnt;
	int mAlive;
	int mMaxCnt; //To Direct

	void init(int aCnt, int aDir, int aTestcase, int aMaxCnt = 0);
	void merge(cMicro aMicro);
};

cMicro::cMicro(int aX, int aY, int aDir, int aCnt) :mX(aX), mY(aY), mDir(aDir), mCnt(aCnt) {};

void cMicro::init(int aCnt, int aDir, int aTestcase, int aMaxCnt)
{	
	mCnt = aCnt;
	mDir = aDir;
	mAlive = aTestcase;
	mMaxCnt = aMaxCnt;
}

void cMicro::merge(cMicro aMicro)
{
	mCnt += aMicro.mCnt;
}

cMicro gMicro[MAX_N][MAX_N];
cMicro gNextMicro[MAX_N][MAX_N];

void printMicro()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << gMicro[i][j].mCnt<<" ";
		}
		cout << endl;
	}
	cout << endl;
}


void findSolve(int aTime, int aTestcase)
{
	int sDX;
	int sDY;
	//move
	for (int sTime = 0; sTime < M; sTime++) 
	{
		/*cout << "time : " << sTime << endl;
		printMicro();*/
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (gMicro[i][j].mAlive == aTestcase)
				{
					sDX = i + dx[gMicro[i][j].mDir];
					sDY = j + dy[gMicro[i][j].mDir];

					if (sDX == 0 || sDX == N-1 || sDY == 0 || sDY == N -1)
					{
						//약품 경계 도착
						if (gMicro[i][j].mCnt / 2 == 0)
							gNextMicro[sDX][sDY].mAlive = 0;
						gNextMicro[sDX][sDY].mAlive = gMicro[i][j].mAlive;
						gNextMicro[sDX][sDY].mCnt = gMicro[i][j].mCnt / 2;
						gNextMicro[sDX][sDY].mMaxCnt = gMicro[i][j].mCnt / 2;

						switch (gMicro[i][j].mDir)
						{
							case 0 : //상
								gNextMicro[sDX][sDY].mDir = 1; // 하
								break;
							case 1 : //하
								gNextMicro[sDX][sDY].mDir = 0; // 상
								break;
							case 2: //좌
								gNextMicro[sDX][sDY].mDir = 3; // 우
								break;
							case 3: //우
								gNextMicro[sDX][sDY].mDir = 2; // 좌
								break;
							default :
								cout << "ERROR!!! mDir : " <<gMicro[i][j].mDir<< endl;
								break;
						}
						continue;
					}

					if (gNextMicro[sDX][sDY].mAlive != aTestcase)
					{
						//비어있다면
						gNextMicro[sDX][sDY].mCnt = gMicro[i][j].mCnt;
						gNextMicro[sDX][sDY].mMaxCnt = gMicro[i][j].mCnt;
						gNextMicro[sDX][sDY].mDir = gMicro[i][j].mDir;
						gNextMicro[sDX][sDY].mAlive = gMicro[i][j].mAlive;

					}
					else
					{
						//차있다면
						if (gNextMicro[sDX][sDY].mMaxCnt > gMicro[i][j].mCnt)
						{
							//작다
							gNextMicro[sDX][sDY].mCnt += gMicro[i][j].mCnt;
						}
						else
						{
							//크다
							gNextMicro[sDX][sDY].mCnt += gMicro[i][j].mCnt;
							gNextMicro[sDX][sDY].mMaxCnt = gMicro[i][j].mCnt;
							gNextMicro[sDX][sDY].mDir = gMicro[i][j].mDir;
						}
							
					}
				}
			}
		}



		//swap and reset
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				gMicro[i][j] = gNextMicro[i][j];
				gNextMicro[i][j].init(0, 0, 0);
			}
		}

	}

	//cout << "final" << endl;
	//printMicro();

	//calc
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (gMicro[i][j].mAlive == aTestcase)
			{
				gMaxMicro += gMicro[i][j].mCnt;
			}
		}
	}

}

int main()
{
	cin >> T;
	int x, y, cnt, dir;
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y >> cnt >> dir;
			gMicro[x][y].init(cnt, dir - 1, t);
			gMicro[x][y].mAlive = t;
		}
		
		findSolve(0, t);

		cout << "#" << t << " " << gMaxMicro << endl;
		gMaxMicro = 0;
	}

	//cin >> T;
	return 0;
}






