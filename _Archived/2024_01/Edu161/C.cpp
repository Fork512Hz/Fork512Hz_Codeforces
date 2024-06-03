#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll N = 100010;
ll n;
ll pfs[N], sfs[N], a[N];
int main()
{
	ll z;
	cin >> z;
	while(z--)
	{
		ll n;
		scanf("%lld", &n);
		for(ll i=1; i<=n; i++)
		{
			scanf("%lld", &a[i]);
		}
		pfs[1] = 0;
		pfs[2] = 1;
		sfs[n] = 0;
		sfs[n-1] = 1;
		for(ll i=2; i<=n-1; i++)
		{
			if(a[i+1] - a[i] < a[i] - a[i-1])
				pfs[i+1] = pfs[i] + 1;
			else pfs[i+1] = pfs[i] + a[i+1] - a[i];
		}
		for(ll i=n-1; i>=2; i--)
		{
			if(a[i] - a[i-1] < a[i+1] - a[i])
				sfs[i-1] = sfs[i] + 1;
			else sfs[i-1] = sfs[i] + a[i] - a[i-1];
		}
		ll q;
		scanf("%lld", &q);
		for(ll i=0; i<q; i++)
		{
			ll x, y;
			scanf("%lld%lld", &x, &y);
			if(y >= x) printf("%lld", pfs[y] - pfs[x]);
			else printf("%lld", sfs[y] - sfs[x]);
			printf("\n");
		}
		memset(pfs, 0, sizeof(ll) * (n+3));
		memset(sfs, 0, sizeof(ll)* (n+3));
	}
 	return 0;
}
