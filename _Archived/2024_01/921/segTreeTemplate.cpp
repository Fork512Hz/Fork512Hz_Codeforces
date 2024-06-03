#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 500100;
#endif
const ll M = 998244353;
struct node{
	ll id, l, r, mid, val, lz, lz2, lch, rch;
	node(): id(-1), l(-1), r(-1), 
			mid(-1), val(0), lz(0), 
			lch(0), rch(0)
	{
	}
	ll Init(ll x, ll lb, ll rb);
	void lazy(ll x, ll y);
	ll update(ll lb, ll rb, ll k1, ll k2);
	ll query(ll lb, ll rb);
};
node segTree[N<<2];
ll a[N];
int n, m;
ll node::Init(ll x, ll lb, ll rb)
{
	id = x;
	l = lb;
	r = rb;
	mid = (l+r) >> 1;
	if(lb > rb) return 0;
	if(lb == rb)
	{
		val = a[lb];
		return val;
	}
	lch = id << 1;
	rch = lch+1;
	val = segTree[lch].Init(lch, lb, mid) 
	    + segTree[rch].Init(rch, mid+1, rb);
	val %= M;
	return val;
}
void node::lazy(ll x, ll y)
{
	val = (val*x) % M;
	val += (r-l+1) * y;
	val %= M;
	lz = lz*x % M;
	lz2 = (lz2*x + y)% M;
}
ll node::update(ll lb, ll rb, ll k1, ll k2)
{
	if(lb > rb) return 0;
	if(lb == l && rb == r)
	{
		this->lazy(k1, k2);
		return val;
	}
	if(lz)
	{
		segTree[lch].lazy(lz, lz2);
		segTree[rch].lazy(lz, lz2);
		lz = 0;
		lz2 = 0;
	}
	if(rb <= mid) val = segTree[rch].val + segTree[lch].update(lb, rb, k1, k2);
	else if(lb > mid) val = segTree[lch].val + segTree[rch].update(lb, rb, k1, k2);
	else val = segTree[lch].update(lb, mid, k1, k2)
	         + segTree[rch].update(mid+1, rb, k1, k2);
    val %= M;
	return val;
}
ll node::query(ll lb, ll rb)
{
	if(lb > rb) return 0;
	if(lb == l && rb == r)
		return val;
	ll ans = 0;
	if(lz)
	{
		segTree[lch].lazy(lz, lz2);
		segTree[rch].lazy(lz, lz2);
		lz = 0;
		lz2 = 0;
	}
	if(rb <= mid) ans = segTree[lch].query(lb, rb);
	else if(lb > mid) ans = segTree[rch].query(lb, rb);
	else ans = segTree[lch].query(lb, mid)
	         + segTree[rch].query(mid+1, rb);
	ans %= M;
	return ans;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    cin >> n >> m;
    for(int i=0; i<n; i++) scanf("%lld", &a[i]);
    node &root = segTree[1];
    root.Init(1, 0, n-1);
    for(int i=0; i<m; i++)
    {
    	int op, x, y, k1, k2;
    	scanf("%d", &op);
    	if(op == 1)
    	{
    		scanf("%d%d", &x, &y);
			y--;
    		printf("%lld\n", root.query(x, y));
		}
		else
		{
			scanf("%d%d%d%d", &x, &y, &k1, &k2);
			y--;
			root.update(x, y, k1, k2);
		}
	}
 	return 0;
}
