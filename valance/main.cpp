//[S/W 문제해결 응용] 2일차 - 균형점   [8]New 정답

#include <iostream>
#include <cstring>

using namespace std;

//#define THRESHOLD (0.0000000001)
long double THRESHOLD = 0.000000001;
#define MAX_N (10)

int gPosition[MAX_N] = { 0, };
int gWeight[MAX_N] = { 0, };

double myAbs(double aA)
{
	return aA > 0 ? aA : -aA;
}

double findPosition(int aNodeCnt, int aIdx)
{
	double sLeft = gPosition[aIdx];
	double sRight = gPosition[aIdx+1];
	double sMid;

	long double sLeftTotalF = 0;
	long double sRightTotalF = 0;
		
	int test;
	//do
	for(int j = 0; j < 80; j++)
	{
		sLeftTotalF = 0;
		sRightTotalF = 0;
		sMid = (sLeft + sRight) / 2.0;
		for (int i = 0; i <= aIdx; i++)
		{
			sLeftTotalF += gWeight[i] / ((sMid - gPosition[i]) * (sMid - gPosition[i]));
		}

		for (int i = aIdx + 1; i < aNodeCnt; i++)
		{
			sRightTotalF += gWeight[i] / ((gPosition[i] - sMid) * (gPosition[i] - sMid));
		}

		//cout << "LF : " << sLeftTotalF << " RF : " << sRightTotalF << " left : " << sLeft << " Right : " << sRight << " mid : " << sMid << endl;
		if (sLeftTotalF > sRightTotalF)
			sLeft = sMid;
		else
			sRight = sMid;
		//cout << "LF : " << sLeftTotalF << " RF : " << sRightTotalF << " left : " << sLeft << " Right : " << sRight << " mid : " << sMid << endl;

	}
	//} while (myAbs(sLeftTotalF - sRightTotalF) > THRESHOLD);
	
	//cout << "FOUND" << sMid;
	return sMid;
}

int main()
{
	/*
	cout << 10*1.5*1.5 << endl;
	cout << 10*(1 + 0.5)*(1 + 0.5) << endl;
	cout << 10*-1.5*-1.5 << endl;
	*/
	cout << fixed;
	cout.precision(10);
	
	int sTestCnt;
	cin >> sTestCnt;

	int sNodeCnt;
	double sResult;
	
	for (int i = 0; i < sTestCnt; i++)
	{
		memset(gPosition, 0, sizeof(gPosition));
		memset(gWeight, 0, sizeof(gWeight));
		cin >> sNodeCnt;

		for (int j = 0; j < sNodeCnt; j++)
		{
			cin >> gPosition[j];
		}
		for (int j = 0; j < sNodeCnt; j++)
		{
			cin >> gWeight[j];
		}

		cout << "#" << i + 1 << " ";
		for (int j = 0; j < sNodeCnt - 1; j++)
		{
			sResult = findPosition(sNodeCnt, j);
			//sResult = solve(j, gPosition, gWeight,sNodeCnt);
			cout << sResult<<" ";
		}
		cout << endl;
	}
	
	
	int s;
	cin >> s;


	 return 0;
}
