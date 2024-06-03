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
inline ll lowbit(ll x)
{
	return x & -x;
}
ll a[N], fwtsum[N<<1], fwtone[N<<1];
ll pfssum(ll x)
{
	ll ret = 0;
	ll t = x;
	while(t)
	{
		ret += fwtsum[t];
		t -= lowbit(t);
	}
	return ret;
}
ll pfsone(ll x)
{
	ll ret = 0;
	ll t =x;
	while(t)
	{
		ret+=fwtone[t];
		t -= lowbit(t);
	}
	return ret;
}
inline ll querysum(ll l, ll r)
{
	return pfssum(r) - pfssum(l-1);
}
inline ll queryone(ll l, ll r)
{
	return pfsone(r) - pfsone(l-1);
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
		ll n, q;
		scanf("%lld%lld", &n, &q);
		memset(fwtsum, 0, sizeof(ll) * (n+5));
		memset(fwtone, 0, sizeof(ll) * (n+5));
		for(ll i=1; i<=n; i++) 
		{
			scanf("%lld", &a[i]);
			fwtsum[i] += a[i];
			fwtsum[i + lowbit(i)] += fwtsum[i];
			if(a[i] == 1) fwtone[i] ++;
			fwtone[i+lowbit(i)] += fwtone[i];
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
			ll sum = querysum(lb, rb);
			ll one = queryone(lb, rb);
			if(one + (rb-lb+1) > sum)
				printf("No\n");
			else printf("Yes\n");
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
