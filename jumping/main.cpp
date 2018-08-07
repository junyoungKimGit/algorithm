//3503. �ʺ��ڸ� ���� ������ ��ġ�ϱ�

#include <iostream>

using namespace std;

int T;
int N;
int JMP[10000];
int REJMP[10000];
int MAXDIFF;

void swap(int * aA, int * aB)
{
	int sTemp = *aA;
	*aA = *aB;
	*aB = sTemp;
}

int diff(int aA)
{
	int sTemp = REJMP[aA] - REJMP[aA + 1];	
	return sTemp > 0 ? sTemp : -sTemp;
}

//���̰� ���
void finalPhase()
{
	for (int i = 0; i < N-1; i++)
	{
		if (MAXDIFF < diff(i))
			MAXDIFF = diff(i);
	}

	int sLast = REJMP[N-1] - REJMP[0];
	if (sLast < 0)
		sLast *= -1;	

	if (MAXDIFF < sLast)
		MAXDIFF = sLast;
}

//��迭�ϱ�
void secondPhase()
{

	int sMid = N / 2;
	int sOdd = -1;
	int sEven = 0;;

	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
		{
			REJMP[sMid+sEven] = JMP[i];
			sEven++;
		}
		else
		{
			REJMP[sMid + sOdd] = JMP[i];
			sOdd--;
		}
	}
}

//�ټ����
//quickSort
void firstPhase(int aStart, int aEnd)
{

	cout << "firstPh : start : " << aStart << " aEnd : " << aEnd << endl;
	if(aStart < aEnd)
	{
		int sPivot = JMP[aStart];
		int sL = aStart + 1;
		int	sR = aEnd;

		while (sL < sR)
		{
			while (sPivot > JMP[sL])
			{
				sL++;
			}
			while (sPivot < JMP[sR])
			{
				sR--;
			}

			if (sL <= sR)
				swap(JMP[sL], JMP[sR]);
			else
				break;
		}

		swap(JMP[aStart], JMP[sR]);
		firstPhase(aStart, sR - 1);
		firstPhase(sR + 1, aEnd);

	}	
}

void QuickSort(int arr[], int left, int right) {
	int L = left, R = right;
	int temp;
	int pivot = arr[(left + right) / 2]; //�Ǻ� ��ġ(�߾�)�� ���� ����.

	//printf("L : %d / pivot : %d / R : %d\n", L, (left + right) / 2, R); //������ Ȯ�� �κ�.

																		//�Ʒ��� while���� ���Ͽ� pivot �������� ��, �� ũ�� ���� �� ����. = Partition
	while (L <= R) {

		//pivot�� �߰� ���̰�, �� ��� arr[L], arr[R]�� pivot�� ���ϴ� �߰� ������ �Ѿ�� ����� �� �� ����.
		while (arr[L] < pivot) //left���� �����ϸ� pivot �̻��� ���� ã��.
			L++;
		while (arr[R] > pivot) //right���� �����ϸ� pivot ���� ���� ã��.
			R--;
		//L, R ��� �ִ� pivot ��ġ���� �̵�.

		if (L <= R) { //���� L�� R���ϸ�. (���� : L>R �κ��� �̹� ������ �� ������).
			if (L != R) { //���� ���� ��츸.
				temp = arr[L];
				arr[L] = arr[R];
				arr[R] = temp;
			} //L�� R�� ���ٸ� ��ȯ(SWAP)�� �ʿ� ���� �� ĭ�� ���ุ ���ָ� ��.
			L++; R--; //�׸��� L,R �� ĭ �� ����.


			//for (int i = 0; i < 10; i++) { //������ Ȯ�� �κ�.
			//	printf("%d ", arr[i]);
			//}
			//printf("\n");
		}
	}
	//printf("\n");

	//���� Ȯ���Ͽ� ����Լ���.
	//printf("QuickSort ��� ȣ�� Ȯ��(���� �� ȣ��)\n1.left : %d < R : %d \n2.right : %d > L : %d\n\n", left, R, right, L); //������ Ȯ�� �κ�.
	if (left < R)
		QuickSort(arr, left, R);
	if (L < right)
		QuickSort(arr, L, right);
}



int main()
{
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> N;
		
		for (int i = 0; i < N; i++)
		{
			cin >> JMP[i];
		}
		MAXDIFF = 0;
		//for (int i = 0; i < N; i++)
		//{
		//	cout << JMP[i] << " ";
		//}
		//cout << endl;

		//firstPhase(0, N-1);
		QuickSort(JMP, 0, N - 1);

		//for (int i = 0; i < N; i++)
		//{
		//	cout << JMP[i] << " ";
		//}
		//cout << endl;

		secondPhase();

		//for (int i = 0; i < N; i++)
		//{
		//	cout << REJMP[i] << " ";
		//}
		//cout << endl;

		finalPhase();

		cout << "#"<<t<< " "<<MAXDIFF << endl;

	
	}
	cin >> N;

	return 0;
}