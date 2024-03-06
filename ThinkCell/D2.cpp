#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

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
		scanf("%d\n", &n);
		ll ans = 0;
		ll s = 0;
		ll cd2 = 0, cd1 = 0, ready = 0; //3 seconds cooldown
		for(int i=0; i<n; i++)
		{
			char ch;
			scanf("%c", &ch);
			ll t = ready;
			ready = cd1;
			cd1 = cd2; //Clock tick
			t ++; //New string ready
			if(ch == '1')
			{
				s += t; //Release all strings not on cooldown
				cd2 = t;
			}
			else
			{
				ready += t; //Not triggered
				cd2 = 0;
			}
			ans += s;
		}
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
