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
const long long N = 200100;
#endif
int pfs[N],pfm[N], a[N], b[N];
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
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		for(int i=1; i<=n; i++) scanf("%d", &b[i]);
		pfs[0]=0;
		for(int i=1; i<=n; i++) pfs[i] = pfs[i-1] + a[i];
		pfm[0] = -1;
		for(int i=1; i<=n; i++) pfm[i] = max(pfm[i-1], b[i]);
		int ans = -1;
		for(int i=1; i<=min(k, n); i++)
			ans = max(ans, pfs[i] + pfm[i] * (k-i));
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
