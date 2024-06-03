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
		ll n, s;
		scanf("%lld%lld", &n, &s);
		for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
		pfs[0] = 0;
		for(int i=1; i<=n; i++) pfs[i] = pfs[i-1] + a[i];
		pfs[n+1] = 0x8080808080808080;
		ll k1=0, k2=1, ans=0, ansl=-1, ansr=-1;
		while(k1 <= n)
		{
			while(pfs[k2] - pfs[k1] >= -s && k2 <= n) k2++;
			k2--;
			if(pfs[k2] - pfs[k1] >= -s)
			{
				if(k2 - k1 > ans)
				{
					ans = k2-k1;
					ansl = k1+1; 
					ansr = k2;
				}
			}
			k1++; k2++;
		}
		if(ansl == -1) printf("-1\n");
		else printf("%lld %lld\n", ansl, ansr);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
