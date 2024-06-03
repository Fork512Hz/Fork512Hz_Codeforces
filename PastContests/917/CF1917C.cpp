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
const ll N = 2000;
const ll K = 100100;
#endif
int a[N], v[K], k;
inline int b(int x)
{
	return v[x % k];
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
		int n,  d;
		scanf("%d%d%d", &n, &k, &d);
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		for(int i=1; i<=k; i++) scanf("%d", &v[i]);
		v[0] = v[k];
		int ans = (d-1)/2;
		for(int j=1; j<=n; j++)
			if(a[j] == j) ans++;
		for(int i=1; i<=2*n+1 && i <= d-1; i++)
		{
			int tmp = 0;
			for(int j=1; j<=n; j++)
			{
				if(j <= b(i)) a[j]++;
				if(a[j] == j) tmp++;
			}
			if(tmp + (d-i-1)/2 > ans) ans = tmp + (d-i-1)/2;
		}
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
