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

#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 200100;
#endif
pii a[N], b[N];
ll ans[N];
bool cmp(pii x, pii y)
{
	return x.second < y.second;
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
		for(int i=0; i<n; i++)
		{
			ll x;
			scanf("%lld", &x);
			a[i] = pii(i, x);
		}
		sort(a, a+n, cmp);
		for(int i=0; i<n; i++)
			b[i] = a[i];
		a[n] = pii(n, 1e12);
		int l = 0, r = 0;
		while(r < n)
		{
			while((a[r].second ^ a[l].second) < 4) 
				r++;
			sort(b+l, b+r);
			for(int i=l; i<r; i++)
				ans[b[i].first] = a[i].second;
			l = r;
		}
		for(int i=0; i<n; i++)
			printf("%lld ", ans[i]);
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
