#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<set>
typedef long long ll;

//#define DEBUG

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 300100;
#endif
using namespace std;

struct node
{
	ll id, l, r, mid, val, firstLz, dLz;
	node(): id(-1), l(-1), r(-1), mid(-1), val(-1), firstLz(-1), dLz(-1){
	}
	ll _init_(int id, int lb, int rb);
	ll query(int lb, int rb);
	void lazy(ll first, ll d);
	ll update(int lb, int rb, ll first, ll d);
	
};

ll h[N], a[N];
set<ll> harbors;
node segTree[N<<2];

inline ll dengcha(ll l, ll r, ll first, ll d)
{
	ll last = first + (r-l)*d;
	return (first+last)*(r-l+1)/2;
}

ll node::_init_(int id_, int lb, int rb)
{
	id = id_;
	l = lb;
	r = rb;
	mid = (l+r) >> 1;
	if(lb == rb)
	{
		if(a[lb]) val = 0;
		else
		{
			auto iter = harbors.upper_bound(lb);
			ll dist = (*iter) - lb;
			iter--;
			val = dist * a[*iter];
		}
	}
	else
	{
		val = segTree[id<<1]. _init_(id<<1, lb, mid) 
		    + segTree[(id<<1)|1]. _init_((id<<1)|1, mid+1, rb);
	}
	return val;
}

void node::lazy(ll first, ll d)
{
	firstLz = first;
	dLz = d;
	val = dengcha(l, r, first, d);
}

ll node::update(int lb, int rb, ll first, ll d)
{
	if(lb > rb) return 0;
	if(lb == l && rb == r)
	{
		this->lazy(first, d);
		return val;
	}
	node &lch = segTree[id<<1];
	node &rch = segTree[(id<<1)|1];
	if(dLz != -1)
	{
		lch.lazy(firstLz, dLz);
		rch.lazy(firstLz + dLz*(mid+1 - l), dLz);
		firstLz = -1;
		dLz = -1;
	}
	if(rb <= mid) val = rch.val + lch.update(lb, rb, first, d);
	else if(lb >= mid+1) val = lch.val + rch.update(lb, rb, first, d);
	else val = lch.update(lb, mid, first, d)
			 + rch.update(mid+1, rb, first + d*(mid+1 - lb),d);
	return val;
}

ll node::query(int lb, int rb)
{
	if(lb > rb) return 0;
	if(lb == l && rb == r) return val;
	node &lch = segTree[id<<1];
	node &rch = segTree[(id<<1)|1];
	if(dLz != -1)
	{
		lch.lazy(firstLz, dLz);
		rch.lazy(firstLz + dLz*(mid+1 - l), dLz);
		firstLz = -1;
		dLz = -1;
	}
	if(rb <= mid) return segTree[id<<1].query(lb, rb);
	else if(lb >= mid+1) return segTree[(id<<1|1)].query(lb, rb);
	else return segTree[id<<1].query(lb, mid)
			  + segTree[(id<<1)|1].query(mid+1, rb);
}

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=0; i<m; i++) scanf("%lld", &h[i]);
	node &root = segTree[1];
	for(int i=0; i<m; i++)
	{
		ll x;
		harbors.insert(h[i]);
		scanf("%lld", &x);
		a[h[i]] = x;
	}
    root._init_(1, 1, n);
    for(int i=0; i<q; i++)
    {
    	ll op, x, y;
    	scanf("%lld%lld%lld", &op, &x, &y);
    	if(op==1)
    	{
    		a[x] = y;
    		harbors.insert(x);
    		auto Iter = harbors.upper_bound(x);
    		auto rh = *(Iter);
    		Iter --; Iter --;
    		auto lh = *(Iter);
    		root.update(lh+1, x-1, a[lh]*(x-lh-1), -a[lh]);
    		root.update(x+1, rh-1, y*(rh-x-1), -y);
    		root.update(x, x, 0, 0);
		}
		else printf("%lld\n", root.query(x, y));
	}
	
	
 	return 0;
}
