#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<deque>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long ll;
//#define DEBUG

#define MULTI

#ifdef DEBUG
const long long N = 200100;
#endif
#ifndef DEBUG
const long long N = 200100;
#endif
vector<int> graph[N<<1];
bool vis[N<<1], col[N];
vector<int> ap;
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
    	ap.clear();
    	int n, m;
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++) graph[i].clear();
		memset(vis, 0, n+5);
		for(int i=0; i<m; i++)
		{
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			if(!col[c])
			{
				graph[n+c].clear();
				vis[n+c] = 0;
				col[c] = 1;
				ap.push_back(c);
			}
			graph[u].push_back(n+c);
			graph[v].push_back(n+c);
			graph[n+c].push_back(u);
			graph[n+c].push_back(v); 
		}
		int src, dst;
		scanf("%d%d", &src, &dst);
		deque<int> bfs = {src, -1};
		vis[src] = 1;
		int depth = 0;
		while(bfs.size() > 1)
		{
			int cur = bfs.front();
			bfs.pop_front();
			if(cur == -1)
			{
				bfs.push_back(-1);
				depth++;
				continue;
			}
			if(cur == dst)
			{
				printf("%d\n", depth >> 1);
				break;
			}
			for(int i: graph[cur]) if(!vis[i])
			{
				bfs.push_back(i);
				vis[i] = 1;
			}
		}
		for(int i: ap) 
			col[i] = 0;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
