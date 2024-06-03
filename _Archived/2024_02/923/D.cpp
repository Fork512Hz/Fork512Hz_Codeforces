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
const ll N = 200100;
#endif
int a[N], ans[N];
int main()
{
    #ifdef DEBUG
    //freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n, q;
		scanf("%d", &n );
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		int h = 1;
		int prev = a[1];
		for(int i=2; i<=n; i++) if(a[i] != prev)
		{
			for(int j=h; j<i; j++) ans[j] = i;
			h = i;
			prev = a[i];
		}
		for(int j=h; j<=n; j++) ans[j] = n+100;
		scanf("%d", &q);
		for(int i=0; i<q; i++) 
		{
			int l, r;
			scanf("%d%d", &l, &r);
			if(r >= ans[l] && l != r) printf("%d %d\n", l, ans[l]);
			else printf("-1 -1\n");
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
