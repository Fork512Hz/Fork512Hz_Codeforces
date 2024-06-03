#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = //TODO
#endif
ll bitcnt(ll x)
{
	ll r=0;
	while(x)
	{
		if(x&1)r++;
		x>>=1;
	}
	return r;
}

ll highbit(ll x)
{
	ll r=1;
	x>>=1;
	while(x)
	{
		r<<=1;
		x>>=1;
	}
	return r;
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
		ll n, a, b;
		cin>>n;
		if(bitcnt(n)&1)
			printf("second\n");
		else 
		{
			printf("first\n");
			printf("%lld %lld\n", highbit(n), n-highbit(n));
		}
		fflush(stdout);
		cin >> a >> b;
		while(a != 0)
		{
			if(bitcnt(a) & 1) swap(a,b);
			printf("%lld %lld\n", highbit(a), a-highbit(a));
			fflush(stdout);
			cin >> a >> b;
			if(a == -1) return 3221225477;
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
