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
const long long N = 200100;
#endif
const ll M = 1000000007;
ll pfs[N], sfs[N];
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
ll C(ll x, ll y)
{
	ll nume, denom;
	nume = 1;
	denom = 1;
	for(int i=1; i<=y; i++)
	{
		nume = (nume * (x+1-i)) % M;
		denom = denom * i % M;
	}
	return nume * mod_inv(denom, M) % M;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n, lp, ls;
		scanf("%d%d%d", &n, &lp, &ls);
		for(int i=1; i<=lp; i++) scanf("%lld", &pfs[i]);
		for(int i=1; i<=ls; i++) scanf("%lld", &sfs[i]);
		if(pfs[lp] != sfs[1] || pfs[1] != 1 || sfs[ls] != n)
		{
			printf("0\n");
			continue;
		}
		ll ans = C(n-1, sfs[1]-1);
		for(int i=2; i<=lp; i++)
			for(ll j=pfs[i-1]; j<pfs[i]-1; j++)
				ans = (ans*j) % M;
		for(int i=ls-1; i>=1; i--)
			for(ll j=n+1-sfs[i+1]; j<n-sfs[i]; j++)
				ans = (ans*j) % M;
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
