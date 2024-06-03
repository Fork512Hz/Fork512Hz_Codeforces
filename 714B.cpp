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

#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif
const ll M = 1000000007;
int a[N];
ll fac[N];
ll C2(ll x)
{
	return (x * (x-1)) % M;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    fac[0] = 1;
    for(ll i=1; i<=N-100; i++)
    	fac[i] = fac[i-1] * i % M;
    int z;
    cin >> z;
    while(z--){
		ll n;
		scanf("%lld", &n);
		
		int an = 0x7fffffff;
		for(ll i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
			an &= a[i];
		}
		ll cnt = 0;
		for(ll i=0; i<n; i++)
			if((a[i] | an) == an) cnt++;
		printf("%lld\n", C2(cnt) * fac[n-2] % M);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
