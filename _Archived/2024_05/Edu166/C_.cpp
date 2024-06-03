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
// const ll M = 998244353;
ll a[N], b[N];
bool side[N], bad[N];
inline r(int x)
{
	return side[x]? b[x]: a[x];
}
inline rev(int x)
{
	return side[x]? a[x]: b[x];
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		ll n, m;
		scanf("%lld%lld", &n, &m);
		for(ll i=0; i<n+m+1; i++)
			scanf("%lld", &a[i]);
		for(ll i=0; i<n+m+1; i++)
			scanf("%lld", &b[i]);	
		ll cnta=0, cntb=0;
		int i = 0;
		ll ans = 0;
		if(n == 0 || m == 0) goto p2; 
		for(; i<n+m+1; i++)
		{
			if(a[i] > b[i])
			{
				cnta++;
				side[i] = 0;
				bad[i] = 0;
				ans += a[i];
				if(cnta == n) break;
			}
			else
			{
				cntb++;
				side[i] = 1;
				bad[i] = 0;
				ans += b[i];
				if(cntb == m) break;
			}
		}
		i++;
		p2:
		if(cnta == n)
		{
			for(; i<n+m+1; i++)
			{
				side[i] = 1;
				ans += b[i];
				bad[i] = a[i] > b[i] || i == n+m;
			}
		}
		else
		{
			for(; i<n+m+1; i++)
			{
				side[i] = 0;
				ans += a[i];
				bad[i] = a[i] < b[i] || i == n+m;
			}
		}
		int ch = -1;
		for(int i=0; i<n+m+1; i++) if(bad[i])
		{
			ch = i;
			break;
		}
		for(int i=0; i<ch; i++)
		{
			if(side[i] == side[ch])
				printf("%lld ", ans - r(i));
			else printf("%lld ", ans - r(i) - r(ch) + rev(ch));
		}
		for(int i=ch; i<n+m+1; i++)
			printf("%lld ", ans - r(i));
		printf("\n");
    }
 	return 0;
}
