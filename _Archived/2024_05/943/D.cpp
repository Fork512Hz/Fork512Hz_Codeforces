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
ll p[N];
ll a[N];
ll n, k;
ll solve(ll x)
{
	ll pos = x;
	ll sum, ans;
	ans = -1;
	sum = 0;
	for(int i=0; i<min(k, n); i++)
	{
		ans = max(ans, a[pos] * (k-i) + sum);
		sum += a[pos];
		pos = p[pos];
	}
	return ans;
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
		ll s1, s2;
		scanf("%lld%lld%lld%lld", &n, &k, &s1, &s2);
		for(int i=1; i<=n; i++)
			scanf("%lld", &p[i]);
		for(int i=1; i<=n; i++)
			scanf("%lld", &a[i]);
		ll ans1 = solve(s1);
		ll ans2 = solve(s2);
		if(ans1 > ans2) printf("Bodya\n");
		else if(ans1 == ans2) printf("Draw\n");
		else printf("Sasha\n");
    }
 	return 0;
}
