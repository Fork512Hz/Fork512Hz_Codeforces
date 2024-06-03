#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<functional>
#include<map>
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
ll a[N];
const ll B = 1000007;
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    ll z;
    //z = 1;
    cin >> z;
    while(z--){
		ll n;
		scanf("%lld", &n);
		for(int i=0; i<n; i++)
			scanf("%lld", &a[i]);
		ll ans = 0;
		map<ll, ll> adj, gap, tri;
		for(ll i=1; i<n-2; i++) 
		{
			auto it = adj.find(a[i]*B + a[i+1]);
			if(it == adj.end())
				adj[a[i]*B + a[i+1]] = 1;
			else{
				ans += 2* (*it).second;
				(*it).second ++;
			}
		}
		auto it = adj.find(a[0]*B + a[1]);
		if(it != adj.end())
			ans += (*it).second;
		it = adj.find(a[n-2]*B + a[n-1]);
		if(it != adj.end())
			ans += (*it).second;
		for(ll i=0; i<n-2; i++) 
		{
			auto it = gap.find(a[i]*B + a[i+2]);
			if(it == gap.end())
				gap[a[i]*B + a[i+2]] = 1;
			else{
				ans += (*it).second;
				(*it).second ++;
			}
			
		}
		for(int i=0; i<n-2; i++) 
		{
			ll tmp = a[i]*B*B + a[i+1]*B + a[i+2];
			auto it = tri.find(tmp);
			if(it == tri.end())
				tri[tmp] = 1;
			else{
				ans -= 3*(*it).second;
				(*it).second++;
			}
		}
		printf("%lld\n", ans);
		
    }
 	return 0;
}
