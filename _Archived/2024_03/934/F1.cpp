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
const long long N = 410;
#endif
#ifndef DEBUG
const long long N = 410;
#endif
ll dp[N][N][N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		ll n, p, M;
		scanf("%lld%lld%lld", &n, &p, &M);
		for(int i=0; i<=p; i++) dp[0][0][i] = 1;
		for(int i=1; i<n; i++)
		{
			for(int k=0; k<=p; k++)
					dp[i][p+1][k] = 0;
			for(int j=p; j>=0; j--)
				for(int k=0; k<=p; k++)
					dp[i][j][k] = (dp[i][j+1][k] + dp[i-1][max(0, j-k)][j]) % M;
		}
		ll ans = 0;
		for(int j=p; j>=0; j--) ans = (ans + dp[n-1][j][j] ) %M;
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
