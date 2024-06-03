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
const long long N = 6;
#endif
#ifndef DEBUG
const long long N = 20;
#endif
// const ll M = 998244353;
int n, dp[N+2][(1<<N)+100];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    z = 1;
    //cin >> z;
    while(z--){
		scanf("%d", &n);
		const int nn = (1<<n);
		for(int i=1; i<=nn-1; i++)
			scanf("%d", &dp[0][i]);
		dp[0][0] = (nn<<1) - 1;
		for(int i=0; i<n; i++)
		{
			for(int START = 0; START < (1<<i); START ++)
			{
				if(dp[i][START+(1<<i)] & 1)
					for(int j=0; j<nn; j+=(1<<(i+1)))
						dp[i+1][START+j] = 
						dp[i][START+j] & dp[i][START+j+(1<<i)] & ((nn-1) >> (i));
					
				
				if(dp[i][START+(1<<i)] & 2)
					for(int j=0; j<nn; j+=(1<<(i+1)))
						dp[i+1][START+j+(1<<i)] = 
						dp[i][START+j] & (dp[i][START+j+(1<<i)] >> 1) & ((nn-1) >> (i));
			}
		}
		vector<int> ans;
		for(int i=0; i<nn; i++) if(dp[n][i])
			ans.push_back(i);
		printf("%d\n", ans.size());
		for(int i: ans) printf("%d\n", i);
    }
 	return 0;
}
