#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<deque>
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
const ll inf  = 0x3f3f3f3f;
deque<ll> bfs;
bool vis[N];
int bfs1[N], bfs2[N];
vint tree[N];

ll dp(int x, int pa)
{
	if(bfs1[x] <= bfs2[x]) return 1;
	if(tree[x].size() == 1 && x != 1) return inf;
	ll t = 0;
	for(int i: tree[x]) if(i != pa)
		t += dp(i, x);
	return t;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    //bool f = 0;
    while(z--){
		int n, k;
		scanf("%d%d", &n, &k);
		//if(z == 9999 && n == 8 && k == 2) f=1;
		memset(vis, 0, n+3);
		bfs.clear();
		for(int i=0; i<k; i++)
		{
			int x;
			scanf("%d", &x);
			bfs.push_back(x);
			vis[x] = 1;
		}
		for(int i=1; i<=n; i++) tree[i].clear();
		for(int i=0; i<n-1; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			tree[x].push_back(y);
			tree[y].push_back(x);
		}
		int depth = 0;
		bfs.push_back(-1);
		
		while(bfs.size() != 1)
		{
			int cur = bfs.front();
			bfs.pop_front();
			if(cur == -1)
			{
				depth++; 
				bfs.push_back(-1);
				continue;
			}
			bfs1[cur] = depth;
			for(int i: tree[cur]) if(!vis[i])
			{
				bfs.push_back(i);
				vis[i] = 1;
			}
		}
		memset(vis, 0, n+3);
		bfs = {1, -1};
		depth = 0;
		vis[1] = 1;
		while(bfs.size() != 1)
		{
			int cur = bfs.front();
			bfs.pop_front();
			if(cur == -1)
			{
				depth++; 
				bfs.push_back(-1);
				continue;
			}
			bfs2[cur] = depth;
			for(int i: tree[cur]) if(!vis[i])
			{
				bfs.push_back(i);
				vis[i] = 1;
			}
		}
		ll ans = dp(1, 0);
		printf("%lld\n",  ans>=inf? -1: ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
