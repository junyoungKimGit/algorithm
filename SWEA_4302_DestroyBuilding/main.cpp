//SWEA 4302. °Ç¹° ºØ±« ¿¹Ãø ½Ã½ºÅÛ

#include <iostream>

using namespace std;

#define MAX_N (100001)

typedef struct stBuilding
{
	int mX;
	int mY;
	int mD;
	bool mIsAlive;
};

int min(int aA, int aB)
{
	return aA > aB ? aB : aA;
}
int abs(int aA)
{
	return aA > 0 ? aA : -aA;
}

int distBuildings(stBuilding aA, stBuilding aB)
{
	return abs(aA.mX - aB.mY) + abs(aA.mY - aB.mY);
}

int damage(stBuilding aSource, stBuilding aTarger)
{
	return 10 / distBuildings(aSource, aTarger);
}

stBuilding gBuildings[MAX_N];

int gQ[MAX_N];
int gQHead;
int gQTail;
int gQSize = MAX_N;

int getQSize()
{
	return abs(gQTail - gQHead);
}

void EnQ(int aA)
{
	gQ[gQTail] = aA;
	gQTail = (gQTail + 1) & gQSize;
}

int DeQ()
{
	int sData = gQ[gQHead];
	gQHead = (gQHead + 1) & gQSize;

	return sData;
}

int T;
int N, W, K;
int gBuildingCnt;
int gCurrentD;

void getAliveBuildings()
{
	for (int i = 0; i < N; i++)
	{
		if (gBuildings[i].mIsAlive == true)
			gBuildingCnt++;
	}
}

void findSolve()
{
	while (K > 0)
	{

	}
}

int main()
{

	cin >> T;


	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> W >> K;

		gCurrentD = 10;
		gQHead = 0;
		gQTail = 0;
		gBuildingCnt = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> gBuildings[i].mX >> gBuildings[i].mY >> gBuildings[i].mD;
			gBuildings[i].mIsAlive = true;
			gCurrentD = min(gCurrentD, gBuildings[i].mD);
		}

		findSolve();

		cout << "#" << tc << " " << gBuildingCnt << endl;
	}

	cin >> T;
	return 0;
}

#if 0

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct building {
	int d, x, y;
};

int c[100001];
int t, n, w, k;
building a[100001];
vector<vector<int>> adj;

bool cmp(const building &p, const building &q) {
	if (p.x < q.x) return true;
	else if (p.x == q.x && p.y < q.y) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		memset(c, 0, sizeof(c));
		cin >> n >> w >> k;
		if (adj.size() < n) adj.resize(n);
		for (int i = 0; i < n; i++) {
			adj[i].clear();
			int x, y, d;
			cin >> x >> y >> d;
			a[i] = { d,x,y };
		}
		sort(a, a + n, cmp);
		register int dx, dy;
		queue<int> q;
		int ans = n;
		for (int i = 0; i < n; i++) {
			if (a[i].d <= k) {
				c[i] = 1;
				ans--;
				q.push(i);
			}
			for (int j = i + 1; j < n; j++) {
				dx = abs(a[j].x - a[i].x);
				if (dx > 10) break;
				dy = abs(a[j].y - a[i].y);
				if (dx + dy > 10) continue;
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
		while (q.size()) {
			int idx = q.front();
			q.pop();
			for (auto &j : adj[idx]) {
				if (c[j]) continue;
				int dif = abs(a[idx].x - a[j].x) + abs(a[idx].y - a[j].y);
				a[j].d -= 10 / dif;
				if (a[j].d - k <= 0) {
					c[j] = 1;
					q.push(j);
					ans--;
				}
			}
		}

		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}

#endif