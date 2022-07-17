#pragma warning(disable : 4996)

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int map[101][101];
int dist[101][101];
int N, M;

//좌우상하
int dir[4][2] = { {0,1}, {0, -1}, {1, 0}, {-1, 0} };
queue<pair<int, int>> q;

int findPath()
{
	//init
	q.push({ 0,0 });
	dist[0][0] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dx = x + dir[i][0];
			int dy = y + dir[i][1];

			if (dx < 0 || dy < 0 || dx >= N || dy >= M)
			{
				continue;
			}

			//벽
			if (map[dx][dy]== 1)
			{
				if (dist[dx][dy] > dist[x][y] + 1)
				{
					dist[dx][dy] = dist[x][y] + 1;
					q.push({ dx, dy });

				}
			}
			//벽 아님
			if (map[dx][dy] == 0)
			{
				if (dist[dx][dy] > dist[x][y])
				{
					dist[dx][dy] = dist[x][y];
					q.push({ dx, dy });

				}
			}
		}
	}

	return dist[N-1][M-1];
}

int main(void)
{
	//N 가로 x, M 세로 y
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//cin >> map[i][j];
			scanf("%1d",&map[i][j]);
			dist[i][j] = 101 * 101;
		}
	}

	cout << findPath();



	return 0;
}