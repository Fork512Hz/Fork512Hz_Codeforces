#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<queue>
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
const long long N = 1010;
#endif
ll a[N][N];
vector<ll> pq[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n, k;
		scanf("%d%d", &n, &k);
		for(int i=1; i<=n; i++)
			for(int j=i; j<=n; j++)
				scanf("%lld", &a[i][j]);
		for(int i=0; i<=n; i++) pq[i].clear();
		pq[0].push_back(0);
		int idx[N], siz[N];
		siz[0] = 1;
		for(int i=1; i<=n; i++)
		{
			memset(idx, 0, sizeof(int) * i);
			priority_queue<pii> auxpq;
			for(int j=i-1; j>=0; j--) if(!pq[j].empty())
			{
				ll t = pq[j][0];
				auxpq.push(pii(t + a[j+2][i], j));
			}
			auxpq.push(pii(a[1][i], -1));
			for(int j=1; j<=k; j++)
			{
				if(auxpq.empty()) break;
				pii t = auxpq.top();
				auxpq.pop();
				pq[i].push_back(t.first);
				if(t.second != -1 && idx[t.second] < siz[t.second]-1)
				{
					idx[t.second] ++;
					ll t2 = pq[t.second][idx[t.second]];
					auxpq.push(pii(t2 + a[t.second+2][i], t.second));
				}
			}
			siz[i] = pq[i].size();
		}
		
		for(ll i: pq[n]) printf("%lld ", i);
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
