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
const long long N = 500100;
#endif
inline ll dist(ll x, ll y)
{
	return x*x + y*y;
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
		ll n;
		scanf("%lld", &n);
		ll x = 0, y = n;
		ll ans = 0;
		while(y > 0)
		{
			ll d2 = dist(x, y);
			if(d2 >= n*n && d2 < (n+1) * (n+1))
				ans++;
			if(dist(x+1, y) >= (n+1) * (n+1))
				y--;
			else
				x++;
		}
		printf("%lld\n", ans<<2);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
