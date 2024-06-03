#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll  N = 100100;
const ll TH = 316;
ll n, q;
ll a[N], sfs[320][N], sfs2[320][N];
inline ll at1(ll x, ll y)
{
	if(x >= TH || y >= n) return 0;
	else return sfs[x][y]; 
}
inline ll at2(ll x, ll y)
{
	if(x >= TH || y >= n) return 0;
	else return sfs2[x][y]; 
}
int main()
{
	//freopen("1.txt", "r", stdin);
	ll z;
	cin >> z;
	while(z--)
	{

		
		scanf("%lld%lld",&n, &q); 
		for(ll i=0; i<n; i++) scanf("%lld", &a[i]);
		for(ll i=1; i<TH; i++)
		{
			for(ll j=1; j<=i; j++) sfs[i][n-j] = a[n-j];
			for(ll j=n-i-1; j>=0; j--) sfs[i][j] = sfs[i][j+i]+a[j];
			for(ll j=1; j<=i; j++) sfs2[i][n-j] = sfs[i][n-j];
			for(ll j=n-i-1; j>=0; j--) sfs2[i][j] = sfs2[i][j+i]+sfs[i][j];
		}
		for(ll i=0; i<q; i++)
		{
			ll s, d, k;
			scanf("%lld%lld%lld", &s, &d, &k);
			s--;
			ll f = s + d*k;
			if(d >= TH)
			{
				ll ans = 0;
				for(ll j=1; j<=k; j++) 
					ans += a[s + (j-1) * d] * j;
				printf("%lld ", ans);
			}
			else
			{
				ll ans = at2(d, s) - at2(d, f) - 
						(at1(d, f)) * k;
				printf("%lld ", ans);
			}
			
		}
		printf("\n");
	}
 	return 0;
}
