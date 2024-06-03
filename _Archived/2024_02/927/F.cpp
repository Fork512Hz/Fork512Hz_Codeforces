#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 1001000;
#endif

int pfs[N], ans[N], best[N], bar[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i=0; i<n+10; i++) 
		{
			pfs[i] = 0;
			bar[i] = i;
		}
		for(int i=1; i<=m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if(x>y)
			{
				int t;
				t=x; x=y; y=t;
			}
			pfs[x] ++;
			pfs[y+1] --;
			bar[x] = max(y, bar[x]);
		}
		bar[0] = 0;
		for(int i=1; i<=n; i++) bar[i] = max(bar[i], bar[i-1]);
		pfs[0] = 0;
		for(int i=1; i<=n; i++) pfs[i] += pfs[i-1];
		ans[n+1] = 0;
		best[n+1] = 0;
		for(int i=n; i>=1; i--)
		{
			ans[i] = pfs[i] + best[bar[i] + 1];
			best[i] = max(ans[i], best[i+1]);
		}
		printf("%d\n", best[1]);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
