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

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n;
		ll s=0;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			ll x;
			scanf("%lld", &x);
			s += x;
		}
		ll rt = floor(sqrt(s)+0.5);
		if(rt * rt == s) printf("Yes\n");
		else printf("No\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
