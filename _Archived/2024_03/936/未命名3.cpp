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
const long long N = 100100;
#endif
int endp1, endp2;
int fa[N], dist[N];
int depth = -1, maxd = 0;
int check;
vint tree[N];
int mid;
void cent(int x, int pa)
{
	depth++;
	fa[x] = pa;
	dist[x] = depth;
	if(depth > maxd)
	{
		maxd = depth;
		endp1 = x;
	}
	for(int i: tree[x]) if(i != pa)
		cent(i, x);
	depth--;
}
int dp(int x, int pa)
{
	int sum = 0;
	for(int i: tree[x]) if(i!= pa)
	{
		int tmp = dp(i, x);
		sum += tmp;
	}
	sum ++;
	if(sum >= mid) 
	{
		check++;
		return 0;
	}
	else return sum;
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
		int n, k;
		scanf("%d%d", &n, &k);
		for(int i=1; i<=n; i++) tree[i].clear();
		for(int i=1; i<=n-1; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			tree[x].push_back(y);
			tree[y].push_back(x);
		}
		depth = -1;
		maxd = 0;
		cent(1, 0);
		endp2 = endp1;
		depth = -1;
		maxd = 0;
		cent(endp2, 0);
		int cur = endp1;
		for(int i=0; i<maxd/2; i++)
			cur = fa[cur];
		int l = 1;
		int r = n;
		while(l < r)
		{
			mid = (l+r+1) >> 1;
			check = 0;
			dp(cur, 0);
			check --;
			if(check >= k)
				l = mid;
			else r = mid-1;
		}
		printf("%d\n", l);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
