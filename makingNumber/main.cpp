//4008. [모의 SW 역량테스트] 숫자 만들기
#include <iostream>

using namespace std;

#define MAX_N (12)
#define MAX_V (100000000)
#define MIN_V (-100000000)
enum Operator
{
	PLUS = 0,
	MINUS,
	PRODUCT,
	DIVIDE
};

int gNumCard[MAX_N];
int gNumOp[4];
int gMax, gMin;

int T, N;

int myMax(int aA, int aB)
{
	return aA > aB ? aA : aB;
}

int myMin(int aA, int aB)
{
	return aA < aB ? aA : aB;
}

void findSolve(int aCardCnt, int aCurrVal)
{

	//cout << "aCardCnt : " << aCardCnt << " CurrV : " << aCurrVal << endl;
	//backtrace 종료 조건
	if (aCardCnt == N)
	{
		gMax = myMax(aCurrVal, gMax);
		gMin = myMin(aCurrVal, gMin);

		//cout << "MAX : "<<gMax<<" MIN : " <<gMin << endl;
		return;
	}
	
	if (gNumOp[0] > 0)
	{
		gNumOp[0]--;
		findSolve(aCardCnt + 1, aCurrVal + gNumCard[aCardCnt]);
		gNumOp[0]++;					
	}

	if (gNumOp[1] > 0)
	{
		gNumOp[1]--;
		findSolve(aCardCnt + 1, aCurrVal - gNumCard[aCardCnt]);
		gNumOp[1]++;
	}

	if (gNumOp[2] > 0)
	{
		gNumOp[2]--;
		findSolve(aCardCnt + 1, aCurrVal * gNumCard[aCardCnt]);
		gNumOp[2]++;
	}

	if (gNumOp[3] > 0)
	{
		gNumOp[3]--;
		findSolve(aCardCnt + 1, aCurrVal / gNumCard[aCardCnt]);
		gNumOp[3]++;
	}

	return;
}

int main()
{
	cin >> T;
	
	for (int t = 1; t <= T; t++)
	{
		cin >> N;

		gMax = MIN_V;
		gMin = MAX_V;

		for (int i = 0; i < 4; i++)
		{
			cin >> gNumOp[i];
		}

		for (int i = 0; i < N; i++)
		{
			cin >> gNumCard[i];
		}

		findSolve(1, gNumCard[0]);

		cout << "#" <<t<< " " << gMax - gMin << endl;
	}	

	return 0;
}
