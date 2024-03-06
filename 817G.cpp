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
//const ll N = //TODO
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
		if(n == 3)
		{
			printf("2 1 3\n");
			continue;
		}
		if(n%2) 
		{
			printf("0 ");
			n--;
		}
		if(n%4 == 0) for(int i=0; i<n; i++) printf("%d ", i+2);
		else
		{
			for(int i=0; i<n-6; i++) printf("%d ", i+2);
			const int M = 1<<24;
			printf("%d %d %d %d %d %d", M+4, M+1, M+2, M+12, M+3, M+8);
		}
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
