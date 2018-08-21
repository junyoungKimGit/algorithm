//1218. [S/W ¹®Á¦ÇØ°á ±âº»] 4ÀÏÂ÷ - °ýÈ£ Â¦Áþ±â

#include <iostream>
#include <string>

using namespace std;

char gInput[500];
char gStack[250];
int gStackIdx;
int N;
void push(char aA)
{
	gStack[++gStackIdx] = aA;
}

char pop()
{
	return gStack[gStackIdx--];
}


bool isRightBracket(char * aInput)
{
	bool sIsRight = true;

	int sStrLen = N;

	for (int i = 0; i < sStrLen; i++)
	{
		switch (aInput[i])
		{
			case '[':
			case '{':
			case '(':
			case '<':
				push(gInput[i]);
				break;
			case ']':
			{
				if (pop() != '[')
					return false;
				break;

			case '}':
			{
				if (pop() != '{')
					return false;
				break;
			}
			case ')':
			{
				if (pop() != '(')
					return false;
				break;
			}
			case '>':
			{
				if (pop() != '<')
					return false;
				break;
			}
			default:
				cout << "ERROR" << endl;
				break;
			}
		}
	}

	return sIsRight;
}

int main()
{
	for (int t = 1; t <= 10; t++)
	{
		gStackIdx = -1;
		cin >> N;
		cin >> gInput;
		cout << "#" << t << " "<<isRightBracket(gInput)<<endl;
	}

		
	return 0;
}