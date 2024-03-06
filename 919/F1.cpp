#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<deque>
typedef long long ll;
using namespace std;

//#define DEBUG


#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 301000;
#endif
const int inf = 0x7fffffff;
int saf[N];
bool vis[N];
int n, m, q, depth, mid, start;
deque<int> bfs;
inline int f(int x, int y)
{
	return x*m+y;
}
void step1(int x, int y)
{
	if(x<0 || x>=n) return;
	if(y<0 || y>=m) return;
	if(vis[f(x, y)] ) return;
	vis[f(x, y)] = 1;
	bfs.push_back(f(x, y));
	if(saf[f(x, y)] != -1)
		saf[f(x, y)] = depth;
}
void step2(int x, int y)
{
	if(x<0 || x>=n) return;
	if(y<0 || y>=m) return;
	if(vis[f(x, y)] ) return;
	if(saf[f(x, y)] < mid) return;
	vis[f(x, y)] = 1;
	bfs.push_back(f(x, y));
}
void step3(int x, int y)
{
	if(x<0 || x>=n) return;
	if(y<0 || y>=m) return;
	if(vis[f(x, y)] ) return;
	vis[f(x, y)] = 1;
	bfs.push_back(f(x, y));
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    freopen("log.txt", "w", stdout);
    #endif
	scanf("%d%d%d", &n, &m, &q);
	memset(vis, 0, sizeof(bool) * (n*m+5));
	bfs.clear();
	bfs.push_back(-1);
	start = -1;
	for(int i=0; i<n; i++)
	{
		string s;
		cin >> s;
		for(int j=0; j<m; j++) switch(s[j])
		{
			case '.': saf[f(i, j)] = inf; break;
			case '#': 
				saf[f(i, j)] = -1;
				if(start == -1) start = f(i, j); 
				break;
			case 'v': 
				saf[f(i, j)] = 0;
				bfs.push_back(f(i, j));
				vis[f(i, j)] = 1;
				break;
		}
	}
	depth = 0;
	while(bfs.size() > 1)
	{
		int cur = bfs.front();
		bfs.pop_front();
		if(cur == -1)
		{
			bfs.push_back(-1);
			depth ++;
		}
		else
		{
			int x, y;
			x = cur / m;
			y = cur % m;
			step1(x, y+1);
			step1(x, y-1);
			step1(x+1, y);
			step1(x-1, y);
		}
	}
	/*for(int i=0; i<n*m; i++)
	{
		printf("%2d ", saf[i]);
		if(i%m == m-1) printf("\n");
	}*/
	bfs.clear();
	for(int i=0; i<q; i++)
	{
		//printf("------------------------\n");
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		int l = 0;
		int r = saf[f(u, v)];
		while(l < r)
		{
			bool flag = 1;
			mid = (l+r+1) >> 1;
			//printf("Checking: %d %d %d\n",l, r, mid);
			bfs = {f(u,v)};
			memset(vis, 0, sizeof(bool) * (n*m+5));
			vis[f(u, v)] = 1;
			while(!bfs.empty())
			{
				int cur = bfs.front();
				bfs.pop_front();
				int x, y;
				x = cur / m;
				y = cur % m;
				step2(x, y+1);
				step2(x, y-1);
				step2(x+1, y);
				step2(x-1, y);
			}
			/*for(int i=0; i<n*m; i++)
			{
				printf("%d ", vis[i]);
				if(i%m == m-1) printf("\n");
			}
			printf("\n");*/
			vis[start] = 1;
			bfs = {start};
			while(!bfs.empty())
			{
				int cur = bfs.front();
				bfs.pop_front();
				int x, y;
				x = cur / m;
				y = cur % m;
				if(x == 0 || y == 0 || x == n-1 || y == m-1)
				{
					//printf("Path to (%d, %d) found, fail\n", x, y);
					flag = 0;
					break;
				}
				step3(x, y+1);
				step3(x, y-1);
				step3(x+1, y);
				step3(x-1, y);
				step3(x+1, y+1);
				step3(x-1, y+1);
				step3(x-1, y-1);
				step3(x+1, y-1);
			}
			if(flag) 
			{
				l=mid;
				//printf("No path, success\n");
			}
			else r=mid-1;
		}
		printf("%d\n", l);
	}
 	return 0;
}
