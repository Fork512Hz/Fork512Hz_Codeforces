#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
typedef long long ll;
#define DEBUG
#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = //TODO
#endif

using namespace std;

int main()
{
    #ifdef DEBUG
    //freopen("1.txt", "r", stdin);
    #endif
	int z;
	cin >> z;
	while(z--)
    {
    	ll x, n;
    	scanf("%lld%lld", &x, &n);
    	if(n*n <= x)
    	{
    		for(ll i=n; i*i<=x; i++) if(x%i==0) 
    		{
    			printf("%lld\n", x/i);
    			goto end;
			}
			for(ll i=n-1; i>=1; i--) if(x%i==0)
			{
				printf("%lld\n", i);
				break;
			}
		}
		else
		{
			for(ll i=x/n; i>=1; i--) if(x%i==0)
			{
				printf("%lld\n", i);
				break;
			}
		}
		end:
			;
	}
 	return 0;
}
