#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<utility>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 300100;
#endif
const ll inf = 1000010001;

bool cmp(pair<int, int> x, pair<int, int> y)
{
	if(x.first > y.first) return true;
	if(x.first < y.first) return false;
	return x.second < y.second;
}
int t=0;
struct node{
	int l, r, mid, val, pos, lch, rch, lz;
	node()
	{
	}
	void init()
	{
		l = -1;
		r = -1;
		mid = -1;
		val = -1;
		pos = -1;
		lch = -1;
		rch = -1;
		lz = 0;
	}
};
node segTree[4*N];
int a[N];
pair<int, int> build(int x, int lb, int rb)
{
	node &c = segTree[x];
	c.l = lb;
	c.r = rb;
	c.mid = (lb+rb)/2;
	if(lb == rb)
	{
		c.pos = lb;
		c.val = a[c.pos] + lb;
		return pair<int, int> (c.val, c.pos);
	}
	else 
	{
		t++;
		c.lch = t;
		pair<int, int> t1 = build(t, lb, c.mid);
		t++;
		c.rch = t;
		pair<int, int> t2 = build(t, c.mid+1, rb);
		if (cmp(t1, t2))
		{
			c.val = t1.first;
			c.pos = t1.second;
		}
		else
		{
			c.val = t2.first;
			c.pos = t2.second;
		}
		return pair<int, int> (c.val, c.pos);
	}
}

pair<int, int> modify(int x, int lb, int rb, int v)
{
	node &c = segTree[x];
	if(lb > rb) return pair<int, int> (-1, -1);
	if(lb == c.l && rb == c.r)
	{
		c.val -= v;
		c.lz += v;
		return pair<int, int> (c.val, c.pos);
	}
	if(c.lz != 0)
	{
		segTree[c.lch].val -= c.lz;
		segTree[c.lch].lz = c.lz;
		segTree[c.rch].val -= c.lz;
		segTree[c.rch].lz = c.lz;
		c.lz = 0;
	}
	pair<int, int> t1, t2;
	if(lb >= c.mid+1) 
	{
		t1 = pair<int, int> (segTree[c.lch].val, segTree[c.lch].pos);
		t2 = modify(c.rch, lb, rb, v);
	}
	else if(rb <= c.mid)
	{
		t1 = modify(c.lch, lb, rb, v);
		t2 = pair<int, int> (segTree[c.rch].val, segTree[c.rch].pos);
	}
	else
	{
		t1 = modify(c.lch, lb, c.mid, v);
		t2 = modify(c.rch, c.mid+1, rb, v);
	}
	if (cmp(t1, t2))
	{
		c.val = t1.first;
		c.pos = t1.second;
	}
	else
	{
		c.val = t2.first;
		c.pos = t2.second;
	}
	return pair<int, int> (c.val, c.pos);
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
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		t = 1;
		build(1, 1, n);
		for(int i=1; i<=n; i++) 
		{
			printf("%d ", segTree[1].val);
			int p = segTree[1].pos;
			int vv = segTree[1].val;
			modify(1, p, p, vv);
			modify(1, p+1, n, 1);
		}
		printf("\n");
		for(int i=1; i<=t; i++ ) segTree[i].init();
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
