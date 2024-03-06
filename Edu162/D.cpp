#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 300100;
#endif
ll a[N], pfs[N], sfs[N], samep[N], sames[N], ans[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    ll z;
    cin >> z;
    while(z--){
		ll n;
		scanf("%lld", &n);
		memset(ans, 0x7f, sizeof(ll) * (n+5));
		for(ll i=1; i<=n; i++) scanf("%lld", &a[i]);
		pfs[0] = 0;
		sfs[n+1] = 0;
		for(ll i=1; i<=n; i++) pfs[i] = pfs[i-1] + a[i];
		for(ll i=n; i>=1; i--) sfs[i] = sfs[i+1] + a[i];
		samep[1] = 1;
		ll t = 1;
		for(ll i=2; i<=n; i++) if(a[i] == a[t])
			samep[i] = t;
		else
		{
			samep[i] = i;
			t=i;
		}
		sames[n] = n;
		t = n;
		for(ll i=n-1; i>=1; i--) if(a[i] == a[t])
			sames[i] = t;
		else{
			sames[i] = i;
			t=i;
		}
		a[0] = -1;
		a[n+1] = -1;
		for(ll i=1; i<=n; i++)
			if(a[i-1] > a[i] || a[i+1] > a[i]) ans[i] = 1;
		for(ll i=1; i<=n; i++) if(ans[i] != 1)
		{
			ll l = sames[i+1]+1; 
			ll r = n+1;
			ll target = pfs[i] + a[i]+1;
			if(l > n) goto second_pass;
			while(l < r)
			{
				ll mid = (l+r) >> 1;
				if(pfs[mid] < target) l = mid+1;
				else if(pfs[mid] > target) r = mid;
				else 
				{
					l = mid; 
					break;
				}
			}
			if(l > n) goto second_pass;
			ans[i] = min(ans[i], l-i);
			
			second_pass:
			l = 1;
			r = samep[i-1];
			target = sfs[i] + a[i] + 1;
			if(r <= 1) goto fin;
			while(l < r)
			{
				ll mid = (l+r) >> 1;
				if(sfs[mid] > target) l = mid+1;
				else if(sfs[mid] < target) r = mid;
				else 
				{
					l = mid+1; 
					break;
				}
			}
			l--;
			if(l == 0) goto fin;
			ans[i] = min(ans[i], i-l);
			
			fin:
			printf("%lld ", ans[i] == 0x7f7f7f7f7f7f7f7f? -1: ans[i]);
		}
		else printf("1 ");
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
