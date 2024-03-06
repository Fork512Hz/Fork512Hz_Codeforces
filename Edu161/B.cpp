#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const ll N = 300010;
ll n;
ll a[N], pfs[N], appear[N];
inline ll C2(ll x)
{
	return x * (x-1) / 2;
}
inline ll C3(ll x)
{
	return x * (x-1) / 2 * (x-2) / 3;
}
int main()
{
	ll z;
	cin >> z;
	while(z--)
	{
		ll n;
		scanf("%lld", &n);
		for(ll i=0; i<n; i++)
		{
			scanf("%lld", &a[i]);
			appear[a[i]] ++;
		}
		pfs[0] = appear[0];
		for(ll i=0; i<=n; i++) pfs[i] = pfs[i-1] + appear[i];
		ll ans = 0;
		for(ll i=0; i<=n; i++) ans += C3(appear[i]) + C2(appear[i])*pfs[i-1];
		printf("%lld\n", ans);
		memset(appear, 0, sizeof(ll)*(n+2));
		memset(pfs, 0, sizeof(ll)*(n+2));
	}
 	return 0;
}
