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
const ll M = 998244353;
struct node{
	int id, lch, rch, pa;
};
int l[N], r[N], pos[N];
ll unable[N];
node tree[N<<1];
vector<int> fix;
void fail()
{
	printf("0");
	exit(0);
}
void lnr(int x)
{
	if(tree[x].lch == -1 && tree[x].rch == -1)
		fix.push_back(x);
	if(tree[x].lch != -1) lnr(tree[x].lch);
	if(tree[x].rch != -1) lnr(tree[x].rch);
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    z = 1;
    //cin >> z;
    while(z--){
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i=0; i<m; i++) scanf("%d", &l[i]);
		for(int i=0; i<m; i++) scanf("%d", &r[i]);
		for(int i=1; i<=n; i++) 
		{
			pos[i] = i;
			tree[i] = {i, -1, -1, -1};
		}
		int top = n+1;
		for(int i=m-1; i>=0; i--)
		{
			node& lchild = tree[pos[l[i]]];
			node& rchild = tree[pos[r[i]]];
			if(lchild.pa != -1 || rchild.pa != -1)
				fail();
			tree[top] = {max(l[i], r[i]), pos[l[i]], pos[r[i]], -1};
			lchild.pa = top;
			rchild.pa = top;
			pos[max(l[i], r[i])] = top;
			top++;
		}
		int root = top-1;
		lnr(root);
		unable[fix.front()] ++;
		unable[fix.back()] ++;
		int segcnt = fix.size();
		for(int i=0; i<segcnt-1; i++)
			unable[max(fix[i], fix[i+1])] ++;
		for(int i=1; i<=n; i++)
			unable[i] += unable[i-1];
		ll ans = 1;
		segcnt++;
		for(int i=n; i>=1; i--) if(tree[i].pa == -1)
		{
			ans = (ans * (segcnt - unable[i])) % M;
			segcnt++;
		}
		printf("%lld\n", ans);
    }
 	return 0;
}
