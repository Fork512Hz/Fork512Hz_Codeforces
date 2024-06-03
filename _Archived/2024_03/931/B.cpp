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
const ll N = 10000;
#endif
int ex[15]={0, 1, 2, 1, 2, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3};
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
		if(n == 5) printf("3\n");
		else if(n == 8) printf("3\n");
		else printf("%d\n", n/15 + ex[n%15]);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
