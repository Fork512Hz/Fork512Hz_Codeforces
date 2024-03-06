#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
const ll K = 2100;
#endif
#ifndef DEBUG
const ll N = 100100;
const ll K = 1050000;
#endif
const ll inf = 0x7f7f7f7f;
vector<int> conn[N], todo;
int a[N], dp[K];
void dfs(int x, int pa)
{
	for(int i: conn[x]) if(i != pa)
	{
		dfs(i, x);
		a[x] ^= a[i];
	}
	
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
		int n;
		scanf("%d", &n);
		memset(a, 0, sizeof(int) * (n+5));
		for(int i=1; i<=n; i++) conn[i].clear();
		for(int i=1; i<=n-1; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			conn[x].push_back(y);
			conn[y].push_back(x);
		}
		int k;
		scanf("%d", &k);
		memset(dp, 0x7f, sizeof(int) * (1<<k));
		for(int i=0; i<k; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			a[x] += (1<<i);
			a[y] += (1<<i);
		}
		dfs(1, -1);
		todo.clear();
		for(int i=1; i<=n; i++)
			if(dp[a[i]] == inf)
			{
				todo.push_back(i);
				dp[a[i]] ++;
			}
		dp[0] = 0;
		for(int i=0; i<(1<<k); i++)
		{
			for(int j: todo)
			{
				dp[i | a[j]] = min(dp[i | a[j]], dp[i] + 1);
			}
		}
		printf("%d\n", dp[ (1<<k) - 1]);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
