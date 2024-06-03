#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long ll;
//#define DEBUG

//#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif
const ll neginf = 0xc0c0c0c0c0c0c0c0;
struct node{
	int id, l, r, mid, lch, rch;
	ll val, mod;
	bool lazy;
	node(){
	}
	node(int i, int x, int y):
		id(i), l(x), r(y), mid((x+y) >> 1), 
		lch(-1), rch(-1),
		val(neginf), lazy(0), mod(0){}
	ll build();
	ll update(ll x, int lb, int rb);
};

ll a[N], b[N], pfs[N];
int cnt;
node segTree[N<<2];

ll node::build()
{
	if(l == r)
	{
		val = pfs[l];
		return val;
	}
	cnt++; lch = cnt;
	segTree[cnt] = node(cnt, l, mid);
	val = max(val, segTree[cnt].build());
	cnt++; rch = cnt;
	segTree[cnt] = node(cnt, mid+1, r);
	val = max(val, segTree[cnt].build());
	return val;
}

ll node::update(ll x, int lb, int rb)
{
	if(lb == l && rb == r)
	{
		val += x;
		lazy = 1;
		mod += x;
		return val;
	}
	if(lazy)
	{
		segTree[lch].lazy = 1;
		segTree[lch].mod += mod;
		segTree[lch].val += mod;
		segTree[rch].lazy = 1;
		segTree[rch].mod += mod;
		segTree[rch].val += mod;
		lazy = 0;
		mod = 0;
	}
	if(rb <= mid)
		val = max(segTree[rch].val, segTree[lch].update(x, lb, rb));
	else if(lb >= mid+1)
		val = max(segTree[lch].val, segTree[rch].update(x, lb, rb));
	else
	{
		val = max(segTree[lch].update(x, lb, mid), segTree[rch].update(x, mid+1, rb));
	}
	return val;
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

    }
    #endif
	#ifndef MULTI
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
	for(int i=1; i<=n; i++) scanf("%lld", &b[i]);
	ll trash;
	for(int i=1; i<=n-1; i++) scanf("%lld", &trash);
	pfs[0] = 0;
	ll sumb = 0;
	for(int i=1; i<=n; i++) pfs[i] = pfs[i-1] + b[i] - a[i];
	for(int i=1; i<=n; i++) sumb += b[i];
	cnt = 0;
	segTree[0] = node(0, 1, n);
	segTree[0].build();
	
	for(int z=0; z<q; z++)
	{
		int p;
		ll x, y;
		scanf("%d%lld%lld%lld", &p, &x, &y, &trash);
		sumb += y - b[p];
		ll toupdate = (y-x) - (b[p] - a[p]);
		a[p] = x;
		b[p] = y;
		#ifdef DEBUG
		printf("----------\nUpdate %d: %d (%d,%d) sumb=%lld toupdate=%lld\n", z+1, p, x, y, sumb, toupdate);
		#endif
		segTree[0].update(toupdate, p, n);
		printf("%lld\n", sumb - max(0ll, segTree[0].val));
		#ifdef DEBUG
		for(int i=0; i<=cnt; i++)
		{
			node &cu = segTree[i];
			printf("%d: [%d,%d] val=%lld mod=%lld lazy=%d\n", cu.id, cu.l, cu.r, cu.val, cu.mod, cu.lazy );
		}
		#endif
		
	}
	#endif
 	return 0;
}
