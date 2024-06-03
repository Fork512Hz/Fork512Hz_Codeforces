#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

bool occ[27];
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
		string s;
		scanf("%d", &n);
		cin >> s;
		memset(occ, 0, sizeof(occ));
		ll t = 0;
		ll ans = 0;
		for(int i=0; i<n; i++) 
		{
			if(!occ[s[i]-97])
			{
				occ[s[i]-97] = 1;
				t++;
			}
			ans += t;
		}
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
