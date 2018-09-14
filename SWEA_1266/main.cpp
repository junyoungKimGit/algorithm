//1266. [S/W 문제해결 응용] 9일차 - 소수 완제품 확률

#include <iostream>

using namespace std;

#define MAX_N (19)

long long FACTORIAL[MAX_N];
int PRIME[7] = { 2, 3, 5, 7, 11, 13, 17 };

void initFact(){
	
	FACTORIAL[0] = 0;
	FACTORIAL[1] = 1;
	for (int i = 2; i <= MAX_N; i++)
	{
		FACTORIAL[i] = FACTORIAL[i - 1] * i;
	}
    
}
int composition(int n, int r){
    if(r == 0 || r==n)
        return 1;
    long long sRes = FACTORIAL[n]/FACTORIAL[r];
	sRes /= FACTORIAL[n-r];
    return sRes;
}

    
double cal(int i_p){
    if(i_p == 0){
        return 0;
    }
    double t_p = i_p;
    double p = t_p/100;

    double P[MAX_N];
    double Q[MAX_N];
    P[1] = p;
    Q[1] = 1-p;
    for(int i = 2; i<MAX_N; i++)
	{
        P[i] = P[i-1]*p;
        Q[i] = Q[i-1]*(1-p);
    }
    double sRes = 0;
    for(int i = 0; i<7; i++)
	{
		sRes += composition(18, PRIME[i])*P[PRIME[i]]*Q[18-PRIME[i]];
    }
    return sRes;
}

int T;
int main(){
	initFact();

	cin >> T;

    int aPA, aPB;
	double sResA, sResB;
	double sTotalRes;

    for(int tc = 1; tc<=T; ++tc)
	{
		cin >> aPA >> aPB;

		sResA = cal(aPA);
		sResB = cal(aPB);
		sTotalRes = sResA + sResB - sResA * sResB; //동시에 소수가 나올 확률을 제외해야 함
		
		
		cout << "#" << tc << " "; 
		
		cout << fixed;
		cout.precision(6);
		cout<< sTotalRes << endl;
		cout.unsetf(ios::fixed);
    }
    return 0;
}
