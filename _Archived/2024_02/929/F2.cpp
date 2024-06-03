// Problem: F. Turtle Mission: Robot and the Earthquake
// Contest: Codeforces - Codeforces Round 929 (Div. 3)
// URL: https://codeforces.com/contest/1933/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<deque>
#include<utility>
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1010000;
#endif
#ifndef DEBUG
const ll N = 1010000;
#endif
int *grid[N];
int *vis[N];
int ans[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n,m ;
		scanf("%d%d", &n, &m);
		for(int i=0; i<n+5; i++) 
			ans[i]  = 0x7f7f7f7f;
		for(int i=0; i<n; i++) 
		{
			free(grid[i]);
			free(vis[i]);
			grid[i] = (int*) calloc(m+5, sizeof(int));
			vis[i] = (int*) calloc((m+5), sizeof(int));
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				scanf("%d", &grid[i][j]);
				if(grid[i][j] == 1) vis[i][j] = 0x7f7f7f7f;
			}
		}
		int steps = 0;
		deque<pii> bfs = {pii(0, 0), pii(-1, -1)};
		vis[0][0] = -1;
		while(bfs.size() > 1)
		{
			pii cur = bfs.front();
			bfs.pop_front();
			if(cur.first == -1)
			{
				steps ++;
				bfs.push_back(cur);
				//printf("step=%d-------------------\n", steps);
				continue;
				
			}
			int x = cur.first;
			int y = cur.second;
			//printf("%d %d\n", x, y);
			if(y == m-1) ans[x] = steps;
			if(y != m-1)
				if(! grid[(x+1)%n][y+1] && !vis[(x+1)%n][y+1])
				{
					bfs.push_back(pii ((x+1)%n, y+1));
					vis[(x+1) % n] [y+1] = steps+1;
				}
			if(! grid[(x+1)%n][y] && ! grid[(x+2)%n][y] && !vis[(x+2)%n][y])
				{
					bfs.push_back(pii ((x+2)%n, y));
					vis[(x+2)%n] [y] = steps+1;
				}
			
		}
		int result = 0x7f7f7f7f;
		for(int i=0; i<n; i++)
		{
			int rem = (i+1) % n;
			int cur = ans[i] % n;
			ans[i] += (rem+n-cur)%n;
			result = min(result, ans[i]);
		}
		printf("%d\n", result == 0x7f7f7f7f? -1: result);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
