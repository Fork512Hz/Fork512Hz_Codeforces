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
const ll N = 100100;
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
		int sum=0;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%d", &x);
			sum += abs(x);
		}
		printf("%d\n", sum);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
