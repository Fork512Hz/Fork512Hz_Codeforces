#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 100100;
#endif
ll n1m0, n0m1;
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    ll z;
    cin >> z;
    while(z--){
		long long n, m;
		scanf("%lld%lld", &n, &m);
		ll xx = n^m;
		if(xx < n)
		{
			printf("1\n%lld %lld\n", n, m);
		}
		else 
		{
			n1m0 = n & (~m);
			n0m1 = m & (~n);
			long long t=n;
			vector<long long> inc, dec, ori;
			inc = {}; dec = {};
			ll i=0;
			while(n1m0)
			{
				if(n1m0 & 1) dec.push_back(i);
				i++;
				n1m0 >>= 1;
			}
			i=0;
			while(n0m1)
			{
				if(n0m1 & 1) inc.push_back(i);
				i++;
				n0m1 >>= 1;
			}
			i=0;
			while(t)
			{
				if(t&1) ori.push_back(i);
				t >>= 1;
				i++;
			}
			ll osize = ori.size();
			if(osize <= 1 || inc.back() > ori[osize-2])
				printf("-1\n");
			else 
			{
				long long target = 0;
				for(long long j: inc) 
					target += 1ll<<j;
				target += 1ll<<ori[osize-2];
				target = n^target;
				printf("2\n%lld %lld %lld\n", n, target, m);
			}
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
