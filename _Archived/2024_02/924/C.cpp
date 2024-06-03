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
const ll N = 100;
#endif
bool flag=0;
ll x;
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
		flag = 0;
		scanf("%lld%lld", &n, &x);
		if((n+x) % 2)
		{
			printf("0\n");
			continue;
		}
		
		ll b = (n+x-2) /2;
		ll a = (n-x)  / 2;
		ll ans=0;
		for(int i=1; i*i<=a; i++) if (i != 0 && a%i == 0)
		{
			int j = a/i;
			if(i+1 >= x) ans++;
			if(i+1 == x) flag = 1;
			if(i != j) 
			{
				if(j+1 >= x) ans++;
				if(j+1 == x) flag = 1;
			}
		}
		if(x == 1) flag = 0;
		else
		{
			for(int i=1; i*i<=b; i++) if(b%i == 0)
			{
				int j = b/i;
				if(i+1 >= x) ans++;
				if(i+1 == x) flag = 1;
				if(i != j) 
				{
					if(j+1 >= x) ans++;
					if(j+1 == x) flag = 1;
				}
			}
		}
		printf("%lld\n", ans-flag);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
