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
struct seg{
	int id, l, r, v;
	seg(){
	}
	seg(int w, int  x, int y, int z):
		id(w), l(x), r(y), v(z){
		}
};
struct edge{
	int l, r, w;
};
class cmp{
	public:
    bool operator()(seg x, seg y)const
	{
		if(x.v != y.v)  return x.v < y.v;
		return x.id < y.id;
	}
};
bool cmp2(pii x, pii y)
{
	if(x.first != y.first) return x.first < y.first;
	return x.second < y.second;
}
bool cmp3(edge x, edge y)
{
	return x.w < y.w;
}
int bcj[N]; 
seg a[N];
int find(int x)
{
	if(bcj[x] == -1) return x;
	int t = find(bcj[x]);
	bcj[x] = t;
	return t;
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
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
		{
			int l, r, p;
			scanf("%d%d%d", &l, &r, &p);
			a[i] = seg(i, l, r, p);
		}
		//sort(a.begin(), a.end(), cmp);
		vector<pii> points;
		for(int i=1; i<=n; i++)
		{
			points.push_back({a[i].l, -i});
			points.push_back({a[i].r, i});
		}
		sort(points.begin(), points.end(), cmp2);
		int m = points.size();
		set<seg, cmp> sweep;
		vector<edge> edges;
		for(int i=0; i<m; i++)
		{
			pii& cur = points[i];
			if(cur.second < 0)
			{
				//const seg tmp = a[-cur.second];
				auto it = (sweep.insert(a[-cur.second])).first;
				if(it != sweep.begin())
				{
					it--;
					int s = -cur.second;
					int t = it->id;
					edges.push_back({s, t, a[s].v - a[t].v});
					it++;
				}
				it++;
				if(it != sweep.end())
				{
					int s = -cur.second;
					int t = it->id;
					edges.push_back({s, t, a[t].v - a[s].v});
				}
			}
			else
			{
				sweep.erase(a[cur.second]);
			}
		}
		ll ans = 0;
		int cnt = 0;
		sort(edges.begin(),edges.end(), cmp3);
		memset(bcj, 0xff, sizeof(int) * (n+5));
		for(edge i: edges)
		{
			if(find(i.l) != find(i.r))
			{
				ans += (ll) i.w;
				cnt++;
				bcj[find(i.l)] = find(i.r);
			}
			if(cnt == n-1) break;
		}
		if(cnt != n-1) printf("-1\n");
		else printf("%lld\n", ans);
    }
 	return 0;
}
