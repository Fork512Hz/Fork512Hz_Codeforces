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
ll a[N], dp[N][12];
ll inf = 0x3f3f3f3f3f3f3f3f;
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		ll n, k;
		scanf("%lld%lld", &n, &k);
		for(ll i=1; i<=n; i++)
			scanf("%lld", &a[i]);
		dp[0][0] = 0;
		for(ll i=1; i<=n; i++)
			dp[i][0] = dp[i-1][0] + a[i];
		for(ll i=0; i<=n; i++)
			for(ll j=1; j<=k; j++)
				dp[i][j] = inf;
			
		for(ll i=0; i<=n-1; i++)
		{
			ll mink[11];
			ll tmp = inf;
			for(ll j=0; j<=k && i+j<=n; j++)
			{
				tmp = min(tmp, a[i+j+1]);
				mink[j] = tmp;
			}
			for(ll j=0; j<=min(i, k); j++)
			{
				for(ll d=1; i+d<=n && j+d-1<=k; d++)
					dp[i+d][j+d-1] = min(dp[i+d][j+d-1], dp[i][j] + mink[d-1] * d);
			}
		}
		ll ans = dp[n][0];
		for(ll i=1; i<=k; i++) ans = min(dp[n][i], ans);
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
