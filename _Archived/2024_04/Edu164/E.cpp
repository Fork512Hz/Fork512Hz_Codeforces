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
#ifndef DEBUG
const long long N = 200100;
#endif
pii a[N];
ll ans[N];
bool lt[N], rt[N];
int main()
{
	ll n;
	scanf("%lld", &n);
	ll m = -1;
	for(ll i=0; i<n; i++) 
	{
		ll x;
		scanf("%lld", &x);
		a[i] = pii(x, i);
		m = max(m, x);
	}
	sort(a, a+n);
	ll t = 0;
	lt[0] = 1;
	rt[n-1] = 1;
	ll segs = 1;
	for(ll i=0; i<n; i++)
	{
		for(; t<a[i].first; t++) ans[t] = segs;
		ll p = a[i].second;
		ll c = lt[p] * 2 + rt[p];
		switch(c)
		{
			case 3: segs--; break;
			case 0: 
				segs++;
				lt[p+1] = 1;
				rt[p-1] = 1;
				break;
			case 2:
				lt[p+1] = 1;
				break;
			case 1:
				rt[p-1] = 1;
				break;
		}
	}
	for(ll i=1; i<=m; i++)
	{
		ll result = 0;
		for(ll j=0; j<m; j+=i) result += ans[j];
		printf("%lld ", result);
	}
 	return 0;
}
