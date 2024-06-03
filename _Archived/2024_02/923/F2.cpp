#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<deque>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI
struct edge{
	int l, r, wt;
	edge(){
	}
	edge(int a, int b, int c):
		l(a), r(b), wt(c)
		{
			
		}
};
#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 200100;
#endif
vector<int> graph[N];
edge edges[N];
int bcj[N], parent[N];
bool vis[N];
bool gt(edge x, edge y)
{
	return x.wt > y.wt;
}
int find(int x)
{
	if(bcj[x] == 0) return x;
	int tmp = find(bcj[x]);
	bcj[x] = tmp;
	return tmp;
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
		int v, e;
		scanf("%d%d", &v, &e);
		for(int i=1; i<=v; i++) graph[i].clear();
		memset(bcj, 0, sizeof(int) * (v+5));
		memset(vis, 0, sizeof(bool) * (v+5));
		memset(parent, 0, sizeof(int) * (v+5));
		for(int i=0; i<e; i++)
		{
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			graph[x].push_back(y);
			graph[y].push_back(x);
			edges[i] = edge(x, y, w);
		}
		sort(edges, edges+e, gt);
		int last = -1;
		for(int i=0; i<e; i++)
		{
			edge &cur = edges[i];
			if(find(cur.l) == find(cur.r)) 
				last = i;
			else 
				bcj[find(cur.r)] = cur.l;
		}
		edge &ans = edges[last];
		printf("%d ", ans.wt);
		int source = ans.l;
		int target = ans.r;
		parent[source] = target;
		vis[source] = 1;
		deque<int> bfs = {source, -1};
		int depth = 0;
		while(1)
		{
			int cur = bfs.front();
			bfs.pop_front();
			if(cur < 0)
			{
				bfs.push_back(cur-1);
				depth = -cur;
				continue;
			}
			for(int i: graph[cur]) if(!vis[i] && i != parent[cur])
			{
				parent[i] = cur;
				vis[i] = 1;
				bfs.push_back(i);
				if(i == target) goto output;
			}
		}
		output:
		printf("%d\n%d", depth+2, source);
		int k = target;
		while(k != source)
		{
			printf(" %d", k);
			k = parent[k];
		}
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
