/*
* main.cpp
*
*  Created on: 2018. 7. 19.
*      Author: HY
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int countChar(int src, int find)
{
	int cnt = 0;
	while (src)
	{
		if (src % 10 == find)
		{
			cnt++;
			break;
		}
		src /= 10;
	}

	return cnt;
}

int findPrime(int prime[100000], int start, int end, int find)
{
	int result = 0;

	for (int i = 0; i < end; i++)
	{
		if (prime[i] == 0)
		{
			continue;
		}
		else
		{
			if (i > start)
			{
				result += countChar(i, find);
			}
		}
	}

	return result;
}

void makePrime(int prime[100000])
{
	for (int i = 2; i < 100000; i++) {
		prime[i] = i;
	}

	for (int i = 0; i < 100000; i++)
	{
		if (prime[i] == 0)
		{
			continue;
		}

		for (int j = i + i; j < 100000; j += i)
		{
			// i를 제외한 i의 배수들은 0으로 체크
			prime[j] = 0;
		}
	}

}

int main()
{
	int result;
	int T;
	int s, e, f;


	int prime[100000] = { 0, };
	makePrime(prime);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> f >> s >> e;
		result = findPrime(prime, s, e, f);
		cout << "#" << i + 1 << " " << result;
	}

	return 0;
}
