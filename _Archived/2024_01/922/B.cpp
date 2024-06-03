#include<cstdio>
#include<algorithm>
#include<iostream>
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
int a[N], b[N];
int main()
{
    #ifdef DEBUG
    //freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) 
		{
			int x;
			scanf("%d", &x);
			a[x] = i;
		}
		for(int i=1; i<=n; i++) scanf("%d", &b[i]);
		for(int i=1; i<=n; i++) printf("%d ", i);
		printf("\n");
		for(int i=1; i<=n; i++) printf("%d ", b[a[i]]);
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
