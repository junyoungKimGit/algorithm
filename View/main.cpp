//1206.[S / W 문제해결 기본] 1일차 - View

#include <iostream>

using namespace std;

int gBuildArray[1000];

int cntH(int aIdx)
{
	int sLeftMax = gBuildArray[aIdx - 1] > gBuildArray[aIdx - 2] ? gBuildArray[aIdx - 1] : gBuildArray[aIdx - 2];
	int sRightMax = gBuildArray[aIdx + 1] > gBuildArray[aIdx + 2] ? gBuildArray[aIdx + 1] : gBuildArray[aIdx + 2];
	int sSecondMax = sLeftMax > sRightMax ? sLeftMax : sRightMax;

	return gBuildArray[aIdx] - sSecondMax;
}

int viewCnt(int aBuildCnt)
{
	int sTotalLength = 0;
		
	for (int i = 2; i < aBuildCnt-2; i++)
	{
		if (gBuildArray[i] <= gBuildArray[i - 1] ||
			gBuildArray[i] <= gBuildArray[i - 2] ||
			gBuildArray[i] <= gBuildArray[i + 1] ||
			gBuildArray[i] <= gBuildArray[i + 2])
		{
			continue;
		}
		//cout << "i : "<<i<<" cnt : "<< cntH(i) << endl;
		sTotalLength += cntH(i);


	}

	return sTotalLength;
}
int main()
{
	int sBuildNum = 0;
	int sResult = 0;
	int sBuildH;
	for (int i = 0; i < 10; i++)
	{
		memset(gBuildArray, 0, sizeof(gBuildArray));

		cin >> sBuildNum;

		for (int j = 0; j < sBuildNum; j++)
		{
			cin >> gBuildArray[j];			
		}

		sResult = viewCnt(sBuildNum);
		
		cout << "#" << i + 1 << " " << sResult << endl;
	}

	

	return 0;


}