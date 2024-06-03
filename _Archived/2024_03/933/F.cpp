#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<set>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef long long ll;
//#define DEBUG

#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll n, m, k, x, y, diff1, diff2, l, r, ans;
ll a[N];
set<ll> b;
bool check(ll t)
{
	ans = min(ans, max(diff2, max(r - t, t - l)));
	if(ans == diff2) 
	{
		printf("%lld\n", diff2);
		return true;
	}
	return false;
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
		scanf("%lld%lld%lld", &n, &m, &k);
		diff1 = -1; 
		diff2 = -1;
		
		scanf("%lld", &x);
		for(int i=1; i<n; i++)
		{
			scanf("%lld", &y);
			if(y-x >= diff1)
			{
				l = x;
				r = y;
				diff2 = diff1;
				diff1 = y-x;
			}
			else if(y-x >= diff2)
				diff2 = y-x;
			x = y;
		}
		b.clear();
		for(int i=0; i<m; i++) scanf("%lld", &a[i]);
		for(int i=0; i<k; i++){
			scanf("%lld", &x);
			b.insert(x);
		}
		if(diff1 == diff2)
		{
			printf("%lld\n", diff1);
			continue;
		}
		ans = diff1;
		for(int i=0; i<m; i++)
		{
			auto it = b.lower_bound((l+r)/2 - a[i]);
			if(it != b.end()) 
				if(check(a[i] + *it) ) goto fin;;
			if(it != b.begin())
			{
				it--;
				if( check(a[i] + *it)) goto fin;;
			}
		}
		printf("%lld\n", ans);
		
		fin:;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
