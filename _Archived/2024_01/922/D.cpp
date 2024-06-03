#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<deque>
#include<cstring>
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
int n;
ll a[N], pfs[N];
ll dp[N];
deque<ll> monoque;
bool check(ll ans)
{
	
	monoque.clear();
	monoque.push_back(0);
	for(int i=1; i<=n+1; i++)
	{
		while(!monoque.empty() && pfs[i-1] - pfs[monoque.front()] > ans)
			monoque.pop_front();
		dp[i] = a[i] + dp[monoque.front()];//PROBLEM
		while(!monoque.empty() && dp[i] <= dp[monoque.back()])
			monoque.pop_back();
		monoque.push_back(i);
	}
	return dp[n+1] <= ans;
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
		
		scanf("%d", &n);
		for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
		a[0] = 0;
	    a[n+1] = 0;
	    pfs[0] = 0;
	    for(int i=1; i<=n; i++) pfs[i] = pfs[i-1]+ a[i];
	    ll l = 1;
	    ll r = pfs[n];
	    while(l <= r)
	    {
	    	ll mid = (l+r)>>1;
	    	if(check(mid)) r = mid-1;
	    	else l = mid+1;
		}
		printf("%lld\n", l);
    }
    
	
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
