#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
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
const long long N = 2010;
#endif
vector<int> tree[N];
int par[N];
int depth, maxd;
int endp1, endp2;

void dfs(int x, int p)
{
	depth++;
	par[x] = p;
	if(depth > maxd)
	{
		maxd = depth;
		endp1 = x;
	}
	for(int i: tree[x]) if(i != p)
		dfs(i, x);
	depth--;
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
		for(int i=1; i<=n; i++) tree[i].clear();
		for(int i=0; i<n-1; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			tree[x].push_back(y);
			tree[y].push_back(x);
		}
		depth = -1;
		maxd = -1;
		dfs(1, 0);
		endp2 = endp1;
		depth = -1;
		maxd = -1;
		dfs(endp2, 0);
		int k = endp1;
		for(int i=0; i<maxd/2; i++) k = par[k];
		if(maxd & 1)
		{
			printf("%d\n", (maxd/4 + 1) *2);
			for(int i=0; i<=maxd/4; i++)
				printf("%d %d\n%d %d\n", k, 2*i+1, par[k], 2*i+1);
		}
		else 
		{
			printf("%d\n", maxd/2 + 1);
			for(int i=0; i<=maxd/2; i++)
				printf("%d %d\n", k, i);
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
