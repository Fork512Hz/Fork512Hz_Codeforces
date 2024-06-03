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
const long long N = 2000000;
#endif
#ifndef DEBUG
const long long N = 2000000;
#endif
ll base1[N >> 2];
ll base2[N >> 2];
ll top = 0;
ll gcd(ll x, ll y)
{
	if(x > y) swap(x, y);
	ll t;
	while(x)
	
	{
		t = y%x;
		y = x;
		x = t;
	}
	return y;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    #endif
    #ifdef MULTI
    ll z;
    cin >> z;
    for(ll i=2; i * ((i+1) /2) <= N; i++)
    {
    	for(ll j=i/2; j>=1; j--) if(gcd(i, j) == 1)
    	{
    		ll p = j*i;
    		ll q = (i-j) * i;
    		if(q > N) break;
    		base1[top] = p;
    		base2[top] = i;
    		top++;
		}
	}
    while(z--){
		ll n, m;
		scanf("%lld%lld", &n, &m);
		ll ans = 0;
		ll i;
		for(i=0; i<top; i++)
		{
			if(base2[i] > n || base2[i] > m || (base2[i] * base2[i] > n+m)) break;
			ll fir = base1[i];
			ll sec = base2[i] * base2[i] - base1[i];
			ans += min(n/fir, m/sec);
			if(fir != sec)
				ans += min(n/sec, m/fir);
		}
		//cerr << i << endl;
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
