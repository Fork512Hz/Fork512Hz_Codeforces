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
ll po(ll b, ll e)
{
	if(e == 0) return 1;
	if(e == 1) return b;
	ll ans = po(b, e>>1);
	ans = ans*ans % M;
	if(e%2) ans = ans*b % M;
	return ans;
}

ll cb(ll n, ll m)
{
	ll rt = 1, qt = 1;
	for(int i=n; i>n-m; i--) 
		rt = rt*i % M;
	for(int i=1; i<=m; i++)
		qt = qt*i % M;
	rt = rt * po(qt, M-2) % M;
	return rt;
}
inline ll f(ll no, ll space)
{
	return cb(no+space, no);
}
struct node{
	int l, r, val;
	node(){
		
	}
	node(int x, int y, int z):
		l(x), r(y), val(z)
		{
		}
};
node tree[N];
node list[N];
void nlrInsert(int x, int pr, int su)
{
	list[x] = node(pr, su, tree[x].val);
	list[pr].r = x;
	list[su].l = x;
	if(tree[x].l != -1) nlrInsert(tree[x].l, pr, x);
	if(tree[x].r != -1) nlrInsert(tree[x].r, x, su);
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
		int n, C;
		scanf("%d%d", &n, &C);
		for(int i=0; i<n; i++)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			tree[i+1] = node(x, y, z); 
		}
		list[0] = node(-1, n+1, 1);
		list[n+1] = node(0, n+2, C);
		nlrInsert(1, 0, n+1);
		int k1=0, k2 = 0;
		int left = 0;
		ll ans = 1;
		for(int right=0; k2!=n+2; right++, k2 = list[k2].r)
		{
			if(list[k2].val != -1 && right != left)
			{
				ll no = right - left -1;
				ll space = list[k2].val - list[k1].val;
				ans *= f(no, space);
				ans %= M;
				k1 = k2;
				left = right;
			}
			
		}
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
