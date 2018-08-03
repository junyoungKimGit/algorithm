/*
* main.cpp
*
*  Created on: 2018. 7. 18.
*      Author: Junyoung
*/

#include <iostream>

#define MAX_TEST_CASE_NUMBER (50)
#define ONCE_ARGUMENT_NUMBER (2)
#define BIAS_CHARACTER 'A'
#define TEST_NUMBER (26)
#define DEPENDENCY_NUMBER (100)

using std::cin;
using std::cout;
using std::endl;

void DepthFirstSearch(int aGraph[26][26], int aVertex, int aMaxVertaxNumber, bool aVisited[], int aStack[], int * aStackSize)
{
	aVisited[aVertex] = true;

	for (int i = 0; i < aMaxVertaxNumber; i++)
	{
		if (aGraph[aVertex][i] == 1)
		{
			if (aVisited[i] == false)
			{
				DepthFirstSearch(aGraph, i, aMaxVertaxNumber, aVisited, aStack, aStackSize);
			}
		}
	}
	*aStackSize = *aStackSize + 1;
	aStack[*aStackSize] = aVertex;

}


void topologicalSort(int aGraph[26][26], int * aIndgree, int aVertexNumber)
{
	bool sVisited[TEST_NUMBER] = { 0, };
	int sStack[TEST_NUMBER] = { 0, };
	int sStackSize = -1;

	cout << "JYJY0  " << aVertexNumber << endl;
	for (int i = aVertexNumber - 1; i > -1; i--)
	{
		cout << "JYJY1" << endl;
		if (aIndgree[i] == 0)
		{
			cout << "JYJY2" << endl;
			DepthFirstSearch(aGraph, i, aVertexNumber, sVisited, sStack, &sStackSize);
		}

	}
	cout << "StackSize : " << sStackSize << endl;

	for (int i = sStackSize; i > -1; i--)
	{
		cout << (char)(sStack[i] + BIAS_CHARACTER);
	}
	cout << endl;

	return;
}

int main()
{

	int sInputTestcaseNumber = 0;
	int sInputData[MAX_TEST_CASE_NUMBER][ONCE_ARGUMENT_NUMBER];
	char sInputCharacter[2];

	//	int test[2];
	//
	//	cin>>test[0]>>test[1];
	//	cout<<test[0]<<" "<<test[1];

	int i = 0;
	int j = 0;

	int sGraphArray[MAX_TEST_CASE_NUMBER][TEST_NUMBER][TEST_NUMBER] = { 0, };
	int sIndegreeArray[MAX_TEST_CASE_NUMBER][TEST_NUMBER] = { 0, };

	cin >> sInputTestcaseNumber;

	for (i = 0; i < sInputTestcaseNumber; i++)
	{
		cin >> sInputData[i][0] >> sInputData[i][1];
		cout << "i  :" << i << " [0] : " << sInputData[0][0] << " [1] : " << sInputData[0][1] << endl;

		if (sInputData[i][1] == 0)
		{
			continue;
		}

		for (j = 0; j < sInputData[i][1]; j++)
		{

			cin >> sInputCharacter;
			sInputCharacter[0] -= BIAS_CHARACTER;
			sInputCharacter[1] -= BIAS_CHARACTER;
			cout << "inputData sInputCharacter[0] : " << (int)sInputCharacter[0] << "    sInputCharacter[1] : " << (int)sInputCharacter[1] << endl;


			sGraphArray[i][(int)sInputCharacter[0]][(int)sInputCharacter[1]] = 1;
			sIndegreeArray[i][(int)sInputCharacter[1]] = 1;

		}
	}

	cout << "GRAPH, sInputData[0][0] : " << sInputData[0][0] << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << sGraphArray[0][i][j];
		}
		cout << endl;

	}



	for (int i = 0; i< 4; i++)
		cout << sIndegreeArray[0][i] << endl;


	for (i = 0; i < sInputTestcaseNumber; i++)
	{
		//		topologicalSort( sGraphArray[i], sIndegreeArray[i], sInputData[i][0] );
		topologicalSort(sGraphArray[i], sIndegreeArray[i], 4);
	}

	return 0;

}



