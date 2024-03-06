#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

//#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 200100;
#endif
const int inf = 0x7fffffff;
int par[N];
vector<int> save;
vector<int> child[N];
int dfs(int x, int depth)
{
	int d = (x==0)? inf: depth;
	for(int i: child[x])
	{
		int tmp = dfs(i, depth+1);
		int sv = min(tmp, d) - 2*depth;
		if(x == 0) sv -= 2;
		if(sv > 0) save.push_back(sv);
		d = max(tmp, d);
	}
	return d;
}
inline bool cmp(int x, int y)
{
	return x>y;
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
		
    }
    #endif
	#ifndef MULTI
	child[0] = {1};
    par[1] = 0;
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=2; i<=n; i++) 
	{
		scanf("%d",&par[i]);
		child[par[i]].push_back(i);
	}
	dfs(0, -1);
	sort(save.begin(), save.end(), cmp);
	int len = save.size();
	int ans = 2*(n-1);
	for(int i=0; i<k+1 && i<len; i++) 
		ans -= save[i];
	printf("%d\n", ans);
	#endif
 	return 0;
}
