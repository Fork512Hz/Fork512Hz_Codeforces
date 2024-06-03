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
#define DEBUG

#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif
ll a[N], pfs[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    #endif
    #ifdef MULTI
    ll z;
    cin >> z;
    while(z--){
		ll n;
		scanf("%lld", &n);
		for(ll i=1; i<=n; i++)
			scanf("%lld", &a[i]);
		ll ans = 0;
		pfs[0] = 0;
		for(int i=1; i<=n; i++) pfs[i] = pfs[i-1] ^ a[i];
		for(int j=1; j<=n; j++)
		{
			for(int i=1; i<=j; i++)
			{
				ll s = pfs[j] ^ pfs[i-1];
				for(int k=i; k<=j; k++)
					if((s ^ a[k]) > s)
					{
						//printf("%d %d %d\n", i, j, k);
						ans++;
					}
						
			}
		}
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
