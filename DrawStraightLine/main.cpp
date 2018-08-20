//5170. 상원이의 직선 긋기 게임

#include <iostream>

using namespace std;

int gCoord[200][2]; //[i][0] 분자 [i][1] 분모
int gMap[4002][4002]; //x,y -1000 ~ 1000 => diff 2000 + bias 2000

int T, N;
int gCnt;

int abs(int aA)
{
	return aA > 0 ? aA : -aA;
}

//https://opentutorials.org/course/1685/9533
//유클리드 호재법으로 gcd 찾기
int gcd(int a, int b)
{ //반복문을 이용한 방법
	int mod = a % b;
	while (mod > 0)
	{
		a = b;
		b = mod;
		mod = a % b;
	}
	return b;
}

int gcdEX(int aA, int aB)
{
	int sGCD = 0;
	if (aA > aB)
	{
		sGCD = gcd(aA, aB);
	}
	else
	{
		sGCD = gcd(aB, aA);
	}

	return sGCD;
}


int main()
{

	cin >> T;

	int sParent = 0;
	int sChild = 0;
	int sGCD = 0;

	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> gCoord[i][0] >> gCoord[i][1];
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = i+1; j < N; j++)
			{		
				sChild = gCoord[i][0] - gCoord[j][0];
				sParent = gCoord[i][1] - gCoord[j][1];
				if (sParent == 0)
				{
					if (gMap[2000][0] != t)
					{
						gCnt++;
						gMap[2000][0] = t;
						//cout << "sParent == 0 " << endl;
					}
					continue;
				}

				if (sChild == 0)
				{
					if (gMap[0][2000] != t)
					{
						gCnt++;
						gMap[0][2000] = t;
						//cout << "sChild == 0 " << endl;
					}
					continue;
				}

				sGCD = gcdEX(abs(sChild), abs(sParent));
				if (sChild * sParent > 0)
				{
					sChild = abs(sChild);
					sParent = abs(sParent);
				}
				else
				{
					sChild = -abs(sChild);
					sParent = abs(sParent);
				}

				if (gMap[sChild / sGCD + 2000][sParent / sGCD + 2000] != t)
				{
					gCnt++;
					gMap[sChild / sGCD + 2000][sParent / sGCD + 2000] = t;

					//cout << "sParent : " << sParent << " sChild : " << sChild << endl;
				}
			}
		}

		cout << "#" << t << " " << gCnt << endl;
		gCnt = 0;
	}

	cin >> T;

	return 0;
}