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
const long long N = 500100;
#endif
pii a[N];
ll idx[N], block[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    ll z;
    cin >> z;
    while(z--){
		ll n;
		scanf("%lld", &n);
		for(ll i=1; i<=n; i++)
		{
			ll x;
			scanf("%lld", &x);
			a[i] = pii(x, i);
		}
		sort(a+1, a+n+1);
		a[0] = pii(-1, 0);
		a[n+1] = pii(-1, n+1);
		for(ll i=1; i<=n; i++)
			idx[a[i].second] = i;
		for(ll i=1; i<=n; i++) scanf("%lld", &block[i]);
		block[0] = -1;
		ll ans = 0, cnt = 0;
		ll k = n+1;
		for(ll i=1; i<=(n+1)/2; i++)
		{
			
			if(idx[block[i-1]] >= k) 
			{
				k--;
				while(a[k].first == -1) k--;
			}
			k--;
			while(a[k].first == -1) k--;
			ll tmp = (ll)i * a[k].first;
			if(ans < tmp)
			{
				ans = tmp;
				cnt = i;
			}
			
			a[idx[block[i]]].first = -1;
		}
		printf("%lld %lld\n", ans, cnt);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
