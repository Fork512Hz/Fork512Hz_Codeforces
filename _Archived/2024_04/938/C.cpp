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
const long long N = 500100;
#endif
ll a[N], pfs, sfs;
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		ll n, k;
		scanf("%lld%lld", &n, &k);
		for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
		a[n+1] = 0x3f3f3f3f3f3f3f3f;
		a[0] = 0x3f3f3f3f3f3f3f3f;
		int ans = 0;
		pfs = 0;
		sfs = 0;
		int k1, k2;
		ll res = 0;
		for(int i=1; i<=n+1; i++) 
		{
			pfs += a[i];
			if(pfs > (k+1) / 2)
			{
				k1 = i-1;
				res += pfs - (k+1) / 2;
				break;
			}
		}
		for(int i=n; i>=0; i--) 
		{
			sfs += a[i];
			if(sfs > k/2)
			{
				k2 = i+1;
				res += sfs - k/2;
				break;
			}
		}
		if(k1 + 1 >= k2) ans = n;
		else if(k1 + 2 < k2) ans = k1+n-k2+1;
		else
		{
			ans = n-1;
			if(res <= a[k1+1]) ans++;
		}
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
