#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<utility>
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 200100;
#endif
int c[N], root[N], colorparent[N], group[N];
vector<int> graph[N];
vector<pii> colorgraph[N];
ll ans;
inline ll c2(int x)
{
	return (ll) x* (x-1) / 2;
}
void dfs(int x, int pa)
{
	int recovery[] = {colorparent[c[x]], group[c[pa]]};
	if(colorparent[c[x]] == -1)
	{
		root[c[x]] = x;
	}
	else if(colorparent[c[x]] == pa)
		colorgraph[colorparent[c[x]]].push_back(pii(x, x));
	else colorgraph[colorparent[c[x]]] .push_back(pii(x, group[c[x]]));
	colorparent[c[x]] = x;
	group[c[pa]] = x;
	for(int i: graph[x]) if(i != pa) dfs(i, x);
	colorparent[c[x]] = recovery[0];
	group[c[pa]] = recovery[1];
	if(colorparent[c[x]] == -1)
	{
		colorparent[c[x]] = x;
		group[c[x]] = pa;
	}
}

void dfs2(int x)
{
	if(colorgraph[x].empty()) return; 
	int len = colorgraph[x].size();
	int cnt = 1;
	for(int i=1; i<len; i++)
	{
		if(colorgraph[x][i].second == colorgraph[x][i-1].second) cnt++;
		else
		{
			ans += c2(cnt+1);
			cnt = 1;
		}
	}
	ans += c2(cnt+1);
	for(pii i: colorgraph[x]) dfs2(i.first);
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
		memset(root, -1, sizeof(int) * (n+3));
		memset(group, -1, sizeof(int) * (n+3));
		memset(colorparent, -1, sizeof(int) * (n+3));
		for(int i=1; i<=n; i++)
		{
			graph[i].clear();
			colorgraph[i].clear();
		}
		for(int i=1; i<=n; i++) scanf("%d", &c[i]);
		for(int i=1; i<=n-1; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		dfs(1, 0);
		ans = 0;
		for(int i=1; i<=n; i++) if(root[i] != -1)
			dfs2(root[i]);
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
