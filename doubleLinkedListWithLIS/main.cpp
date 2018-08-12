//4587. 흥민이의 리스트 되돌리기
#include <iostream>

using namespace std;



int sTestNum = 0;
int sListNum = 0;
int sFuncNum = 0;

#if 0 
void LIS(int aArr[])
{
	int arr[100];
	int dp[100];

	int max;

	dp[0] = 1;
	for (int i = 0; i < 100; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[j]< arr[i] && dp[j] + 1 < dp[i])
			{
				dp[i] = dp[j] + 1;

			}
		}

		if (max < dp[i])
		{
			max = dp[i];
		}
	}
}

int LISAlgorithm(List aList, int aNodecnt)
{
	int *sArr = new int[aNodecnt];

	for (int i = 0; i < aNodecnt; i++)
	{
		sArr[i] = i;
	}

	int sMax = 0;

	int * sDP = new int[aNodecnt];
	sDP[0] = 1;

	for (int i = 1; i < aNodecnt; i++)
	{
		sDP[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (sArr[j] < sArr[i] && sDP[j] + 1 > sDP[i])
			{
				sDP[i] = sDP[j] + 1;
			}

		}
		if (sMax < sDP[i])
			sMax = sDP[i];
	}

	return sMax;

}
#endif

class Node
{
public:
	int mData;
	Node * mPrev;
	Node * mNext;
};

class List
{
public:
	Node * mHead;
	Node * mTail;

	int mCurrNodeCnt;

	List();
	~List();

	void init(int aNodeCnt);
	void fin();

	void insert(int aData);
	void moveFunc(char aCase, int aA, int aB);
	void printList();

	Node * find(int aData);

	int findSolution();

};

List::List()
{
	mHead = new Node;
	mTail = new Node;

	mHead->mPrev = nullptr;
	mHead->mNext = nullptr;

	mTail->mPrev = nullptr;
	mTail->mNext = nullptr;

	mCurrNodeCnt = 0;
}

List::~List()
{
	delete mHead;
	delete mTail;
}

void List::insert(int aData)
{
	Node * sNewNode = new Node;

	sNewNode->mData = aData;

	if (mHead->mNext == nullptr)
	{
		mHead->mNext = sNewNode;
		sNewNode->mPrev = mHead;
		sNewNode->mNext = mTail;
		mTail->mPrev = sNewNode;
	}
	else
	{
		mTail->mPrev->mNext = sNewNode;
		sNewNode->mPrev = mTail->mPrev;
		sNewNode->mNext = mTail;
		mTail->mPrev = sNewNode;
	}
}

void List::init(int aNodeCnt)
{
	int sData = mCurrNodeCnt + 1;

	if (aNodeCnt > mCurrNodeCnt)
	{
		for (int i = mCurrNodeCnt; i < aNodeCnt; i++)
		{
			insert(sData);
			sData++;
		}

		mCurrNodeCnt = aNodeCnt;
	}
	else
	{
	}


	//	cout<<"init("<<aNodeCnt<<")"<<endl;
}

void List::printList()
{
	Node * sTemp = mHead->mNext;
	cout << "PRINT LIST" << endl;
	while (sTemp != mTail || sTemp->mNext != nullptr)
	{
		cout << sTemp->mData << " ";
		sTemp = sTemp->mNext;
	}
	cout << endl;
}

void List::fin()
{
	Node * sCurrNode = mHead->mNext;
	Node * sNextNode;
	while (sCurrNode != mTail)
	{
		sNextNode = sCurrNode->mNext;

		sCurrNode->mPrev->mNext = sCurrNode->mNext;
		sCurrNode->mNext->mPrev = sCurrNode->mPrev;

		delete sCurrNode;

		sCurrNode = sNextNode;

	}

	//	cout<<"fin"<<endl;
}

Node * List::find(int aData)
{
	Node * sFindNode = mHead->mNext;

	while (sFindNode->mNext != mTail)
	{
		if (sFindNode->mData == aData)
		{
			break;
		}
		else
		{
			sFindNode = sFindNode->mNext;
		}
	}

	return sFindNode;
}

void List::moveFunc(char aCase, int aA, int aB)
{

	Node * sANode;
	Node * sBNode;

	sANode = find(aA);
	sBNode = find(aB);

	if (aCase == 'A')
	{
		if (sANode->mNext == sBNode)
			return;

		//remove ANode
		sANode->mPrev->mNext = sANode->mNext;
		sANode->mNext->mPrev = sANode->mPrev;

		//
		sANode->mPrev = sBNode->mPrev;
		sANode->mNext = sBNode;
		sBNode->mPrev->mNext = sANode;
		sBNode->mPrev = sANode;


	}
	else
	{
		if (sBNode->mNext == sANode)
			return;

		//remove ANode
		sANode->mPrev->mNext = sANode->mNext;
		sANode->mNext->mPrev = sANode->mPrev;

		//insert ANode into BNode
		sANode->mPrev = sBNode;
		sANode->mNext = sBNode->mNext;
		sBNode->mNext->mPrev = sANode;
		sBNode->mNext = sANode;

	}
}

int List::findSolution()
{
	int sFuncCnt = 0;
	int sData = 1;

	Node * sTempNode = mHead->mNext;

	Node * sFindNode;
	Node * sFindNextNode;

	while (sTempNode != mTail && sData != sListNum && sData < sListNum)
	{
		if (sData == sTempNode->mData)
		{
			sData++;
			sTempNode = sTempNode->mNext;
		}
		else
		{
			//find Data
			sFindNode = find(sData);
			sFindNextNode = find(sData + 1);

			this->printList();
			cout << "MOVE data: " <<sData<< endl;
			moveFunc('A', sFindNode->mData, sFindNextNode->mData);
			this->printList();
			
			sTempNode = sFindNode->mNext;
			sFuncCnt++;
			sData++;			
		}
	}

	return sFuncCnt;
}


int main()
{
	
	List sList;
	char sCase;
	int sA, sB;
	int sResult;

	cin >> sTestNum;

	for (int i = 0; i < sTestNum; i++)
	{
		cin >> sListNum >> sFuncNum;

		sList.init(sListNum);

		for (int j = 0; j < sFuncNum; j++)
		{
			cin >> sCase >> sA >> sB;
			sList.moveFunc(sCase, sA, sB);
		}

		sResult = sList.findSolution();		
		cout << "#" << i + 1 << " " << sResult << endl;
		
	}

	//cin >> sTestNum;

	return 0;
}

