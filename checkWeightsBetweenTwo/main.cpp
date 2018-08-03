/*
* main.cpp
*
*  Created on: 2018. 7. 19.
*      Author: HY
*
*      백준 1717 응용
*/

#if 1
#include <iostream>

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

using std::cin;
using std::cout;
using std::endl;

int parentA[1000001] = { 0, };
int weightA[1000001] = { 0, };

//ver1
int findP(int a)
{
	if (parentA[a] < 0)
	{
		return a;
	}
	else
	{
		//
		weightA[a] += weightA[parentA[a]];
		return parentA[a] = findP(parentA[a]);
	}
}


void uni(int a, int b, int w)
{
	/*
	int x, y;
	x = findP(a);
	y = findP(b);

	parentA[x] = y;
	*/


	int pa = findP(a);
	int pb = findP(b);

	if (pa == pb)
		return;

	if (parentA[pa] > parentA[pb])
	{
		swap(a, b);
		swap(pa, pb);
		w = -w;
	}

	parentA[pb] += parentA[pb];
	parentA[a] = pb;
	weightA[pa] = -w + weightA[a] - weightA[b];

}




int main()
{
	int T;
	int S, W;
	int cnt = 1;

	int max = 0;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> S >> W;

		for (int i = 0; i < S + 1; i++)
		{
			parentA[i] = -1;
			weightA[i] = 0;
		}

		cout << "#" << i + 1 << " ";

		char op;
		int a, b, w;

		for (int j = 0; j < W; j++)
		{
			cin >> op;

			if (op == '?')
			{
				cin >> a >> b;
				if (findP(a) != findP(b))
					cout << "UNKNOWN";

				cout << weightA[b] - weightA[a] << " ";
			}
			else
			{
				cin >> a >> b >> w;
				uni(a, b, w);
			}
		}

		cout << endl;
	}

	return 0;
}

#endif

#if 0
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int t, n, m;
int dist[100001];
int p[100001];
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int find(int a)
{
	if (p[a] < 0)
		return a;
	dist[a] += dist[p[a]];
	p[a] = find(p[a]);
	int res = find(p[a]);
	return res;

}

bool merge(int a, int b, int diff)
{
	int pa = find(a);
	int pb = find(b);
	if (pa == pb)
		return true;

	if (p[pa] < p[pb])
	{
		swap(a, b);
		swap(pa, pb);
		diff = -diff;
	}

	//
	dist[pa] = dist[b] + diff - dist[a];
	p[pb] += p[pa];
	p[a] = pb;

	//

	//	cout<<endl<<"merge a : "<<a<<" b : "<<b<<endl;
	//	for(int i = 0; i < 5; i++)
	//	{
	//		cout<<"p["<<i<<"] : "<< p[i]<<"  ";
	//
	//	}
	//	cout<<endl;
	//	for(int i = 0; i < 5; i++)
	//	{
	//		cout<<"W["<<i<<"] : "<< dist[i]<<"  ";
	//
	//	}
	//	cout<<endl;


	return false;
}

int main()
{

	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++)
	{
		cin >> n >> m;
		cout << "#" << testcase << " ";
		memset(dist, 0, sizeof(dist));
		memset(p, -1, sizeof(p));
		for (int i = 0; i < m; i++)
		{
			char tmp;
			cin >> tmp;
			if (tmp == '!')
			{
				int a, b, d;
				cin >> a >> b >> d;
				merge(a, b, d);
			}
			else
			{
				int a, b;
				cin >> a >> b;
				if (find(a) != find(b)) cout << "UNKNOWN ";
				else
				{
					//					cout<<a<<b<<endl;
					//					cout<<"dist[b] : "<< dist[b]<<" dist[a] : "<<dist[a]<<endl;
					cout << -dist[b] + dist[a] << " ";

					//					for(int i = 0; i < 5; i++)
					//					{
					//						cout<<"W["<<i<<"] : "<< dist[i]<<"  ";
					//
					//					}
					//					cout<<endl;
				}
			}
		}
		cout << "\n";

	}
}

#endif
