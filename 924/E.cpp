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
const ll N = 200100;
#endif
ll dp[N], father[N];


inline ll tri(ll x)
{
	return x*(x+1)/2;
}
int main()
{
    //freopen("1.txt", "r", stdin);
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
	father[0] = 0;
	for(ll i=0; i<N; i++)
	{
		for(ll j=1; ; j++)
		{
			ll target = i+tri(j);
			if(target >= N) break;
			if(dp[i] + j+1 < dp[target])
			{
				dp[target] = dp[i] + j+1;
				father[target] = j;
			}
		}
	}
    ll z;
    cin >> z;
    
    while(z--){
		ll n, x, y, s;
		scanf("%lld%lld%lld%lld", &n, &x, &y, &s);
		ll d, r;
		d = x/y;
		r = x%y;
		s -= r*n;
		if(s<0 || s%y != 0)
		{
			printf("NO\n");
			continue;
		}
		s /= y;
		ll sum = 0;
		for(ll i=1; ; i++)
		{
			sum += d+i-1;
			if(sum > s) 
			{
				printf("NO\n");
				break;
			}
			if(dp[s-sum] <= n-i)
			{
				printf("YES\n");
				for(ll j=0; j<i; j++) 
					printf("%lld ", x + y*j);
				ll rem = s - sum;
				while(rem > 0)
				{
					for(ll j=0; j<=father[rem]; j++) 
						printf("%lld ", r + y*j);
					rem -= tri(father[rem]);
				}
				for(ll j=1; j<=(n-i-dp[s-sum]); j++)
					printf("%lld ", r);
				printf("\n");
				break;
			}
		}
    }
 	return 0;
}
