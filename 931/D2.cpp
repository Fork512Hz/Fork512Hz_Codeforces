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
const ll N = 100100;
#endif
ll bitcnt(ll x)
{
	ll t = x;
	
	ll ret =0;
	while(t)
	{
		if(t%2) ret++;
		t >>=1;
	}
	return ret;
}
ll highbit(ll x)
{
	ll t = x;
	ll cnt=0;
	while(t)
	{
		cnt++;
		t>>=1;
	}
	return 1ll << (cnt-1ll);
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
		ll n;
		scanf("%lld", &n);
		bool turn;
		if(bitcnt(n)%2) 
		{
			turn = 0;
			printf("second\n");
		}
		else
		{
			turn = 1;
			 printf("first\n");
		}
		fflush(stdout);
		ll p, q;
		p = 2;
		q = n;
		for(;;) if(turn)
		{
			ll todo;
			if(bitcnt(p) % 2) todo = q;
			else todo = p;
			printf("%lld %lld\n", todo-highbit(todo), highbit(todo));
			fflush(stdout);
			turn = 0;
		}
		else
		{
			scanf("%lld%lld", &p, &q);
			if(p == -1) return 3221225477;
			if(p == q && p == 0) break;
			
			turn = 1;
		}
		
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
