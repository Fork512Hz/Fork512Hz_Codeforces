#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<functional>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long ll;
typedef long long i64;
//#define DEBUG

//#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 100100;
#endif
const ll V = 5001000;

// Shu lian pou fen =======================================
//struct node
//{
//	int id, pa, depth, subsize, heavych, dfn, top, subright;
//	vector<int> conn;	
//	node(int x): id(x){
//	}
//	
//	int predfs(int parent);
//	void postdfs(int parent, int t);
//};
//vector<node> tree;
//int d, cnt;
//int node::predfs(int parent)
//{
//	pa = parent;
//	depth = d;
//	
//	heavych = -1;
//	int maxsize = -1;
//	subsize = 1;
//	d++;
//	
//	for(int i: conn) if(i != parent)
//	{
//		int tmp = tree[i].predfs(id);
//		subsize += tmp;
//		if(tmp > maxsize)
//		{
//			maxsize = tmp;
//			heavych = i;
//		}
//	}
//	d--;
//	return subsize;
//}
//void node::postdfs(int parent, int t)
//{
//	top = t;
//	dfn = cnt;
//	cnt++;
//	//rnk[dfn] = id;
//	if(heavych != -1)
//	{
//		tree[heavych].postdfs(id, t);
//		for(int i: conn) if(i != parent && i != heavych)
//			tree[i].postdfs(id, i);
//	}
//	subright = cnt-1;
//}
//
//void shulianpoufen(vector<node> &tree, int root)
//{
//	d = 0;
//	tree[root]. predfs(-1);
//	cnt = 1;
//	tree[root]. postdfs(-1, root);
//	cnt = 1;
//}


//void link(int u, int v)
//{
//	tree[u].conn.push_back(v);
//	tree[v].conn.push_back(u);
//}
// =======================================

int phi[V], depth[V];
int lca(int p, int q)
{
	int x=p, y=q;
	while(x != y)
	{
		if(depth[x] < depth[y]) swap(x, y);
		x = phi[x];
	}
	return x;
}
//Euler's sieve
vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            phi[i] = i-1;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
            	phi[i * p] = phi[i] * p;
                break;
            }
            else
            	phi[i * p] = phi[i] * phi[p];
        }
    }
}

// Segment tree template from jiangly ========
template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};
// YOUR CODE HERE
struct Info {
    i64 sum = 0;
    i64 lca = 0x7fffffff;
};
Info operator+(Info a, Info b) {
    Info c;
    c.sum = a.sum + b.sum;
    if(a.lca == 0x7fffffff) c.lca = b.lca;
    else if(b.lca == 0x7fffffff) c.lca = a.lca;
    else c.lca = lca(a.lca, b.lca);
    return c;
}
//=====================================================
int pv[N], nx[N];
vector<Info> a;
void deleteLL(int x)
{
	//Delete node from linked list
	if(x > 0)
		nx[pv[x]] = nx[x];
	pv[nx[x]] = pv[x];
}
int find(int x)
{
	if(a[x].lca != 1) return x;
	int t = find(nx[x]);
	nx[x] = t;
	return t;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
	int n, q;
	scanf("%d%d", &n, &q);
	int v = -1;
	for(int i=0; i<n; i++)
	{
		int x;
		scanf("%d", &x);
		a.push_back({0, x});
		v = max(v, x);
	}
	sieve(v);
	depth[1] = 0;
	for(int i=2; i<=v; i++)
		depth[i] = depth[phi[i]] + 1;
	for(int i=0; i<n; i++)
		a[i].sum = depth[a[i].lca];
	pv[0] = -1;
	nx[n] = -1;
	pv[n] = n-1;
	for(int i=0; i<n; i++)
	{
		pv[i] = i-1;
		nx[i] = i+1;
	}
	for(int i=1; i<=n; i++) 
		if(a[i].lca == 1) deleteLL(i);
		
	SegmentTree<Info> sgt(a);
	
	for(int t=0; t<q; t++)
	{
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if(op == 2)
		{
			Info ans = sgt.rangeQuery(l-1, r);
			printf("%d\n", ans.sum - depth[ans.lca] * (r+1-l));
		}
		else
		{
			l--;
			int k = l;
			for(;;)
			{
				k = find(k);
				if(k >= r) break;
				Info& cur = a[k];
				cur.lca = phi[cur.lca];
				cur.sum --;
				if(cur.lca == 1)
					deleteLL(k);
				sgt.modify(k, cur);
				k++;
			}
		}
	}
	
 	return 0;
}
