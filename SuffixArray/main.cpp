#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX_N 600000

using namespace std;

char str[MAX_N];
int t, n, g[MAX_N], tg[MAX_N], SA[MAX_N], RANK[MAX_N], LCP[MAX_N];

bool cmp(int x, int y)
{
	// 현재 보고있는 단어가 같으면 t번째 기준으로 정렬
	if (g[x] == g[y])
		return g[x + t] < g[y + t];

	// 현재 보고있는 단어가 다르다면 바로 정렬
	return g[x] < g[y];
}
void getSA(const char* str)
{
	t = 1;
	n = (int)strlen(str);    //글자의 수 배정

							 //첫 글자에 의한 그룹을 정해주는 전처리
	for (int i = 0; i < n; i++)
	{
		SA[i] = i;
		g[i] = str[i] - 'a';
	}

	//1,2,4,8... 씩 단어의 길이보다 작은 경우를 탐색
	while (t <= n)
	{
		//    g[n] = -1;
		sort(SA, SA + n, cmp);    //그룹에 의한 정렬
		tg[SA[0]] = 0;    //다음 그룹을 할당하기 위하여 tempgroup의 첫번째 번호 배정

						  //다음 그룹 배정 
		for (int i = 1; i < n; i++)
		{
			//그룹이 다를 경우 다음 그룹 번호 할당
			if (cmp(SA[i - 1], SA[i]))
				tg[SA[i]] = tg[SA[i - 1]] + 1;

			//그룹이 같을 경우 같은 그룹 번호 할당
			else
				tg[SA[i]] = tg[SA[i - 1]];
		}

		//새로운 그룹 할당
		for (int i = 0; i < n; i++)
			g[i] = tg[i];

		t <<= 1; // t *= 2;
	}
}
int main()
{
	scanf("%s", &str);
	getSA(str);

	// RANK 배열에는 접미사 배열 순서가 들어간다.
	for (int i = 0; i < n; i++)
		RANK[SA[i]] = i;

	int len = 0;

	for (int i = 0; i < n; i++)
	{
		int k = RANK[i];
		if (k)
		{
			int j = SA[k - 1];

			while (str[j + len] == str[i + len])
				len++;

			LCP[k] = len;

			if (len)
				len--;
		}
	}

	printf("\n[Suffix Array]\n");

	for (int i = 0; i < n; i++)
		printf("%s\n", str + SA[i]);

	printf("\n[Suffix Array Order]\n");
	for (int i = 0; i < n; i++)
		printf("%d ", SA[i] + 1);

	printf("\n\n[LCP]\n");
	for (int i = 0; i < n; i++)
	{
		if (!i)
			printf("x ");
		else
			printf("%d ", LCP[i]);
	}

	printf("\n\n");


	return 0;
}
