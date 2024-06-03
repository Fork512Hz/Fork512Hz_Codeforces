#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 300100;
#endif
ll a[N], sum[N], one[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		ll n, q;
		scanf("%lld%lld", &n, &q);
		sum[0] = 0;
		one[0] = 0;
		for(ll i=1; i<=n; i++) 
		{
			scanf("%lld", &a[i]);
			sum[i] = sum[i-1] + a[i];
			one[i] = one[i-1] + (a[i] == 1? 1:0);
		}
		for(ll i=0; i<q; i++)
		{
			ll lb, rb;
			scanf("%lld%lld", &lb, &rb);
			if(rb == lb) 
			{
				printf("No\n");
				continue;
			}
			ll s = sum[rb] - sum[lb-1];
			ll o = one[rb] - one[lb-1];
			if(o + (rb-lb+1) > s)
				printf("No\n");
			else printf("Yes\n");
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
