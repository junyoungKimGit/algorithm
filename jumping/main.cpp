//3503. 초보자를 위한 점프대 배치하기

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

//차이값 계산
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

//재배열하기
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

//줄세우기
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
	int pivot = arr[(left + right) / 2]; //피봇 위치(중앙)의 값을 받음.

	//printf("L : %d / pivot : %d / R : %d\n", L, (left + right) / 2, R); //데이터 확인 부분.

																		//아래의 while문을 통하여 pivot 기준으로 좌, 우 크고 작은 값 나열. = Partition
	while (L <= R) {

		//pivot이 중간 값이고, 비교 대상 arr[L], arr[R]은 pivot과 비교하니 중간 지점을 넘어가면 종료로 볼 수 있음.
		while (arr[L] < pivot) //left부터 증가하며 pivot 이상의 값을 찾음.
			L++;
		while (arr[R] > pivot) //right부터 감소하며 pivot 이하 값을 찾음.
			R--;
		//L, R 모두 최대 pivot 위치까지 이동.

		if (L <= R) { //현재 L이 R이하면. (이유 : L>R 부분은 이미 정리가 된 상태임).
			if (L != R) { //같지 않은 경우만.
				temp = arr[L];
				arr[L] = arr[R];
				arr[R] = temp;
			} //L과 R이 같다면 교환(SWAP)은 필요 없고 한 칸씩 진행만 해주면 됨.
			L++; R--; //그리고 L,R 한 칸 더 진행.


			//for (int i = 0; i < 10; i++) { //데이터 확인 부분.
			//	printf("%d ", arr[i]);
			//}
			//printf("\n");
		}
	}
	//printf("\n");

	//조건 확인하여 재귀함수로.
	//printf("QuickSort 재귀 호출 확인(만족 시 호출)\n1.left : %d < R : %d \n2.right : %d > L : %d\n\n", left, R, right, L); //데이터 확인 부분.
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