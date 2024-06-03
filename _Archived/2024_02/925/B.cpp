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
#ifndef DEBUG
const ll N = 200010;
#endif
ll a[N];
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
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%lld", &a[i]);
		ll sum = 0;
		for(int i=0; i<n; i++) sum += a[i];
		ll av = sum/n;
		for(int i=0; i<n; i++)
		{
			if(a[i]<av)
			{
				printf("no\n");
				goto endd;
			}
			else
			{
				ll x = a[i] - av;
				a[i+1] += x;
			}
		}
		printf("yes\n");
		endd: ;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
