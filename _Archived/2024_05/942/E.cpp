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
typedef long long i64;
//#define DEBUG

#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 200100;
#endif
const ll M = 998244353;
ll a[N];
ll pfs[20][N];
inline ll bitcnt(ll x)
{
	return __builtin_popcountll(x);
}

inline ll lowbit(ll x)
{
	return x & (-x);
}

inline ll highbit(ll x)
{
	return 1ll << (64 - __builtin_clzll(x));
}
void push(ll p, ll x)
{
	ll bcn = bitcnt(p);
	for(ll i=0; i<20; i++) if(i != bcn)
		pfs[i][p] = pfs[i][p-1];
	else
		pfs[i][p] = pfs[i][p-1] + x;
}
i64 mod_inv(i64 a, const i64& m);
i64 exgcd(i64 a, i64 b, i64& x, i64& y);
i64 mod_inv(i64 a, const i64& m)
{
	i64 x, y;
	exgcd(a, m, x, y);
	return (m + x % m) % m;
}
i64 exgcd(i64 a, i64 b, i64& x, i64& y)
{
	i64 d = a;
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
i64 gcd(i64 x, i64 y)
{
	i64 t;
	i64 a=x, b=y;
	if(a>y)
	{
		t=a; a=b; b=t;
	}
	while(a)
	{
		t=b%a;
		b=a; a=t;
	}
	return b;
}
ll jc[30], inv[30];
ll C(ll n, ll m)
{
	ll ret = 1;
	for(ll i=1; i<=m; i++)
		ret = ret * (n-i+1) % M;
	ret = ret * inv[m] % M;
	return ret;
}
void prepCombinatorics(ll n)
{
	jc[0] = 1;
	for(ll i=1; i<=n; i++)
		jc[i] = jc[i-1] * i % M;
	for(ll i=0; i<=n; i++)
		inv[i] = mod_inv(jc[i], M);
}

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    prepCombinatorics(21);
    ll z;
    cin >> z;
    while(z--){
		ll n, k;
		scanf("%lld%lld", &n, &k);
		for(ll i=0; i<n; i++)
			scanf("%lld", &a[i]);
		for(ll i=1; i<20; i++)
			pfs[i][0] = 0;
		pfs[0][0] = a[0];
		printf("%lld ", a[0]);
		for(ll i=1; i<n; i++)
		{
			ll ans = a[i];
			ll r = i+1;
			ll l = r - lowbit(r);
			for(ll j=1, mask = 1; mask<lowbit(r); j++, mask<<=1)
			{
				ll to_minus;
				ll digits = bitcnt(i) - j;
				if(l == 0)
					to_minus = pfs[digits][i-1];
				else to_minus = pfs[digits][i-1] - pfs[digits][l-1];
				to_minus %= M;
				to_minus = to_minus * C(k-1+j, j) % M;
				ans = (M + ans - to_minus) % M;
			}
			printf("%lld ", ans);
			push(i, ans);
		}
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
