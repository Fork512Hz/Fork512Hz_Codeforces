#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long ll;
#define DEBUG

#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 400100;
#endif

struct edge{
	ll dst, w;	
	edge(){
	}
	edge(ll x, ll y):
		dst(x), w(y){
		}
};
class cmp_dijk{
	public:
	bool operator()(pii x, pii y)
	{
		return x.second > y.second;
	}
};

vector<ll> dijkstra(vector<edge> graph[], const ll n, ll origin)
{
	priority_queue<pii, vector<pii>, cmp_dijk> pq;
	vector<ll> dist(n);
	pq.push(pii(origin, 0));
	for(ll i=0; i<n; i++)
		dist[i] = 0x7fffffffffffffff;
	while(!pq.empty())
	{
		ll cur = pq.top().first;
		ll d = pq.top().second;
		pq.pop();
		if(d > dist[cur]) continue;
		
		dist[cur] = d;
		for(edge j: graph[cur]) if(dist[j.dst] > j.w + d)
		{
			pq.push(pii(j.dst, j.w + d));
			dist[j.dst] = j.w + d;
		}
	}
	return dist;
}
ll v[N];
ll dist[N];
vector<edge> graph[N<<1];
pii a[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    ll z;
    cin >> z;
    while(z--){
		ll x, n, m;
		scanf("%lld%lld", &n, &m);
		for(ll i=0; i<n*(m+1); i++) graph[i].clear();
		for(ll i=0; i<n; i++) 
		{
			scanf("%lld", &x);
			for(ll j=0; j<m; j++)
			{
				graph[j*n + i].push_back(edge(m*n + i, x));
				graph[m*n + i].push_back(edge(j*n + i, 0));
			}
		}
		for(ll i=0; i<n; i++)
			for(ll j=0; j<m; j++)
			{
				ll x;
				scanf("%lld", &x);
				a[j*n + i] = pii(x, i);
			}
		for(ll i=0; i<m; i++)
		{
			
			sort(a+i*n, a+(i+1)*n);
			for(ll j=0; j<n-1; j++)
			{
				graph[n*i + a[i*n+j].second].push_back(edge(n*i + a[i*n+j+1].second, 0));
				graph[n*i + a[i*n+j+1].second].push_back(edge(n*i + a[i*n+j].second, a[i*n+j+1].first - a[i*n+j].first));
			}
		}
		vector<ll> anss = dijkstra(graph, n*(m+1), n*m);
		printf("%lld\n", anss[n*(m+1) -1]);
		
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
