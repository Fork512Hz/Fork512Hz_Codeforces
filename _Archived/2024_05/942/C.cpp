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
ll a[N];
ll pfs[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		ll n, k0, k;
		scanf("%lld%lld", &n, &k0);
		k= k0;
		for(ll i=1; i<=n; i++)
			scanf("%lld", &a[i]);
		sort(a+1, a+n+1);
		ll i;
		memset(pfs, 0, sizeof(ll) * (n+5));
		for(i=1; i<n; i++)
		{
			if(k >= (a[i+1] - a[i]) * i)
			{
				k -= (a[i+1] - a[i]) * i;
				pfs[i] += a[i+1] - a[i];
			}
			else
			{
				int div = k / i;
				pfs[i] += div;
				int rem = k % i;
				pfs[i] ++;
				pfs[i-rem] --;
				break;
			}
		}
		if(i == n)
		{
			ll sum = 0;
			for(int i=1; i<=n; i++) sum += a[i];
			printf("%lld\n", sum + k0 - n + 1);
		}
		else
		{
			pfs[n+1] = 0;
			for(ll i=n; i>=1; i--)
			{
				pfs[i] += pfs[i+1];
				a[i] += pfs[i];
			}
			ll min = a[1];
			ll i = 1;
			for(i=1; i<=n; i++)
				if(a[i] - min >= 1)  break;
			printf("%lld\n", min * n +2-i);
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
