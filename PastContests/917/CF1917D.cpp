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
const ll N = 200100;
#endif
const ll M = 998244353;
ll n, k;
ll a[N], q[N], fwt[N], p[N];
inline ll tri(ll x)
{
	return x<=0? 0: (x*(x+1)/2) % M;
}
inline int num2idxup(ll x)
{
	return (x+2) >> 1;
}
inline int num2idxdn(ll x)
{
	return (x+1) >> 1;
}
inline ll lowbit(ll x)
{
	return x & -x;
}
ll pfs(ll x)
{
	ll ret = 0;
	ll t=x;
	while(t)
	{
		ret += fwt[t];
		ret %= M;
		t -= lowbit(t);
	}
	return ret;
}
inline ll query(ll l, ll r)
{
	return pfs(r) - pfs(l-1);
}
void buildFwt()
{
  	for (ll i = 1; i <= n; ++i) {
    	fwt[i] += 1;
    	ll j = i + lowbit(i);
    	if (j <= n) fwt[j] += fwt[i];
  	}
}
void update(ll x, ll d)
{
	ll t=x;
	while(t <= n)
	{
		fwt[t] = (fwt[t]+M+d) % M;
		t += lowbit(t);
	}
}
ll mergesort(ll l, ll r)
{
	if(l == r) return 0;
	ll mid = (l+r) / 2;
	ll ret = mergesort(l, mid) + mergesort(mid+1, r);
	ll i = l;
	ll j = mid+1;
	ll k = l;
	while(i <= mid && j <= r)
	{
		if(q[i] < q[j])
		{
			p[k] = q[i];
			i++; k++;
		}
		else
		{
			ret += (mid+1 - i);
			p[k] = q[j];
			j++; k++;
		}
	}
	if(i > mid) 
		for(; j<=r; j++, k++) p[k] = q[j];
	else
		for(; i<=mid; i++, k++)	p[k] = q[i];
	for(ll i=l; i<=r; i++) q[i] = p[i];
	return ret;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    ll z;
    cin >> z;
    while(z--){
		scanf("%d%d", &n, &k);
		for(ll i=1; i<=n; i++)
		{
			scanf("%d", &a[i]);
		}
		for(ll i=0; i<k; i++)
		{
			scanf("%d", &q[i]);
		}
		ll ans = mergesort(0, k-1) * n % M;
		buildFwt();
		for(ll i=1; i<=n; i++)
		{
			update(num2idxdn(a[i]), -1);
			for(ll j=0; 1; j++)
			{
				ll lb, rb;
				lb = num2idxup( a[i] << j);
				rb = num2idxdn( a[i] << (j+1));
				if(lb > n) break;
				if(rb > n) rb = n;
				ans = (ans + query(lb,rb) * tri(k-j-1)) % M;
			}
			for(ll j=0; 1; j++)
			{
				ll lb, rb;
				rb = num2idxdn(a[i] >> j);
				lb = num2idxup(( (a[i]-1) >> (j+1) )+ 1);
				//printf("%d %d\n", lb, rb);
				ans = (ans+ query(lb,rb) * ((k*k) - tri(k-j-1)) ) % M;
				if(lb == 1) break;
			}
		}
		
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
