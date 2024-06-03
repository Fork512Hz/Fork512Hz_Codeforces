#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;
const int tmax = 0x7fffffff;
//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 200100;
#endif
int a[N];
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
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		sort(a, a+n);
		int k1 = 0; 
		int k2 = n-1;
		int ans = n;
		while(k1 <= k2)
		{
			if(a[k2] == (tmax^a[k1]))
			{
				while (a[k2] == (tmax ^ a[k1]) && k1<k2)
				{
					k1++;
					k2--;
					ans--;
				}
			}
			else if(a[k2] > (tmax ^ a[k1])) k2--;
			else k1++;
		}
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
