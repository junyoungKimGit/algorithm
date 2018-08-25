
/*
*      백준 3055 탈출
*
in
3 3
D.*
...
.S.

out
3

in
3 3
D.*
...
..S

out
KAKTUS

in
3 6
D...*.
.X.X..
....S.

out
6


http://js1jj2sk3.tistory.com/69?category=725176

*/

#if 1
#include <iostream>

using namespace std;

#define MAX_N (50)

enum
{
	eRockNHole = -1,
	eEmpty = 0,

};

typedef struct
{
	int mX;
	int mY;
}cPoint;

int gGraph[MAX_N][MAX_N];

cPoint gQ[MAX_N];
int gQHead = 0;
int gQTtail = 0;
int gQSize = MAX_N;

void EnQ(int aX, int aY)
{
	cPoint sData;
	sData.mX = aX;
	sData.mY = aY;

	gQ[gQTtail] = sData;
	gQTtail = (gQTtail + 1) % gQSize;
}

cPoint DeQ(void)
{
	cPoint sData = gQ[gQHead];
	gQHead = (gQHead + 1) % gQSize;

	return sData;
}

bool isEmptyQ()
{
	if (gQHead == gQTtail)
		return true;
	else
		return false;
}

int abs()
{
	return gQTtail - gQHead;
}

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

cPoint gHedgehog;
cPoint gHole;
cPoint gWater[MAX_N];


