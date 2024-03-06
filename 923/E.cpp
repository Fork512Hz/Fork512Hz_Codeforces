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
const ll N = 200010;
#endif
int ans[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n, k;
		scanf("%d%d", &n, &k);
		int r = n%k;
		int d = n/k;
		int t=1;
		for(int i=1; i<=k; i++) 
		if(i % 2)
		{
			for(int j=i; j<=n; j+=k)
			{
				ans[j] = t;
				t++;
			}
		}
		else
		{
			int j = d*k+i;
			if(j>n) j -= k;
			for(; j>=1; j-=k)
			{
				ans[j] = t;
				t++;
			}
		}
		for(int i=1; i<=n; i++) printf("%d ", ans[i]);
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
