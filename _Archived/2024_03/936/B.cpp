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
const ll M = 1000000007;

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		ll n, k;
		scanf("%lld%lld", &n, &k);
		for(ll i=0; i<n; i++)scanf("%lld", &a[i]);
		ll sum = 0;
		for(ll i=0; i<n ;i++) sum = (sum + a[i] + M) % M;
		while(sum < 0) sum += M;
		sum %= M;
		ll tsum = 0;
		ll smax = 0;
		for(ll i=0; i<n; i++) {
			tsum = max(0ll, tsum + a[i]);
			smax = max(smax, tsum);
		}
		for(ll i=0; i<k; i++)
		{
			sum = (sum + smax) % M;
			smax = (smax * 2) % M;
		}
		printf("%lld\n", sum);
		
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
