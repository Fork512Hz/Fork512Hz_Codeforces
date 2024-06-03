#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;


//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 2010;
#endif
struct cl{
	ll idx;
	pll val;
	cl(){
	}
	cl(ll t, pll pp): idx(t), val(pp)
	{
		}	
};
inline bool cmp(cl p, cl q)
{
	if(p.val.second != q.val.second)return p.val.second < q.val.second;
	return p.val.first < q.val.first;
}
inline bool cmp2(cl p, cl q)
{
	if(p.val.first != q.val.first)return p.val.first < q.val.first;
	return p.val.second < q.val.second;
}
cl b[N], a[N];
ll a2b[N], b2a[N];
bool vis[N], sel[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    ll z;
    cin >> z;
    while(z--){
		ll n, l;
		scanf("%lld%lld", &n ,&l );
		for(ll i=0; i<n; i++)
		{
			ll x, y;
			scanf("%lld%lld", &x, &y);
			b[i] = cl(i, pll(x, y));
			a[i] = cl(i, pll(x, y));
		}
		sort(b, b+n, cmp);
		sort(a, a+n, cmp2);
		#ifdef DEBUG
		//for(ll i=0; i<n; i++) prllf("%d %d ",a[i].val.first, a[i].val.second);
		//printf("\n");
		#endif
		for(ll i=0; i<n; i++)
		{
			for(ll j=0; j<n; j++) if(a[i].idx == b[j].idx)
			{
				a2b[i] = j;
				b2a[j] = i;
				break;
			}
		}
		ll ans = 0;
		ll result = 0;
		for(ll i=0; i<n-1; i++)
		{
			for(ll j=i+1; j<n; j++) 
			{
				vis[b2a[j]] = false;
				sel[b2a[j]] = false;
			}
			vis[b2a[i]] = true;
			sel[b2a[i]] = true;
			ll sum = b[i].val.first;
			ll k = 0;
			ans = 1;
			for(ll j=n-1; j>=i+1; j--)
			{
				if(sel[b2a[j]]) sum += b[j].val.second - b[i].val.second;
				else 
				{
					sum += b[j].val.first + b[j].val.second - b[i].val.second;
				ans++;
				}
				vis[b2a[j]] = true;
				sel[b2a[j]] = true;
				if(sum > l) goto recover;
				for(; k<n; k++)
				{
					if(vis[k]) continue;
					if(sum + a[k].val.first <= l) 
					{
						ans++;
						sum += a[k].val.first;
						sel[k] = true;
					}
					else break;
				}
				if(ans > result) 
				{
					result = ans;
					//if(ans == 4) printf("??\n");
				}
				recover:
				sum -= b[j].val.first + b[j].val.second - b[i].val.second;
				sel[b2a[j]] = false;
				ans--;
				
			}
		}
		if(result <= 1)
			for(ll i=0; i<n; i++) if(a[i].val.first <= l)
			{
				result = 1;
				break;
			}
		printf("%d\n", result);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
