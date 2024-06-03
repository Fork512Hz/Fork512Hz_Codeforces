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
const long long N = 1000010;
#endif
const ll M = 998244353;
ll jc[N], inv[N];

ll ksm(ll x, ll ex)
{
	if(ex == 0) return 1ll;
	ll t = ksm(x, ex >> 1);
	t = t*t % M;
	if(ex & 1ll) t = t*x % M;
	return t;
}

inline ll C(ll n, ll m)
{
	return jc[n] * inv[m] % M * inv[n-m] % M;
}

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    jc[0] = 1;
    for(int i=1; i<=N; i++) jc[i] = jc[i-1] * i % M;
    for(int i=0; i<=N; i++) inv[i] = ksm(jc[i], M-2);
    int z;
    cin >> z;
    while(z--){
		int l, n;
		scanf("%d%d", &l, &n);
		ll ans = 0;
		for(int i=0; i<=(l-2*n) / 2; i++)
		{
			ll tmp = C(i+n-1, i) * C(l-n-2*i, n) % M;
			ans = (ans + tmp) % M;
		}
		
		printf("%lld\n", 2 * (C(l, 2*n) + M - ans) % M);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
