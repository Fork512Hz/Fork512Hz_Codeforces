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
ll gcd(ll x, ll y)
{
	ll t;
	if(x > y) swap(x, y);
	while(x)
	{
		t = y%x;
		y = x;
		x = t;
	}
	return y;
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
		ll a, b;
		scanf("%lld%lld", &a, &b);
		ll g = gcd(a,b);
		if(g == a)
			printf("%lld\n", b*b/a);
		else
			printf("%lld\n", b*a/g);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
