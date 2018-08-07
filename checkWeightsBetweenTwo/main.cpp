/*
* main.cpp
*
*  Created on: 2018. 7. 19.
*      Author: HY
*
*      백준 1717 응용
*/

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
