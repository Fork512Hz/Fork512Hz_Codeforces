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
const ll N = 105000;
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
		for(int i=1; i<=n/2; i++)
		{
			printf("%d %d ", n+1-i, i);
		}
		if(n%2) printf("%d", (n+1) / 2);
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
