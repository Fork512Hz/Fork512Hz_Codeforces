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
const ll N = 300100;
#endif
ll a[N], hp[N];
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
		memset(hp, 0, sizeof(ll) * (n+3));
		for(ll i=0; i<n; i++)
			scanf("%lld", &a[i]);
		for(ll i=0; i<n; i++)
		{
			ll x;
			scanf("%lld", &x);
			hp[abs(x)] += a[i];
		}
		for(ll i=1; i<=n; i++) hp[i] += hp[i-1];
		for(ll i=0; i<=n; i++)
		{
			if(hp[i] > k*i)
			{
				printf("No\n");
				goto fin;
			}
		}
		printf("Yes\n");
		fin:;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
