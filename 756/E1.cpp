// Problem: E1. Escape The Maze (easy version)
// Contest: Codeforces - Codeforces Round 756 (Div. 3)
// URL: https://codeforces.com/contest/1611/problem/E1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<deque>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 200100;
#endif
int block[N];
deque<int> route = {};
vector<int> tree[N];
bool vis[N];

int main()
{

    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n, k;
		scanf("%d%d", &n, &k);
		memset(block, 0xff, sizeof(int) * (n+5));
		memset(vis, 0, sizeof(bool) * (n+5));
		for(int i=1; i<=n; i++) tree[i].clear();
		route.clear();
		for(int i=0; i<k; i++) 
		{
			int x;
			scanf("%d", &x);
			block[x] = 0;
			route.push_back(x);
		}
		for(int i=0; i<n-1; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			tree[x].push_back(y);
			tree[y].push_back(x);
		}
		route.push_back(-1);
		int depth =0 ;
		while(route.size() > 1)
		{
			int cur = route.front();
			route. pop_front();
			if(cur == -1)
			{
				depth++;
				route.push_back(-1);
				continue;
			}
			
			for(int i: tree[cur]) if(block[i] == -1)
			{
				route.push_back(i);
				block[i] = depth+1;
			}
		}
		route = {1, -1};
		depth =0 ;
		vis[1] = 1;
		while(route.size() > 1)
		{
			int cur = route.front();
			route. pop_front();
			if(cur == -1)
			{
				depth++;
				route.push_back(-1);
				continue;
			}
			if(cur != 1 && tree[cur].size() == 1  && depth < block[cur])
			{
				printf("Yes\n");
				goto fin;
			}
			for(int i: tree[cur]) if(!vis[i])
			{
				route.push_back(i);
				vis[i]= 1;
			}
		}
		printf("No\n");
		fin:;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
