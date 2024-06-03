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
const long long N = 100100;
#endif
// const ll M = 998244353;
pii a[N], b[N];
int ans[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		int n;
		scanf("%d", &n);
		bool p;
		for(int i=0; i<n/2; i++)
		{
			ll x, y;
			scanf("%lld%lld", &x, &y);
			if(x == n) p = 0;
			if(y == n) p = 1;
			a[i] = {x, i*2};
			b[i] = {y, i*2+1};
		}
		sort(a, a+n/2);
		sort(b, b+n/2);
		if(p)
			for(int i=0; i<n/2; i++)
			{
				ans[a[i].second] = n/2-i;
				ans[b[i].second] = n-i;
			}
		else
			for(int i=0; i<n/2; i++)
			{
				ans[a[i].second] = n-i;
				ans[b[i].second] = n/2-i;
			}
		for(int i=0; i<n; i++)
			printf("%d ", ans[i]);
		printf("\n");
    }
 	return 0;
}
