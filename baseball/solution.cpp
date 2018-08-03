/*
* soulution.cpp
*
*  Created on: 2018. 7. 18.
*      Author: HY
*/

//#include <iostream>

#define N 4
typedef struct {
	int strike;
	int ball;
} Result;

extern Result query(int guess[]);

//using std::cin;
//using std::cout;
//using std::endl;

class Node
{
public:
	int mNum[4];

	Node * mPrev;
	Node * mNext;
};

class List
{


public:
	List();
	~List();


	void init();
	void fin();

	void insert(int aNum[4]);
	void del(Node * aNode);

public:
	Node * mHead;
	Node * mTail;

};
List::List()
{
	mHead = new Node;
	mHead->mPrev = nullptr;
	mHead->mNext = nullptr;

	mTail = new Node;
	mTail->mPrev = nullptr;
	mTail->mNext = nullptr;

	mHead->mNext = mTail;
	mTail->mPrev = mHead;

}
List::~List()
{

	delete mHead;
	delete mTail;
}

void List::insert(int aNum[4])
{
	Node * sNewNode = new Node;
	for (int i = 0; i <4; i++)
		sNewNode->mNum[i] = aNum[i];
	sNewNode->mNext = nullptr;
	sNewNode->mPrev = nullptr;

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

void List::del(Node * aNode)
{
	aNode->mPrev->mNext = aNode->mNext;
	aNode->mNext->mPrev = aNode->mPrev;

	//	cout<<"delete : "<<aNode->mNum[3]<<aNode->mNum[2]<<aNode->mNum[1]<<aNode->mNum[0]<<endl;

	delete aNode;

	//	cout<<"delete Success"<<endl;
}

void List::init()
{
	int sNum[4];
	int sCount = 0;

	for (int a = 0; a < 10; a++)
	{
		for (int b = 0; b < 10; b++)
		{
			if (a != b)
			{
				for (int c = 0; c < 10; c++)
				{
					if (c != a && c != b)
					{
						for (int d = 0; d < 10; d++)
						{
							if (d != a && d != b && d != c)
							{
								sNum[0] = a;
								sNum[1] = b;
								sNum[2] = c;
								sNum[3] = d;

								insert(sNum);

								sCount++;
							}
						}
					}
				}
			}
		}
	}

	//	cout<<"COUNT : "<<sCount<<endl;;
}

void List::fin()
{
	Node * sTemp = mHead->mNext;
	Node * sNext;
	//	cout<<"??";
	while (sTemp != mTail)
	{
		sNext = sTemp->mNext;
		del(sTemp);
		sTemp = sNext;
		//		cout<<"!!!!";
	}

}

//void printList(List * aList)
//{
//	Node * sTemp;
//	sTemp = aList->mHead->mNext;
//	int sCnt = 0;
//	while(sTemp != nullptr)
//	{
//		cout<<"Cnt : "<<sCnt<<"  Node : "<<sTemp->mNum[3]<<sTemp->mNum[2]<<sTemp->mNum[1]<<sTemp->mNum[0]<<endl;
//
//		sTemp = sTemp->mNext;
//		sCnt++;
//	}
//}

void doUserImplementation(int guess[])
{
	List sList;
	sList.init();

	//	printList(&sList);

	Node *sNode = sList.mHead->mNext;
	Node *sNext = sNode->mNext;
	Result sResult;

	int sDelCnt = 0;
	int sWhileCnt = 0;

	while (sWhileCnt < 10000)
	{
		sWhileCnt++;
		//cout<<"While St Cnt : "<< sWhileCnt<<endl;
		sResult = query(sNode->mNum);

		if (sResult.strike == 4)
		{
			//			cout<<"RIGHT"<<endl;
			for (int i = 0; i < 4; i++)
				guess[i] = sNode->mNum[i];
			break;
		}

		int sComp[4];
		for (int i = 0; i < 4; i++)
			sComp[i] = sNode->mNum[i];

		int sStrikeCnt;
		int sBallCnt;
		sNext = sNode;
		while (sNode->mNext != nullptr)
		{
			sNext = sNode->mNext;
			sStrikeCnt = 0;
			sBallCnt = 0;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (sNode->mNum[i] == sComp[j])
					{
						if (i == j)
						{
							sStrikeCnt++;
						}
						else
						{
							sBallCnt++;
						}
						break;
					}
				}
			}

			if (sResult.strike != sStrikeCnt || sResult.ball != sBallCnt)
			{
				sList.del(sNode);
				sDelCnt++;
				//				cout<<"delete cnt : "<<sDelCnt<<endl;
			}

			sNode = sNext;
		}

		sNode = sList.mHead->mNext;
	}

	//	cout<<"JYJY"<<endl;
	sList.fin();
	//	cout<<"JYJY1"<<endl;
	return;
}




