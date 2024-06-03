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
		scanf("%d",&n);
		int x=0;
		while(n)
		{
			x++;
			n >>= 1;
		}
		printf("%d\n", 1<<(x-1));
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
