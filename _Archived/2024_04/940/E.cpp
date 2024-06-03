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
const ll T = 1000;
#endif
#ifndef DEBUG
const long long N = 1000100;
const ll T = 100100;
#endif
const ll M = 1000000007;
ll ans[N];
ll a[T];

bool sieve[N];
vector<ll> EulerSieve(ll n)
{
	vector<ll> p = {};
	memset(sieve, 0, sizeof(sieve));
	for(ll i=2; i<=n; i++)
	{
		if(!sieve[i])
			p.push_back(i);
		for(ll t: p)
		{
			if(i * t > n) break;
			sieve[i * t] = 1;
			if(i % t == 0) break;
		}
	}
	return p;
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

    }
    #endif
	#ifndef MULTI
	ll z, n;
	n = -1;
	scanf("%lld", &z);
	for(int i=0; i<z; i++)
	{
		scanf("%lld", &a[i]);
		n = max(n, a[i]);
	}
	vector<ll> prime = EulerSieve(n);
	for(ll p: prime)
	{
		for(int i=1; i*p <= n; i++)
			if(i % p == 1) ans[i*p] += p-1;
			else ans[i*p]--;
	}
	for(int i=4; i<=n; i+=4)
		if(i % 8 == 0) ans[i] -= 2;
		else ans[i] += 2;
	for(int i=1; i<=n; i++)
		ans[i] = (ans[i] + ans[i-1]) % M;
	for(int i=1; i<=n; i++)
		ans[i] = (ans[i] + ans[i-1]) % M;
	for(int i=0; i<z; i++)
		printf("%lld\n", ans[a[i]]);
	#endif
 	return 0;
}
