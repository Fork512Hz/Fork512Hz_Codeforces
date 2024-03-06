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
int a[500];
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
		n *= 2;
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		sort(a, a+n);
		int sum = 0;
		for(int i=0; i<n; i+=2) sum += a[i];
		printf("%d\n", sum);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