void bfsWithWater(int aX, int aY)
{
	cPoint sWater;

	//init
	int sTimer = 1;

	int sDX;
	int sDY;
	int sQSize;
	while (isEmptyQ() != true)
	{
		sTimer++;

		sQSize = abs();
		while (sQSize--)
		{
			sWater = DeQ();

			for (int i = 0; i < 4; i++)
			{
				sDX = sWater.mX + dx[i];
				sDY = sWater.mY + dy[i];

				if (sDX < aX && sDX > -1 && sDY < aY && sDY > -1)
				{
					if (gGraph[sDX][sDY] == 0)// && gGraph[sDX][sDY] < sTimer)
					{
						//						cout<<"AAAA"<<endl;
						//						if( gGraph[sDX][sDY] < sTimer)
						gGraph[sDX][sDY] = sTimer;
						EnQ(sDX, sDY);
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
}

int bfsWithHedgehog(int aX, int aY)
{

	int sMoveCnt = 0;
	int sQSize = 0;
	int sDX, sDY;

	cPoint sCurrHedgeHog;
	while (isEmptyQ() != true)
	{

		sQSize = abs();
		while (sQSize--)
		{
			sCurrHedgeHog = DeQ();
			cout << "DEQ?? : " << sCurrHedgeHog.mX << " " << sCurrHedgeHog.mY << " movecnt : " << sMoveCnt << endl;


			for (int i = 0; i< 4; i++)
			{
				sDX = sCurrHedgeHog.mX + dx[i];
				sDY = sCurrHedgeHog.mY + dy[i];
				if (sDX < aX && sDX > -1 && sDY < aY && sDY > -1)
				{
					if (gGraph[sDX][sDY] != -1 && gGraph[sDX][sDY] > sMoveCnt)
					{
						cout << "ENQ?? : " << sDX << " " << sDY << " movecnt : " << sMoveCnt << endl;
						gGraph[sDX][sDY] = -1;
						EnQ(sDX, sDY);
					}

					if (gHole.mX == sDX && gHole.mY == sDY && gGraph[sDX][sDY] > sMoveCnt)
					{
						cout << "FOUND!!" << endl;
						return sMoveCnt + 1;
					}

				}

			}
		}
		sMoveCnt++;
	}
	return -1;


}

int main()
{
	int sX, sY;

	cin >> sX >> sY;

	char sIN;
	int sWaterCnt = 0;
	for (int i = 0; i< sX; i++)
	{
		for (int j = 0; j < sY; j++)
		{
			cin >> sIN;
			switch (sIN)
			{
			case 'X':
				gGraph[i][j] = eRockNHole;
				break;
			case '.':
				gGraph[i][j] = eEmpty;
				break;
			case 'D':
				gHole.mX = i;
				gHole.mY = j;
				gGraph[i][j] = eRockNHole;
				break;
			case 'S':
				gHedgehog.mX = i;
				gHedgehog.mY = j;
				break;
			case '*':
				gGraph[i][j] = 1;
				EnQ(i, j);
				sWaterCnt++;
				break;
			default:
				cout << "ERROR INPUT" << endl;
				break;
			}
		}
	}

	for (int i = 0; i < sX; i++)
	{
		for (int j = 0; j< sY; j++)
		{
			cout << gGraph[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;

	//water
	bfsWithWater(sX, sY);

	for (int i = 0; i < sX; i++)
	{
		for (int j = 0; j< sY; j++)
		{
			cout << gGraph[i][j] << " ";
		}
		cout << endl;
	}

	//hedgehog
	EnQ(gHedgehog.mX, gHedgehog.mY);
	gGraph[gHedgehog.mX][gHedgehog.mY] = -1;
	int sHedgeHogMoveCnt = 0;
	sHedgeHogMoveCnt = bfsWithHedgehog(sX, sY);
	cout << "ANSWER is" << endl;
	cout << sHedgeHogMoveCnt << endl;

}

#endif

#if 0

#include <stdio.h>
#include <iostream>
using namespace std;
typedef struct col {
	int x, y;
}col;

col que[10000];
int que_front, que_back;
#define que_size 10000
void que_push(int x, int y) {
	que[que_back] = { x,y };
	que_back = (que_back + 1) % que_size;
}
col que_pop() {
	col tmp = que[que_front];
	que_front = (que_front + 1) % que_size;

	return tmp;
}

char buf[51];
int r, c;
int map[50][50];
int waters_cnt;
col waters[2500];
col start, dst;

int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int abs(int x) {
	return x > 0 ? x : -x;
}

void water_bfs() {
	int cnt = 2;

	while (que_front != que_back) {
		int size = abs(que_back - que_front);

		while (size--) {
			col tmp = que_pop();

			for (int i = 0; i < 4; ++i) {
				int xx = tmp.x + dir[i][0];
				int yy = tmp.y + dir[i][1];

				if (xx < 0 || yy < 0 || xx >= r || yy >= c)
					continue;

				if (map[xx][yy] != 0)
					continue;

				que_push(xx, yy);
				map[xx][yy] = cnt;
			}
		}
		cnt++;
	}
}

int beaber_bfs() {
	int cnt = 2;

	while (que_front != que_back) {
		int size = abs(que_front - que_back);

		while (size--) {
			col tmp = que_pop();

			for (int i = 0; i < 4; ++i) {
				int xx = tmp.x + dir[i][0];
				int yy = tmp.y + dir[i][1];

				if (xx < 0 || yy < 0 || xx >= r || yy >= c)
					continue;

				if (xx == dst.x && yy == dst.y)
					return cnt;

				if (map[xx][yy] == 0) {
					que_push(xx, yy);
					map[xx][yy] = -1;
					continue;
				}

				if (map[xx][yy] == -1)
					continue;

				if (map[xx][yy] <= cnt)
					continue;

				que_push(xx, yy);
				map[xx][yy] = -1;
			}
		}

		cnt++;
	}
	return -1;
}

int main() {
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; ++i) {
		scanf("%s", buf);
		for (int j = 0; j < c; ++j) {
			if (buf[j] == '.') // 길
				continue;
			else if (buf[j] == 'D') { // 비버굴
				dst = { i,j };
				map[i][j] = -1;
			}
			else if (buf[j] == 'S') { // 고슴도치
				start = { i,j };
			}
			else if (buf[j] == 'X') // 돌
				map[i][j] = -1;
			else { // 물
				waters[waters_cnt++] = { i,j };
				map[i][j] = 1;
			}
		}
	}

	//물이 번지는 시간 기록
	for (int i = 0; i < waters_cnt; ++i)
		que_push(waters[i].x, waters[i].y);
	water_bfs();

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j< c; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}


	map[start.x][start.y] = -1;
	que_push(start.x, start.y);

	int ans = beaber_bfs();
	if (ans == -1)
		printf("KAKTUS");
	else
		printf("%d\n", ans - 1);

	return 0;
}

#endif
