#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<functional>
#include<deque>
#include<set>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vll;
typedef long long ll;
typedef long long i64;

//#define DEBUG

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif
// const ll M = 998244353;
ll dp[52][50010];
ll c[55], v[55];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		ll n, x;
		ll maxv = 0;
		scanf("%lld%lld", &n, &x);
		for(ll i=0; i<n; i++)
		{
			scanf("%lld%lld", &c[i], &v[i]);
			maxv += v[i];
		}
		
		for(ll i=0; i<n; i++)
			memset(dp[i], 0x3f, sizeof(ll) * (maxv+4));
		dp[0][c[0]==0? v[0]: 0] = 0;
		for(ll i=0; i<n; i++)
		{
			for(ll j=0; j<=maxv; j++) if(dp[i][j] < 1e12)
			{
				dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
				if(dp[i][j] + c[i+1] <= (i+1) * x)
					dp[i+1][j+v[i+1]] = min(dp[i+1][j+v[i+1]], dp[i][j] + c[i+1]);
					
			}
		}
		ll i=maxv;
		for(; i>=0; i--) if(dp[n-1][i] < 1e12) break;
		printf("%lld\n", i);
    }
 	return 0;
}
