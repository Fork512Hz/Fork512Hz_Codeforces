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
const ll N = 500100;
#endif

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
		int a=-1;
		int b=0x7fffffff;
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%d", &x);
			a = max(a, x);
			b = min(b, x);
		}
		printf("%d\n", a-b);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
