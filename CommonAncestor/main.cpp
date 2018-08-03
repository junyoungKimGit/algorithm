//1248. [S/W 문제해결 응용] 3일차 - 공통조상

#include <iostream>
#include <cstring>

using namespace std;


#define MAX_N (100000)

int gParent[MAX_N] = { 0, };
int gVisited[MAX_N] = { 0, };

int findParent(int aChildA, int aChildB)
{
	int sParent = 0;

	gVisited[aChildA] = 1;
	while (aChildA != 1)
	{
		aChildA = gParent[aChildA];
		gVisited[aChildA] = 1;
	}

	//cout << "gV" << endl;
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << gVisited[i] << endl;
	//}

	while(1)
	{
		//cout <<"CB : "<< aChildB << endl;
		if (gVisited[aChildB] == 1)
		{
			sParent = aChildB;
			break;
		}
		gVisited[aChildB] = 1;
		aChildB = gParent[aChildB];
		//cout << "CB A : " << aChildB << endl;
	}

	return sParent;
}

int countChildren(int aParent, int aTotalChildren)
{
	int sChildCnt = 0;

	int sTemp;

	for (int i = 1; i < aTotalChildren+1; i++)
	{
		//cout << "i " << i << " cnt : " << sChildCnt << endl;
		sTemp = i;
		if (sTemp == aParent)
		{
			sChildCnt++;
			continue;
		}

		do
		{

			sTemp = gParent[sTemp];
			if (sTemp == aParent)
			{
				sChildCnt++;
				break;
			}

		} while (sTemp != 1);
	}

	return sChildCnt;
}
int main()
{
	int sT;
	cin >> sT;
	int sN, sE, sChildA, sChildB;

	for(int t = 1; t <= sT; t++)
	{
		cin >> sN >> sE >> sChildA >> sChildB;
	
		int sP, sC;
		gParent[1] = 1;
		for (int i = 0; i < sE; i++)
		{
			cin >> sP >> sC;
			gParent[sC] = sP;
		}

		int sCommonParent = findParent(sChildA, sChildB);

		int sChildCnt = countChildren(sCommonParent, sN);

		//cout << "PA" << endl;
		//for (int i = 0; i < sE; i++)
		//{
		//	cout << gParent[i] << endl;
		//}

		//cout << "gV" << endl;
		//for (int i = 0; i < sE; i++)
		//{
		//	cout << gVisited[i] << endl;
		//}

		cout << "#" <<t<<" "<< sCommonParent <<" "<<sChildCnt<< endl;

		memset(gParent, 0, sizeof(gParent));
		memset(gVisited, 0, sizeof(gVisited));

	}
	cin >> sT;

	return 0;
}