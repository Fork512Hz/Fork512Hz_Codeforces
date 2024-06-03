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
const long long N = 500100;
#endif
// const ll M = 998244353;
bool c[N];
vector<int> tree[N];
int bcnt = 0, xor2 = 0;
int pa[N], bdeg[N], bdegcnt[N];
void dfs(int x, int  p)
{
	pa[x] = p;
	bdeg[pa[x]] += c[x];
	for(int i: tree[x]) if(i != p)
		dfs(i, x);
}
inline int bdegcnt012()
{
	return bdegcnt[0] + bdegcnt[1] + bdegcnt[2];
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
		int n, q;
		scanf("%d%d", &n, &q);
		memset(c, 0, n+5);
		for(int i=1; i<=n; i++) tree[i].clear();
		for(int i=1; i<=n; i++)
			scanf("%d", &c[i]);
		for(int i=1; i<n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			tree[v].push_back(u);
			tree[u].push_back(v);
		}
		bcnt = 0;
		memset(bdeg, 0, sizeof(int) * (n+5));
		memset(bdegcnt, 0, sizeof(int) * (n+5));
		dfs(1, 0);
		bdeg[0] = 0;
		xor2 = 0;
		for(int i=1; i<=n; i++) if(c[i])
		{
			bdegcnt[bdeg[i]] ++;
			bcnt ++;
			if(bdeg[i] == 2) xor2 ^= i;
		}
		for(int t=0; t<q; t++)
		{
			int x;
			scanf("%d" , &x);
			if(!c[x])
			{
				bcnt++;
				c[x] = 1;
				if(x != 1)
				{
					if(c[pa[x]])
					{
						bdegcnt[bdeg[pa[x]]]--;
						if(bdeg[pa[x]] == 2) xor2 ^= pa[x];
					}
					bdeg[pa[x]] ++;
					
					if(c[pa[x]])
					{
						bdegcnt[bdeg[pa[x]]]++;
						if(bdeg[pa[x]] == 2) xor2 ^= pa[x];
						
					}
						
				}
				
				bdegcnt[bdeg[x]] ++;
				if(bdeg[x] == 2) xor2 ^= x;
			}
			else
			{
				bcnt--;
				c[x] = 0;
				if(x != 1)
				{
					if(c[pa[x]])
					{
						bdegcnt[bdeg[pa[x]]]--;
						if(bdeg[pa[x]] == 2) xor2 ^= pa[x];
					}
					bdeg[pa[x]] --;
					if(c[pa[x]])
					{
						bdegcnt[bdeg[pa[x]]]++;
						if(bdeg[pa[x]] == 2) xor2 ^= pa[x];
					}
				}
				bdegcnt[bdeg[x]] --;
				if(bdeg[x] == 2) xor2 ^= x;
			}
			if(bcnt == bdegcnt012() && 
				(bdegcnt[0] == 1 && bdegcnt[2] == 0 ||
				 bdegcnt[0] == 2 && bdegcnt[2] == 1 && !c[pa[xor2]]))
				printf("Yes\n");
			else printf("No\n"); 
			
		}
    }
 	return 0;
}
