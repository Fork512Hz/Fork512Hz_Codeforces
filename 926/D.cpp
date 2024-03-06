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
#endif
#ifndef DEBUG
const ll N = 300010;
#endif
const ll M = 998244353;
vector<int> conn[N];
ll single[N];
ll ans[N];

ll dfs1(int x, int prev)
{
	ll ret = 1;
	for(int i: conn[x]) if(i != prev)
	{
		ret = ret * dfs1(i, x) % M;
	}
	ret = (ret+1) % M;
	single[x] = ret;
	return ret;
}
ll dfs2(int x, int prev)
{
	ll a1=1;
	ll a2=1;
	bool fl = 0;
	for(int i: conn[x]) if(i != prev)
	{
		fl = 1;
		a1 = (a1 + dfs2(i, x) - 1 + M)% M;
		a2 = a2*single[i] % M;
	}
	if(!fl)
	{
		ans[x] = 2;
		return 2;
	}
	ans[x] = (a1+a2) % M;
	return ans[x];
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
		for(int i=1; i<=n; i++) conn[i].clear();
		for(int i=0; i<n-1; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			conn[x].push_back(y);
			conn[y].push_back(x);
		}
		dfs1(1, -1);
		dfs2(1, -1);
		printf("%lld\n", ans[1]);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
