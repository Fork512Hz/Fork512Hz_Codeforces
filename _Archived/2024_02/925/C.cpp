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
		int h = a[0];
		int t = a[n-1];
		int i=0; int j=n-1;
		while(a[i]==h) i++;
		while(a[j]==t) j--;
		int ans;
		if(h == t) ans = j-i+1;
		else ans = min(n-i, j+1);
		if(ans < 0) ans=0;
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
