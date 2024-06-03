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
const ll M = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
const ll M = 1000010;
#endif
int n, k, m, cnt, ans;
int a[N], b[N], occ[M], pat[M];

inline void ins (int x)
{
	cnt -= min(occ[x], pat[x]);
	occ[x] ++;
	cnt += min(occ[x], pat[x]);
}
inline void del (int x)
{
	cnt -= min(occ[x], pat[x]);
	occ[x] --;
	cnt += min(occ[x], pat[x]);
}
inline void jug()
{
	if(cnt >= k) ans++;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    //bool f = (z==10000);
    while(z--){
		
		scanf("%d%d%d", &n, &m, &k);
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
		for(int i=0; i<m; i++)
		{
			scanf("%d", &b[i]);
			pat[b[i]] ++;
		}
		cnt = 0;
		ans = 0;
		for(int i=0; i<m; i++)
			ins(a[i]);
		jug();
		
		for(int i=m; i<n; i++)
		{
			ins(a[i]);
			del(a[i-m]);
			jug();
		}
		printf("%d\n", ans);
		for(int i=n-m; i<n; i++)
			del(a[i]);
		for(int i=0; i<m; i++)
		{
			pat[b[i]] = 0;
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
