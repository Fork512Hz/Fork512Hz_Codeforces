#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long ll;
//#define DEBUG

//#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){

    }
    #endif
	#ifndef MULTI
	ll a, b;
	scanf("%lld + %lld", &a, &b);
	printf("%lld", a+b + a*a + b*b + a-b + abs(a) * 2 * b - a*b - 2);
	#endif
 	return 0;
}
