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
const long long N = 200100;
#endif
// const ll M = 998244353;
ll a[N], b[N];
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
		scanf("%lld", &n);
		for(ll i=0; i<n; i++)
			scanf("%lld", &a[i]);
		for(ll i=0; i<=n; i++)
			scanf("%lld", &b[i]);
		ll ans = 0;
		ll p = b[n];
		bool fl = 1;
		for(ll i=0; i<n; i++)
		{
			ans += abs(a[i]-b[i]);
			if((a[i]-p) * (b[i]-p) < 0) fl = 0;
		}
		ll t = 0x7fffffffffffffff;
		if(fl) for(int i=0; i<n; i++)
		{
			t = min(t, min(abs(p - a[i]), abs(p - b[i])) );
		}
		else t = 0;
		printf("%lld\n", ans + t + 1);
    }
 	return 0;
}
