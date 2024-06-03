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
const long long N = 100100;
#endif
// const ll M = 998244353;
struct query{
	ll id, l, r;
};
ll a[N], res[N];
query q[N];
const ll V = 1050000;
ll bucket[V];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stderr);
    #endif
    ll z;
    z = 1;
    //cin >> z;
    while(z--){
		ll n, m, k;
		scanf("%lld%lld%lld", &n, &m, &k);
		a[0] = 0;
		for(ll i=1; i<=n; i++)
		{
			ll x;
			scanf("%lld", &x);
			a[i] = a[i-1] ^ x;
		}
		for(ll i=0; i<m; i++)
		{
			ll x, y;
			scanf("%lld%lld", &x, &y);
			y++; x--;
			q[i] = {i,x, y};
		}
		const ll BLOCK = ceil(sqrt(n));
		auto modui = [&] (query x, query y)
		{
			if(x.l / BLOCK != y.l / BLOCK)
				return x.l / BLOCK < y.l / BLOCK;
			if((x.l / BLOCK) % 2)return x.r > y.r;
			else return x.r < y.r;		
		};
		sort(q, q+m, modui);
		ll lb = 0, rb = 0, ans = 0;
		for(ll i=0; i<m; i++)
		{
			ll x = q[i].l;
			ll y = q[i].r;
			for(; rb<y; rb++)
			{
				ans += bucket[k^a[rb]];
				bucket[a[rb]] ++;
			}
			for(; lb>x; lb--)
			{
				ans += bucket[k^a[lb-1]];
				bucket[a[lb-1]] ++;
			}
			for(; rb>y; rb--)
			{
				bucket[a[rb-1]] --;
				ans -= bucket[k^a[rb-1]];
			}
			for(; lb<x; lb++)
			{
				bucket[a[lb]] --;
				ans -= bucket[k^a[lb]];
			}
			res[q[i].id] = ans;
		}
		for(ll i=0; i<m; i++)
			printf("%lld\n", res[i]);
    }
 	return 0;
}
