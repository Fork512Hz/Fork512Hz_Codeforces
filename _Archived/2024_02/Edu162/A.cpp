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
const ll N = 1000;
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
		int cnt = 0;
		for(int i=0; i<n; i++) 
		{
			scanf("%d", &a[i]);
			cnt += a[i];
		}
		int i, j;
		for(i=0; i<n; i++) if(a[i]) break;
		for(j=n-1; j>=0; j--) if(a[j]) break;
		printf("%d\n", j-i+1 - cnt); 
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
