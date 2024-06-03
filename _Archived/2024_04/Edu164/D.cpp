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

//#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 5010;
#endif
ll a[N], dp[N][N], pfs[N];
ll M = 998244353;
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		
    }
    #endif
	#ifndef MULTI
	ll n;
	scanf("%lld", &n);
	for(ll i= 1; i<=n; i++)
		scanf("%lld", &a[i]);
	sort(a+1, a+n+1);
	ll ans = 0;
	pfs[0] = 0;
	dp[0][0] = 1;
	for(ll i=1; i<=n; i++)
	{
		for(int j=0; j<=pfs[i-1]; j++) if(dp[i-1][j])
		{
			dp[i][j] = (dp[i][j] + dp[i-1][j]) % M;
			dp[i][j+a[i]] = (dp[i][j+a[i]] + dp[i-1][j]) % M;
		}
		pfs[i] = (pfs[i-1] +  a[i]) % M;
		
	}
	for(ll i=1; i<=n; i++)
		for(ll j=0; j<=pfs[i-1]; j++)
			if(dp[i-1][j])
			{
				if(j <= a[i])
					ans = (ans + (a[i] * dp[i-1][j]) % M) % M;
				else
					ans = (ans + (a[i] + j + 1)/2 * dp[i-1][j] % M) % M;
			}
	printf("%lld", ans);
	#endif
 	return 0;
}
