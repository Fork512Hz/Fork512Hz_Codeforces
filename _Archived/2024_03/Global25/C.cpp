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
const long long N = 500100;
#endif
ll a[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		ll n, m, k;
		scanf("%lld%lld%lld", &n, &m, &k);
		for(int i=0; i<n; i++)
		{
			scanf("%lld", &a[i]);
			
		}
		sort(a, a+n);
		ll ans = 0;
		ll t = k;
		ll r = 0;
		for(int i=0; i<n; i++)
		{
			if(k <= m)
			{
				ans += k * (a[i] + r);
				break;
			}
			else 
			{
				ans += m * (a[i] + r);
				r += m;
				k -= m;
			}
		}
		printf("%lld\n", ans);
		
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
