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

#ifdef DEBUG
const long long N = 3010;
#endif
#ifndef DEBUG
const long long N = 3010;
#endif
ll jc[N], inv[N];
ll M = 1000000007;

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
ll gcd(ll x, ll y)
{
	ll t;
	ll a=x, b=y;
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

inline ll C(ll p, ll q)
{
	if(q > p || q < 0) return 0;
	return jc[p] * inv[q] % M * inv[p-q] % M;
}

ll TODO(ll p, ll q, ll limit)
{
	return C(p-limit+1, q-limit+1);
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    jc[0] = 1;
    for(int i=1; i<=3000; i++) jc[i] = jc[i-1] * i % M;
    for(int i=0; i<=3000; i++) inv[i] = mod_inv(jc[i], M);
    int n, c, k;
    ll ans = 0;
    scanf("%d%d%d", &n, &c, &k);
    
    for(int i=c+k; i>=c; i--)
    {
    	for(int j=0; j<=n+k-i; j++)
    	ans = (ans + C(n-i-2, j) - TODO(n-i-2, j, i)) % M;
	}
	printf("%lld", ans);
 	return 0;
}
