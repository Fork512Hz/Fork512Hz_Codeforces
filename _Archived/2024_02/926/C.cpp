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
const ll N = 500100;
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
		ll k, x, a;
		scanf("%lld%lld%lld", &k, &x, &a);
		ll loss = 1;
		for(ll i=2; i<=(x+1); i++) 
		{
			loss += 1+loss/(k-1);
			if(loss > a)
			{
				printf("No\n");
				goto endd;
			}
			
		}
		printf("Yes\n");
		endd: ;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
