//5432. 쇠막대기 자르기

#include <iostream>

#define MAX_N (100001)

using namespace std;

char gIn[MAX_N];

int T;

int findSolve()
{
	int sCurrentRod = 0;
	int sIdx = 0;
	int sTotalCnt = 0;

	while (gIn[sIdx] != '\0' && gIn[sIdx+1] != '\0')
	{
		if (gIn[sIdx] == '(' && gIn[sIdx + 1] != ')')
		{
			sCurrentRod++;
			sTotalCnt++;
		}
		else if (gIn[sIdx] == '(' && gIn[sIdx + 1] == ')')
		{
			sIdx++;
			sTotalCnt += sCurrentRod;
		}
		else if (gIn[sIdx] == ')')
		{
			sCurrentRod--;
		}

		sIdx++;
	}

	return sTotalCnt;
}


int main()
{

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> gIn;

		cout << "#" << tc << " " << findSolve() << endl;

	}

	cin >> T;

	return 0;
}
