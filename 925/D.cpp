#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;
//#define DEBUG

#define MULTI
ll n, x, y;
#ifdef DEBUG
const ll N = 200100;
#endif
#ifndef DEBUG
const ll N = 201000;
#endif
ll a[N];
ll c2(ll x)
{
	return x * (x-1) /2;
}
bool cmp(ll p, ll q)
{
	if(p%y != q%y) return p%y<q%y;
	return p%x<q%x;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		
		scanf("%lld%lld%lld" , &n, &x, &y);
		for (ll i=0; i<n; i++) scanf("%d", &a[i]);
		sort(a, a+n, cmp);
		ll l=0, r=0; 
		ll ans = 0;
		ll rr1 = a[l] % y;
		a[n] = 0;
		while(l < n)
		{
			while(a[r] % y == rr1 && r<n) r++;
			ll lcnt = 0;
			ll rcnt = 0;
			ll k1 = l;
			ll k2 = r-1;
			ll cnt=0;
			while(a[k1] % x == 0 && k1 < r)
			{
				k1++;
				cnt++;
			}
			ans += c2(cnt);
			while(k1 <  k2)
			{
				if(a[k1] % x + a[k2] % x == x)
				{
					int r1 = a[k1] % x;
					int r2 = a[k2] % x;
					while(a[k1]%x  == r1 && k1 < r)
					{
						lcnt++;
						k1++;
					}
					while(a[k2] %x == r2 && k2 >= l)
					{
						rcnt++;
						k2--;
					}
					if(r1 == r2)
						ans += c2(lcnt);
					else ans+= lcnt*rcnt;
					lcnt=0;
					rcnt=0;
				}
				else if (a[k1] % x + a[k2] % x < x && k1 < r) k1++;
				else if (k2 >= l)k2--;
			}
			l=r;
			rr1 = a[l] % y;
		}
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
