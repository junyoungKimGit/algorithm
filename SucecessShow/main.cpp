//4789. 성공적인 공연 기획

#include <iostream>
#include <cstring>

using namespace std;

int T;
char gInString[1002];
int gCurrMan;
int gNeedMan;

int main()
{
	int sInSteLen = 0;
	cin >> T;


	for (int t = 1; t <= T; t++)
	{
		cin >> gInString;
		sInSteLen = strlen(gInString);


		for (int i = 0; i < sInSteLen; i++)
		{
			if (gInString[i] == '0')
				continue;
			else if (gCurrMan >= i)
			{
				gCurrMan += gInString[i] - '0';
			}
			else
			{
				gNeedMan += (i - gCurrMan);				
				gCurrMan += (i - gCurrMan) + (gInString[i] - '0');
			}
		}

		cout << "#" << t<<" " << gNeedMan << endl;

		gCurrMan = 0;
		gNeedMan = 0;

	}

	cin >> T;
	return 0;
}