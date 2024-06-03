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
const long long N = 200100;
#endif
// const ll M = 998244353;
vector<int> tree[N];
int pa[N];
int depth = 0, maxd = -1;
void dfs(int x, int p)
{
	depth++;
	maxd = max(depth, maxd);
	for(int i: tree[x]) if(i != p)
		dfs(i, x);
	depth--;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		int n, r, b;
		scanf("%d%d%d", &n, &r, &b);
		memset(pa, 0xff, sizeof(int) * (n+3));
		for(int i=1; i<=n; i++) tree[i].clear();
		for(int i=1; i<n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			tree[u].push_back(v);
			tree[v].push_back(u);
			
		}
		deque<int> bfs = {r, -1};
		depth = 0;
		pa[r] = -1;
		int src = -1;
		int ans = 0;
		while(bfs.size() > 1)
		{
			int cur = bfs.front();
			bfs.pop_front();
			if(cur == -1)
			{
				depth++;
				bfs.push_back(-1);
				continue;
			}
			if(cur == b)
			{
				src = b;
				ans = (depth+1) / 2;
				for(int i=0; i<ans; i++)
					src = pa[src];
				break;
			}
			for(int i: tree[cur]) if(i != pa[cur])
			{
				pa[i] = cur;
				bfs.push_back(i);
			}
				
		}
		depth  = -1; maxd = -1;
		dfs(src, -1);
		printf("%d\n", ans + 2 * (n-1) - maxd);
    }
 	return 0;
}
