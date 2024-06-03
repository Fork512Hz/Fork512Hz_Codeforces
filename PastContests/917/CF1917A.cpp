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
		bool sign = 0;
		bool zero = 0;
		for(int i=1; i<=n; i++)
		{
			int x;
			scanf("%d", &x);
			if(x == 0) zero = 1;
			if(x < 0) sign = !sign;
		}
		if(sign || zero)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n1 0\n");
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
