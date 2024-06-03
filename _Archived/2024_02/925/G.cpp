#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI
const ll M = 998244353;
#ifdef DEBUG
const ll N = 2001000;
#endif
#ifndef DEBUG
const ll N = 2001000;
#endif
ll jc[N], inv[N];
ll po(ll b, ll e)
{
	if(e == 0) return 1;
	if(e == 1) return b;
	ll ans = po(b, e>>1);
	ans = ans*ans % M;
	if(e%2) ans = ans*b % M;
	return ans;
}

ll cb(ll n, ll m)
{
	if(n < 0 || m < 0 || m > n) return 0;
	return (jc[n] * inv[m] % M )* inv[n-m] % M;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    jc[0] = 1;
    for(int i=1; i<2000010; i++)
    	jc[i] = jc[i-1] * i % M;
    for(int i=0; i<2000010; i++)
    	inv[i] = po(jc[i], M-2);
    int z;
    cin >> z;
    while(z--){
		ll a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if(!a && !b)
		{
			if(!c || !d) printf("1\n");
			else printf("0\n");
			continue;
		}
		switch(a-b)
		{
			case 1:
				printf("%lld\n", cb(c+a-1, c) * cb(d+a-1, d) % M); break;
			case -1:
				printf("%lld\n", cb(c+b-1, c) * cb(d+b-1, d) % M); break;
			case 0:
				printf("%lld\n", (cb(c+a, c) * cb(d+a-1, d) +
								  cb(c+a-1, c) * cb(d+a, d)) % M); break;
			default:
				printf("0\n");
				break;
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
