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
const long long N = 200100;
#endif
// const ll M = 998244353;
bool vis[N];
pii hori[N], vert[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		int h, w, n, q;
		scanf("%d%d%d%d", &h, &w, &n , &q);
		memset(vis, 0, n+5);
		for(int i=0; i<n; i++)
		{
			int x, y;
			scanf("%d %d\n", &x, &y);
			vert[i] = {x, i};
			hori[i] = {y, i};
		}
		sort(hori, hori+n);
		sort(vert, vert+n);
		pii *xl = vert;
		pii *xr = vert+n;
		pii *yl = hori;
		pii *yr = hori+n;
		int xleft = 1, yleft = 1, xright = h+1, yright = w+1;
		int ans[2] = {0, 0};
		for(int i=0; i<q; i++)
		{
			int &cnt = ans[i%2];
			char op; int v;
			scanf("%c %d\n", &op, &v);
			pii *start, *finish;
			pii pivot;
			switch(op)
			{
				case 'U': pivot = {xleft + v, -1}; break;
				case 'D': pivot = {xright - v, -1}; break;
				case 'L': pivot = {yleft + v, -1}; break;
				case 'R': pivot = {yright - v, -1}; break;
			}
			if (op == 'U' || op == 'D')
			{
				start = xl; finish = xr;
			}
			else
			{
				start = yl; finish = yr;
			}
			pii *cut = lower_bound(start, finish, pivot);
			auto rem = [&] (pii *lb, pii *rb)
			{
				for(pii *i = lb; i < rb; i++)
					if(!vis[(*i).second])
					{
						vis[(*i).second] = 1;
						cnt ++;
					}
			};
			switch(op)
			{
				case 'U':
					rem(xl, cut);
					xl = cut; xleft += v;
					break;
				case 'D':
					rem(cut, xr);
					xr = cut; xright -= v;
					break;
				case 'L':
					rem(yl, cut);
					yl = cut; yleft += v;
					break;
				case 'R':
					rem(cut, yr);
					yr = cut; yright -= v;
					break;
			}
			
		}
		printf("%d %d\n", ans[0], ans[1]);
    }
 	return 0;
}
