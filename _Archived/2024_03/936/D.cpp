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
const long long N = 100100;
#endif
ll a[N], pfs[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		ll n, x;
		scanf("%lld%lld", &n, &x);
		pfs[0] = 0ll;
		for(int i=1; i<=n; i++)
		{
			scanf("%lld", &a[i]);
			pfs[i] = pfs[i-1] ^ a[i];
		}
		ll mask = 0ll;
		int ans = -1;
		for(int i=29; i>=0; i--) 
		{
			if(x & (1ll << i))
			{
				mask += (1ll << i);
				int pv = 0;
				int nseg = 0;
				for(int j=1; j<=n; j++)
				{
					if(!((pfs[j] ^ pfs[pv]) & mask ))
					{
						nseg ++;
						pv = j;
					}
					
				}
				if(pv == n)
					ans = max(nseg, ans);
				mask -= (1ll << i);
			}
			else mask += (1ll << i);
		}
		int pv = 0;
		int nseg = 0;
		for(int i=1; i<=n; i++)
		{
			if(!((pfs[i] ^ pfs[pv]) & mask ))
			{
				nseg ++;
				pv = i;
			}
			
		}
		if(pv == n)
				ans = max(nseg, ans);
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
