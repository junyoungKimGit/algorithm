/*
* main.cpp
*
*  Created on: 2018. 7. 27.
*      Author: HY
*
1247. [S/W 문제해결 응용] 3일차 - 최적 경로
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15OZ4qAPICFAYD
http://gorakgarak.tistory.com/522
*/
#include <iostream>

using namespace std;

#define MAX_CLIENT (10)
#define MAX_PATH (20001)

class cPoint
{
public:
	int mX;
	int mY;
};

cPoint gLocation[MAX_CLIENT + 2];
int gTotalPath = 0;

void swap(int aA, int aB)
{
	cPoint sTemp;
	sTemp = gLocation[aA];
	gLocation[aA] = gLocation[aB];
	gLocation[aB] = sTemp;
}


int abs(int a)
{
	return a > 0 ? a : -a;
}
int distLocs(cPoint aA, cPoint aB)
{
	return abs(aA.mX - aB.mX) + abs(aA.mY - aB.mY);
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

}

int calTotal(int aClientCnt)
{
	int sRet = 0;

	for (int i = 0; i < aClientCnt + 1; i++)
	{
		sRet += distLocs(gLocation[i], gLocation[i + 1]);
	}

	return sRet;
}
void perm(int aPos, int aClientCnt)
{
	if (aPos == aClientCnt)
	{
		int sTempDist = 0;
		sTempDist = calTotal(aClientCnt);

		if (gTotalPath > sTempDist)
			gTotalPath = sTempDist;
		return;
	}

	for (int i = aPos; i < aClientCnt + 1; i++)
	{
		swap(gLocation[i], gLocation[aPos]);
		perm(aPos + 1, aClientCnt);
		swap(gLocation[i], gLocation[aPos]);
	}
}


int main()
{
	//unit test
	//	cout<<abs(4)<<endl;
	//	cPoint A;
	//	cPoint B;
	//	A.mX = 10;
	//	A.mY = 20;
	//
	//	B.mX = 30;
	//	B.mY = 10;
	//
	//	cout<<abs(A.mX - B.mX)<<" "<<abs(A.mY -B.mY)<<endl;
	//
	//	cout<<distLocs(A,B)<<endl;
	//
	//	int arr[5];
	//	for(int i = 0; i < 5; i++){
	//		arr[i] = i;
	//	}
	//	perm(arr, 1, 4);


	int sTest;

	cin >> sTest;
	for (int i = 0; i < sTest; i++)
	{
		int sN;
		cPoint sTempP;

		cin >> sN;

		for (int j = 0; j < sN + 2; j++)
		{
			cin >> sTempP.mX >> sTempP.mY;
			gLocation[j] = sTempP;
		}
		swap(gLocation[1], gLocation[sN + 1]);

		//		for(int i = 0; i < sN+2; i++)
		//		{
		//			cout<<"i :"<<i<<" "<< gLocation[i].mX<<" "<<gLocation[i].mY<<endl;
		//		}

		gTotalPath = MAX_PATH;
		perm(1, sN);

		cout << "#" << i + 1 << " " << gTotalPath << endl;
	}

	return 0;

}
