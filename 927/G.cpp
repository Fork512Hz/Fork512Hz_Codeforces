#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;
typedef pair<ll, int> pll;
//#define DEBUG
#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 100100;
#endif
inline bool cmp(pll x, pll y)
{
	return x.first > y.first;
}
ll n, m, H, h0[N], elev[N], ans[N];
vector<ll> graph[N];
priority_queue<pll, vector<pll>, greater<>> dijk;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll g = exgcd(b, a%b, y, x);
    y -= a/b * x;
    return g;
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
		scanf("%lld%lld%lld", &n, &m, &H);
		memset(ans, 0xff, sizeof(ll) * (n+3));
		for(int i=1; i<=n; i++) graph[i].clear();
		
		for(int i=1; i<=n; i++) scanf("%lld", &h0[i]);
		for(int i=1; i<=n; i++) scanf("%lld", &elev[i]);
		for(int i=0; i<m; i++)
		{
			ll x, y;
			scanf("%lld%lld", &x, &y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		
		dijk.push(pll(0, 1));
		while(! dijk.empty())
		{
			int id = dijk.top().second;
			ll dist = dijk.top().first;
			dijk.pop();
			if(ans[id] != -1) continue;
			ans[id] = dist;
			ll h1 = (h0[id] + (elev[id]%H) * (dist%H)) %H;
			for(int i: graph[id])
			{
				ll t, k;
				ll a = (elev[id] - elev[i] + H) %H;
				// Solve equation: (elev[id] - elev[i])*t - H*k = -(h[id] - h[i])
				// where h[i] is height of i at dist seconds.
				ll gcd = exgcd(a, H, t, k);
				ll dh = ((h0[i] + (elev[i]%H) * (dist%H)) %H - h1 + H) %H;
				if(dh % gcd != 0) continue;
				ll H2 = H/gcd;
				ll wait = (t * (dh/gcd) )% H2;
				wait = (wait + H2) % H2;
				dijk.push(pll(dist + wait +1, i));
			}
		}
		
		printf("%lld\n", ans[n]);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
