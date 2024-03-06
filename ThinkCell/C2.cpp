#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<utility>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 300100;
#endif
const ll inf = 1000010001;
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
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &a[i]);
			a[i] += i;
		}
		sort(a+1, a+n+1);
		int dup = inf;
		for(int i=n; i>=1; i--)
		{
			if(a[i] >= dup) a[i] = dup -1;
			dup = a[i];
			printf("%d ", a[i]);
		}
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
