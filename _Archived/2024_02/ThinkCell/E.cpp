#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<functional>
#include<deque>
#include<set>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vll;
typedef long long ll;
typedef long long i64;

//#define DEBUG

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 1000100;
#endif
const ll M = 998244353;
// Modular inverse and combinatorics preprocessing
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
ll jc[N], inv[N];
ll C(ll n, ll m)
{
	if(n < 0 || m < 0 || m > n) return 0;
	return (jc[n] * inv[m] % M )* inv[n-m] % M;
}
void prepCombinatorics(ll n)
{
	jc[0] = 1;
	for(ll i=1; i<=n; i++)
		jc[i] = jc[i-1] * i % M;
	for(ll i=0; i<=n; i++)
		inv[i] = mod_inv(jc[i], M);
}

ll a[2100];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    ll z = 1;
    //cin >> z;
    while(z--){
		ll t, n;
		n = -1;
		scanf("%lld", &t);
		for(ll i=0; i<t; i++)
		{
			scanf("%lld", &a[i]);
			n = max(n, a[i]);
		}
		prepCombinatorics(n);
		for(ll y=0; y<t; y++)
		{
			n = a[y];
			for(ll i=1; 2*i+1 <= n; i++ )
			{
				ll ans = 1;
				for(ll j=1; n-2*i*j > 0; j++)
				{
					ans += (M + C(n, 2*i*j) - C(n-2*i*j+2*i-1, 2*i-1));
					ans %= M;
				}
				printf("%lld ", ans);
			}
			printf("\n");
		}
    }
 	return 0;
}
