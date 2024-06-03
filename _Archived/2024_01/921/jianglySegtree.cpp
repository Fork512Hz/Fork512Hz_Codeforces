#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<functional>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long i64;
//#define DEBUG

//#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif
i64 M;

// Jiangly segtree lazy
template<class Info, class Tag>
class LazySegmentTree {
private:
    const int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    //Private modify:
    //p = node idx, [l, r] range of this node, x = , v = value
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    
    void half(int p, int l, int r) {
        if (info[p].act == 0) {
            return;
        }
        if ((info[p].min + 1) / 2 == (info[p].max + 1) / 2) {
            apply(p, {-(info[p].min + 1) / 2});
            return;
        }
        int m = (l + r) / 2;
        push(p);
        half(2 * p, l, m);
        half(2 * p + 1, m, r);
        pull(p);
    }
 
 
public:  
    LazySegmentTree(int n) : n(n), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}
    LazySegmentTree(std::vector<Info> init) : LazySegmentTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
    void half() {
        half(1, 0, n);
    }
};

constexpr i64 inf = 1E18;

struct Tag {
    i64 add = 0;
    i64 mul = 1;
    void apply(Tag t) {
    	mul = mul * t.mul % M;
        add = (add * t.mul + t.add) % M;
    }
};

struct Info {
    i64 sum = 0;
    i64 act = 0;
    
    void apply(Tag t) {
        sum = (sum * t.mul + t.add * act) % M;
    }
};

Info operator+(Info a, Info b) {
    Info c;
    c.sum = (a.sum + b.sum) % M;
    c.act = (a.act + b.act) % M;
    return c;
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
	scanf("%d%d%lld", &n, &q, &M);
	LazySegmentTree<Info, Tag> segTree(n);
	for(int i=0; i<n; i++)
	{
		i64 x;
		scanf("%lld", &x);
		segTree.modify(i, {x, 1});
		//printf("%lld %lld\n", segTree.rangeQuery(i, i+1).sum, segTree.rangeQuery(0, i+1).sum % M);
	}
	for(int i=0; i<q; i++)
	{
		i64 op, lb, rb;
		scanf("%lld%lld%lld", &op, &lb, &rb);
		if(op == 3)
		{
			printf("%lld\n", segTree.rangeQuery(lb-1, rb).sum % M);
		}
		else if(op == 2)
		{
			i64 v;
			scanf("%lld", &v);
			//printf("%lld %lld %lld\n", lb-1, rb, v);
			segTree.rangeApply(lb-1, rb, {v, 1});
		}
		else
		{
			i64 v;
			scanf("%lld", &v);
			//printf("%lld %lld %lld\n", lb-1, rb, v);
			segTree.rangeApply(lb-1, rb, {0, v});
		}
	}
	#endif
 	return 0;
}
