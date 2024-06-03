#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<functional>
#include<deque>
#include<set>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vll;
typedef long long ll;
typedef long long i64;

//#define DEBUG

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 2100;
#endif
// const ll M = 998244353;
ll a[N];
ll gcd(ll x, ll y)
{
	if(x>y) swap(x, y);
	ll t;
	while(x)
	{
		t = y%x;
		y=x; x=t;
	}
	return y;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		ll n;
		ll ans = 0;
		deque<ll> div;
		
		scanf("%lld", &n);
		for(ll i=0; i<n; i++) scanf("%lld", &a[i]);
		sort(a, a+n);
		const ll m = a[n-1];
		const double eps = 1e-9;
		for(ll i=0; i<n-1; i++) if(a[n-1] % a[i]) 
		{
			printf("%lld\n", n);
			goto fin;
		}
		
		
		for(ll i=floor(sqrt(m) + eps); i>=1; i--) if(m%i == 0)
		{
			div.push_front(i);
			if(i*i != m) div.push_back(m/i);
		}
		for(ll x: div)
		{
			ll cnt = 0;
			ll lcm = 1;
			for(int i=0; i<n; i++)
			{
				
				if(a[i] == x) goto breakcontinue;
				if(a[i] > x) break;
				if(x % a[i] == 0)
				{
					lcm = lcm*a[i] / gcd(lcm, a[i]);
					cnt++;
				}
			}
			if(lcm == x)
				ans = max(cnt, ans);
			breakcontinue:;
		}
		printf("%lld\n", ans);
		fin:;
    }
 	return 0;
}
