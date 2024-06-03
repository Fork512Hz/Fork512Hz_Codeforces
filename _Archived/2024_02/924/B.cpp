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
const ll N = 200100;
#endif
ll a[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    cin >> z;
    while(z--){
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		sort(a, a+n);
		int i=0, j=0, ans=-1;
		a[n] = 0x7fffffff;
		int cnt = 0;
		while(j<n)
		{
			while(a[j]-a[i]<=n-1)
			{
				if(a[j] != a[j+1]) cnt++;
				j++;
			}
			if(cnt > ans) ans = cnt;
			if(a[i]!= a[i+1]) cnt--;
			i++;
		}
		printf("%d\n", ans);
}
 	return 0;
}
