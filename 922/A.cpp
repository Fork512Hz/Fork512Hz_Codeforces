#include<cstdio>
#include<algorithm>
#include<iostream>
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

int main()
{
    #ifdef DEBUG
    //freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		ll x, y;
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", x*(y>>1));
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}