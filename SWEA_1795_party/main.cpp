//1795. 인수의 생일 파티

#include<stdio.h>
#define INF 1000000000

int v, e, party, go[1010][1010], back[1010][1010], check[1010], shortpath[1010], time[1010];
void init();
int getsmallindex();
void dijkstra(int start, int kk[][1010]);
void clsarr();

int main() {
	int t, testcase, i, j, a, b, c, max;

	scanf("%d", &testcase);

	for (t = 1; t <= testcase; t++) {
		scanf("%d %d %d", &v, &e, &party);
		max = 0;
		init();

		for (i = 0; i < e; i++) {
			scanf("%d %d %d", &a, &b, &c);
			go[a][b] = c;
			back[b][a] = c;
		}

		dijkstra(party, go);
		for (i = 1; i <= v; i++)
			time[i] += shortpath[i];
		clsarr();
		dijkstra(party, back);
		for (i = 1; i <= v; i++)
			time[i] += shortpath[i];
		clsarr();

		for (i = 1; i <= v; i++)
			if (max < time[i])
				max = time[i];

		printf("#%d %d\n", t, max);
	}


	return 0;
}

void init() {
	int u, p;

	for (u = 1; u <= v; u++) {
		time[u] = 0;
		for (p = 1; p <= v; p++) {
			if (u == p)
				continue;
			go[u][p] = INF;
			back[u][p] = INF;
		}
	}
}

int getsmallindex() {
	int k, min = INF, index = -1;

	for (k = 1; k <= v; k++) {
		if (check[k] == 0 && shortpath[k] < min) {
			index = k;
			min = shortpath[k];
		}
	}

	return index;

}

void dijkstra(int start, int kk[][1010]) {
	int u, p, val;

	for (u = 1; u <= v; u++) {
		shortpath[u] = kk[start][u];
	}

	check[start] = 1;

	for (u = 1; u <= v; u++) {
		val = getsmallindex();

		if (val == -1)
			break;

		check[val] = 1;

		for (p = 1; p <= v; p++) {
			if (shortpath[p] > shortpath[val] + kk[val][p])
				shortpath[p] = shortpath[val] + kk[val][p];
		}
	}
}

void clsarr() {
	int pp;

	for (pp = 1; pp <= v; pp++)
		check[pp] = 0;
}
