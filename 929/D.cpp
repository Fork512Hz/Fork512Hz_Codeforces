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
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		sort(a, a+n);
		if(a[0] == a[1])
		{
			for(int i=2; i<n; i++) if(a[i] % a[0])
			{
				printf("Yes\n");
				goto fin;
			}
			printf("No\n");
		}
		else printf("Yes\n");
		fin: ;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
