#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll z;
const ll M = 998244353;
int main()
{
	cin >> z;
	while(z--)
	{
		
		ll n, k;
		scanf("%lld%lld", &n, &k);
		ll dp[n+5][k+5] = {};
		for(ll i=1; i<=k; i++) dp[0][i] = 1;
		for(ll i=1; i<=n; i++)
			for(ll j=1; j<=k; j++)
			{
				for (ll t=1; i-t*j>=0 && t+j-1 <= k; t++)
				{
					dp[i][j] = (dp[i][j] + dp[i-t*j][t]) % M;
				}
			}
		ll ans = 0;
		for(int i=1; i<=k; i++) ans = (ans + dp[n][i]) % M;
		printf("%lld\n", ans);
	}	
 	return 0;
}
