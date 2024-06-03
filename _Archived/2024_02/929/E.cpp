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
const ll N = 100100;
#endif
ll a[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		ll n;
		scanf("%lld", &n);
		a[0] = 0;
		for(ll i=1; i<=n; i++)
		{
			scanf("%lld", &a[i]);
			a[i] += a[i-1];
		}
		a[n+1] = 0x7fffffffffffffff;
		ll q;
		scanf("%lld", &q);
		for(ll v=0; v<q; v++)
		{
			ll l, u;
			scanf("%lld%lld", &l, &u);
			ll target = a[l-1] + u;
			ll start = l;
			ll r = n+1;
			ll mid;
			ll x, y;
			while(l < r)
			{
				mid = (l+r) / 2;
				if(a[mid] > target) r = mid;
				else if(a[mid] < target) l = mid+1;
				else 
				{
					printf("%lld ", mid);
					goto fin;
				}
			}
			if(l == start) 
			{
				printf("%lld ", l) ;
				goto fin;
			}
			if(l == n+1)
			{
				printf("%lld ", n);
				goto fin;
			}
			x = a[l-1] - a[start-1];
			y = a[l] - a[start-1];
			if(u-x <= y-u-1) printf("%lld ", l-1);
			else printf("%lld ", l);
			fin:;
		}
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
