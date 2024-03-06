#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;


#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
const ll M= 998244353;
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
	ll a,b;
		scanf("%lld%lld", &a, &b);
		if(a%2 && b % 2) printf("No\n");
		else if(a %2 && b == 2*a) printf("No\n");
		else if(b%2 && a==2*b) printf("No\n");
		else printf("Yes\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
