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

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		ll coin, jewel;
		scanf("%lld%lld", &coin, &jewel);
		if(jewel <= (coin + 1) / 2)
		{
			printf("YES\n2\n%lld 1\n", coin-jewel+1);
		}
		else if(coin == jewel)
		{
			printf("YES\n1\n1\n");
		}
		else printf("NO\n");
		
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
