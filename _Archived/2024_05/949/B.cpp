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
const long long N = 500100;
#endif
// const ll M = 998244353;

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		ll n, m;
		scanf("%lld%lld", &n, &m);
		ll l, r;
		l = max(0ll, n-m);
		r = n+m;
		ll i = 0;
		ll ans = 0;
		while(r)
		{
			if(r-l > 0 || (l % 2))
				ans |= (1<<i);
			l >>= 1;
			r >>= 1;
			i++;
		}
		printf("%lld\n", ans);
    }
 	return 0;
}
