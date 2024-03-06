#include<cstdio>
#include<utility>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;
typedef  pair<int, int> pll;
//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 200100;
#endif
pll a[N], b[N];
inline bool cp1(pll x, pll y)
{
	return x.first < y.first;
}
inline bool cp2(pll x, pll y)
{
	return x.second < y.second;
}
ll mergesort(int l, int r)
{
	if(l >= r) return 0;
	int mid = (l+r) >> 1;
	ll ans = mergesort(l, mid) + mergesort(mid+1, r);
	int i, j, k;
	i=l; j=mid+1; k=l;
	while(i<=mid && j<=r)
	{
		if(cp2(a[i], a[j]))
		{
			b[k] = a[i];
			i++; k++;
		}
		else
		{
			ans += mid+1-i;
			b[k] = a[j];
			j++; k++;
		}
	}
	while(i <= mid)
	{
		b[k] = a[i];
		i++; k++;
	}
	while(j <= r)
	{
		b[k] = a[j];
		j++; k++;
	}
	for(i = l; i<=r; i++) a[i] = b[i];
	return ans;
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
			int x, y;
			scanf("%d%d", &x, &y);
			a[i] = pll(x, y);
		}
		sort(a, a+n, cp1);
		printf("%lld\n", mergesort(0, n-1));
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
