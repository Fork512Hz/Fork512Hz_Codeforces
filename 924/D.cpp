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
const ll N = 200100;
#endif
ll a[N];
ll n, b, x;
inline ll c2(ll x)
{
	return x*(x-1)/2;
}
inline ll sq(ll x)
{
	return x*x;
}
ll sepprod(ll x, ll par)
{
	ll d = x/par;
	ll r = x%par;
	return sq(d+1) * c2(r) + sq(d) * c2(par-r) + (d+1)*d * r*(par-r);
}
ll result(ll p)
{
	ll ans = 0;
	for(ll i=0; i<n; i++) ans+=sepprod(a[i], p);
	return ans*b - x*(p-1);
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    
    while(z--){
		
		ll rb = 0;
		scanf("%lld%lld%lld", &n, &b, &x);
		for(ll i=0; i<n; i++)
		{
			scanf("%lld", &a[i]);
			if(a[i] > rb) rb = a[i];
		}
    
	    ll maxrb = rb;
	    ll lb = 1;
	    while(lb < rb)
	    {
	    	ll mid = (lb+rb)/2;
	    	int flag = 0;
	    	ll val, vall, valr;
	    	val = result(mid);
	    	vall = mid==1? val-1: result(mid-1);
	    	valr = mid==maxrb? val-1: result(mid+1);
	    	if(vall > val && val > valr) rb = mid-1;
	    	else if(vall < val && val < valr)lb = mid+1;
	    	else
	    	{
	    		printf("%lld\n", val);
	    		goto out;
			}
		
		}
		printf("%lld\n", result(lb));
		out: ;
	}
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
