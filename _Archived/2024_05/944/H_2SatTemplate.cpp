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
#define DEBUG

#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 1500;
#endif
int n;
int constraints[N][3];
//Tarjan template -------------------------
int scc[N], dfn[N], low[N];
bool vis[N];
vector<int> graph[N];
vector<int> sccs;
deque<int> route;
const ll inf = 0x7f7f7f7f;
int depth = 0;

int rev(int x)
{
	if(x <= n) return x+n;
	else return x-n;
}
void build(int x, int y)
{
	graph[rev(x)].push_back(y);
	graph[rev(y)].push_back(x);	
}
int tarjan(int x)
{
	if(low[x] != 0)
	{
		if(!vis[x]) return dfn[x];
		//In the stack
		else return inf;
		//Out of the stack
	}
	else
	{
		route.push_back(x);
		depth++;
		dfn[x] = depth;
		low[x] = depth;
		for(int j: graph[x]) 
			low[x] = min(low[x], tarjan(j));
		if(low[x] == dfn[x])
		{
			while(route.back() != x)
			{
				scc[route.back()] = x;
				vis[route.back()] = 1;
				//Mark the node as out of the stack
				route.pop_back();
			}
			scc[x] = x;
			vis[x] = 1;
			route.pop_back();
			sccs.push_back(x);
		}
		return low[x];
	}
}
// -----------------------------------------------------------
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		
		scanf("%d", &n);
		for(int i=1; i<=2*n; i++)
			graph[i].clear();
		for(int j=0; j<3; j++)
			for(int i=0; i<n; i++)
			{
				scanf("%d", &constraints[i][j]);
				if(constraints[i][j] < 0)
					constraints[i][j] = -constraints[i][j] + n;
			}
		// a_i true = i, a_i false = i+n
		for(int i=0; i<n; i++)
		{
			build(constraints[i][1], constraints[i][2]);
			build(constraints[i][1], constraints[i][0]);
			build(constraints[i][2], constraints[i][0]);
		}
		memset(scc, 0xff, sizeof(int)*(2*n+4) );
		memset(dfn, 0, sizeof(int)*(2*n+4) );
		memset(low, 0, sizeof(int)*(2*n+4) );
		memset(vis, 0, sizeof(int)*(2*n+4) );
		route.clear();
		for(int i=1; i<=2*n; i++) if(scc[i] == -1) 
		{
			depth = 0;
			tarjan(i);
		}
		for(int i=1; i<=n; i++) if(scc[i] == scc[i+n])
		{
			printf("NO\n");
			goto fin;
		}
		printf("YES\n");
		fin:;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
