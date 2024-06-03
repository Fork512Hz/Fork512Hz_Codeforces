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
const long long N = 300100;
#endif

ll mod_inv(ll a, const ll& m);
ll exgcd(ll a, ll b, ll& x, ll& y);
ll mod_inv(ll a, const ll& m)
{
	ll x, y;
	exgcd(a, m, x, y);
	return (m + x % m) % m;
}
ll exgcd(ll a, ll b, ll& x, ll& y)
{
	ll d = a;
	if (b)
	{
		d = exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else
	{
		x = 1;
		y = 0;
	}
	return d;
}

ll jc[N], inv[N], pow2[N];
ll M = 1000000007;
inline ll C(int n, int m)
{
	return jc[n] * inv[m] % M * inv[n-m] % M;
}

ll solve(ll x)
{
	ll ans = 1;
	ll pfp = 1;
	for(ll i=1; i*2 <= x; i++)
	{
		pfp = pfp * C(x + 2 - 2*i, 2) % M;
		ans = (ans + pow2[i] * pfp % M * inv[i] % M) % M; 
	}
	return ans;
}

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    jc[0] = 1;
    for(int i=1; i<N; i++)
    	jc[i] = jc[i-1] * i % M;
    for(int i=0; i<N; i++)
    	inv[i] = mod_inv(jc[i], M);
    pow2[0] = 1;
    for(int i=1; i<N; i++)
    	pow2[i] = pow2[i-1] * 2 % M;
    while(z--){
		ll n, k;
		scanf("%lld%lld", &n, &k);
		for(int i=0; i<k; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if(x == y) n--;
			else n -= 2;
		}
		printf("%lld\n", solve(n));
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
