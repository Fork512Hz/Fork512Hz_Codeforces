#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>
#include<vector>
typedef long long ll;
using namespace std;
typedef pair<ll, ll> pii;
//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1010;
#endif
#ifndef DEBUG
const ll N = 1010;
#endif
ll n, m, s[N], dist[N*1025], mat[N][N];
bool vis[N*1025];
vector<ll> graph[N];
class Cmp {
public:
	bool operator()(const pii x, const pii y) const{
		return x.second > y.second;
	}
};

inline ll f(ll x, ll y)
{
	return (x<<10) + y;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    #endif
    #ifdef MULTI
    ll z;
    cin >> z;
    while(z--){
		scanf("%lld%lld", &n, &m);
		for(ll i=1; i<=n; i++) graph[i].clear();
		for(int i=1; i<=n; i++) 
			memset(mat[i], 0x7f, sizeof(ll) * (n+1) + 5);
		for(ll i=0; i<m; i++)
		{
			ll x, y, w;
			scanf("%lld%lld%lld", &x, &y, &w);
		    graph[x].push_back(y);
		    graph[y].push_back(x);
		    mat[x][y] = min(mat[x][y], w);
		    mat[y][x] = min(mat[y][x], w);
		}
		memset(dist, 0x7f, sizeof(ll) * (n+1)*1024 + 5 );
		memset(vis, 0, sizeof(bool) * (n+1)*1024 + 5 );
		for(ll i=1; i<=n; i++) scanf("%lld", &s[i]);
		priority_queue<pii, vector<pii>, Cmp> dijk;
		dist[f(1, s[1])] = 0;
		dijk.push(pii(f(1, s[1]), 0));
		while(!dijk.empty())
		{
			ll cur = dijk.top().first;
			ll len = dijk.top().second;
			dijk.pop();
			if(vis[cur]) continue;
			vis[cur] = 1;
			ll ii = cur >> 10;
			ll ss = cur % 1024;
			for(ll i: graph[ii])
			{
				ll tt = f(i, min(s[i], ss));
				if(dist[tt] > ss * mat[ii][i] + len)
				{
					dist[tt] = ss * mat[ii][i] + len;
					dijk.push(pii(tt, ss * mat[ii][i] + len));
					//printf("%lld %lld %lld\n", i, ss, dist[tt]);
				}
			}
		}
		ll ans = 0x7f7f7f7f7f7f7f7f;
		for(ll i=f(n, 1); i<=f(n, 1000); i++) 
			ans = min(ans, dist[i]);
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
