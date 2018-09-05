//BOJ 2252 줄 세우기

#include <iostream>
#include <vector>

using namespace std;

#define MAX_N (32001)
#define MAX_M (100002)

//int gAdj[MAX_N][MAX_N];
vector<vector<int>> gAdj(MAX_N+1);
int gIngree[MAX_N];

int gQ[MAX_M];
int gQHead = 0;
int gQTail = 0;
int gQSize = MAX_M;

int N, M;

void EnQ(int aA)
{
	gQ[gQTail] = aA;
	gQTail = (gQTail + 1) % gQSize;
	//cout << "TAIL : " << gQTail << endl;
}

int DeQ()
{
	int sData = gQ[gQHead];
	gQHead++;
	gQHead = gQHead % gQSize;

	//cout << "HEAD : " << gQHead << endl;

	return sData;
}

bool isQEmpty()
{
	return gQHead == gQTail ? true : false;
}

void findSolve()
{
	for (int i = 1; i <= N; i++)
	{
		if (gIngree[i] == 0)
		{
			EnQ(i);
		}
	}

	int sData;
	while (isQEmpty() == false)
	{
		sData = DeQ();

		cout << sData << " ";

		//for (int i = 1; i <= N; i++)
		//{
		//	if (gAdj[sData][i] == 1 && gIngree[i] > 0)
		//	{
		//		EnQ(i);
		//		gIngree[i]--;
		//	}
		//}

		for (auto next : gAdj[sData]) {
			gIngree[next]--;
			if (gIngree[next] == 0)
				EnQ(next);
		}
	}
}


int main()
{

	/*EnQ(1);
	EnQ(2);
	cout << DeQ() << endl;
	EnQ(3);
	cout << DeQ() << endl;
	cout << DeQ() << endl;*/
	int sLittle, sBig;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> sLittle >> sBig;

		//gAdj[sLittle][sBig] = 1;
		gAdj[sLittle].push_back(sBig);
		gIngree[sBig]++;
	}

	findSolve();

	cin >> N;

	return 0;
}
