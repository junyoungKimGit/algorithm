//1265. [S/W 문제해결 응용] 9일차 - 달란트2

#include <iostream>

using namespace std;

unsigned long long countDalant(int aTotalCandy, int aBundleNum)
{
	unsigned long long  sResult = 1;

	int sLeft = aTotalCandy % aBundleNum;
	int sBundleCnt = aTotalCandy / aBundleNum;

	sBundleCnt++;
	for (int i = 0; i < aBundleNum; i++)
	{
		if (i == sLeft)
		{
			sBundleCnt -= 1;
		}
		sResult *= sBundleCnt;		
	}

	return sResult;


}

int main()
{
	//cout << fixed;
	cout.precision(10);
	int sTest;

	cin >> sTest;

	int sCandyCnt;
	int sBundle;
	for (int i = 0; i < sTest; i++)
	{
		cin >> sCandyCnt >> sBundle;
		cout<<"#"<<i+1<<" " << countDalant(sCandyCnt, sBundle) << endl;
	}
	
	cin >> sTest;

	return 0;
}