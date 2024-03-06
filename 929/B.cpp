#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;


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
		int n, a[3];
		a[0] = 0;
		a[1] = 0;
		a[2] = 0;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%d", &x);
			a[x%3] ++;
		}
		int sum = (a[1] + 2*a[2]) % 3;
		switch(sum)
		{
			case 0: printf("0\n"); break;
			case 1: 
				if(a[1]) printf("1\n");
				else printf("2\n");
				break;
			case 2:
				printf("1\n");
				break;
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
