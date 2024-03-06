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

int main()
{
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		ll a, b;
		scanf("%lld%lld", &a, &b);
		if(a>b)
		{
			ll t=a;
			a=b;
			b=t;
		}
		if(b >= a*3) printf("%lld", a);
		else printf("%lld", (a+b) / 4);
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
