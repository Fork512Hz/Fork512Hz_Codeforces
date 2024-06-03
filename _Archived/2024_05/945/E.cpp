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
ll a[N];
inline ll tri(ll x)
{
	return x * (x+1) / 2;
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
		scanf("%lld", &n);
		for(int i=1; i<=n; i++)
			scanf("%lld", &a[i]);
		ll maxx, miny;
		ll maxdiff = 0, mindiff = n;
		ll eq = n*2;
		ll tmp = -1;
		for(ll i=1; i<=n; i++) if(a[i] != i)
		{
			maxdiff = max(maxdiff, i);
			mindiff = min(mindiff, i);
			if(eq == n*2)
			{
				eq = 1;
				tmp = i + a[i];
			}
			else if(eq == 1)
			{
				if(i + a[i] != tmp) eq = 0;
			}
		}
		maxx = mindiff+n;
		miny = maxdiff+1;
		ll ans = (2*n+1-miny) *maxx - tri(maxx-miny+1);
		printf("%lld\n", ans+eq);
    }
 	return 0;
}
