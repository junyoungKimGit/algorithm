//3304. 최장 공통 부분 수열 
//http://mygumi.tistory.com/126

#include <iostream>

#define MAX_LEN (1001)
using namespace std;

char ASTRING[MAX_LEN];
int ASTRINGLEN;
char BSTRING[MAX_LEN];
int BSTRINGLEN;
int LCS[MAX_LEN+1][MAX_LEN+1];


int T, N;

int getLength(char * aA)
{
	int i = 0;
	for (i = 0; i < MAX_LEN; i++)
	{
		if (aA[i] == '\0')
			break;
	}
	return i;
}

int max(int aA, int aB)
{
	return aA > aB ? aA : aB;
}

void initLCS()
{
	for (int i = 0; i <= ASTRINGLEN; i++)
		LCS[i][0] = 0;
	
	for (int j = 0; j <= BSTRINGLEN; j++)
		LCS[0][j] = 0;
}


int findSolve()
{
	ASTRINGLEN = getLength(ASTRING);
	BSTRINGLEN = getLength(BSTRING);

	initLCS();

	for (int i = 1; i <= ASTRINGLEN; i++)
	{
		for (int j = 1; j <= BSTRINGLEN; j++)
		{
			if (ASTRING[i-1] == BSTRING[j-1])
			{
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else
			{
				LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
			}
		}
	}

	return LCS[ASTRINGLEN][BSTRINGLEN];
}

//출력 함수도 구현해볼것


int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> ASTRING >> BSTRING;

		cout << "#" <<t<< " " << findSolve() << endl;
	}

	return 0;
}