#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<set>
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
const long long N = 200100;
#endif
const ll INF = 0x3f3f3f3f3f3f3f3f;
pii a[N];
ll costk[N];
multiset<ll> bestk;
bool cmp(pii x, pii y)
{
	if(x.first != y.first) return x.first < y.first;
	return x.second < y.second;
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
    while(z--){
		ll n, k;
		scanf("%lld%lld", &n, &k);
		for(int i=1; i<=n; i++) scanf("%lld", &a[i].second);
		for(int i=1; i<=n; i++) scanf("%lld", &a[i].first);
		sort(a+1, a+n+1, cmp);
		memset(costk, 0x3f, sizeof(ll) * (n+5));
		ll sumk = 0;
		bestk.clear();
		for(ll i=n; i>n-k; i--)
		{
			costk[i] = INF;	
			sumk += a[i].second;
			bestk.insert(a[i].second);
		}	
		ll tmp;
		for(ll i=n-k; i>0; i--)
		{
			costk[i] = sumk;
			sumk += a[i].second;
			bestk.insert(a[i].second);
			auto tail = bestk.end();
			tail--;
			tmp = *tail;
			sumk -= tmp;
			bestk.erase(tail);
		}
		costk[0] = sumk;
		ll sumprofit = 0;
		ll ans = 0;
		for(ll i=1; i<=n-k; i++)
		{
			sumprofit += max(0ll, a[i].first - a[i].second);
			ans = max(ans, sumprofit - costk[i]);
		}
		printf("%lld\n", ans);
		
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}