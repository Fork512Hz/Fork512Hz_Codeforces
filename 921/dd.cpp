#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
typedef long long ll;
#define DEBUG
#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = //TODO
#endif
const ll M = 999999893;
using namespace std;

ll f(ll x)
{
	if(x<=30) return (1<<x) % M;
	ll ans;
	if(x & 1ll) ans = 2;
	else ans = 1;
	ll tmp = f(x >> 1);
	return (tmp*tmp%M) * ans % M;
}
ll mod_inv(ll a, const ll& m);
ll exgcd(ll a, ll b, ll& x, ll& y);
ll mod_inv(ll a, const ll& m)
{
	ll x, y;
	exgcd(a, m, x, y);
	return (m + x % m) % m;
}

// 扩展欧几里德算法
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
int main()
{
    #ifdef DEBUG
    //freopen("1.txt", "r", stdin);
    #endif
	int z;
	cin >> z;
	while(z--)
	{
		ll n;
		scanf("%lld", &n);
		ll ansp, ansq;
		ll p2 = f(n>>1);
		if(n & 1ll)
		{
			ansp = (p2-1) % M;
			ansq = ((p2+1) * (p2+1) - 2) % M;
		}
		else
		{
			ansp = 2*(p2-1) % M;
			ansq = (2-(p2-2) * (p2-2) )%M;
			if(ansq<0) ansq += 	M;
		}
		printf("%lld\n", ansp * mod_inv(ansq, M) % M);
	}
 	return 0;
}
