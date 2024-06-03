#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long ll;
//#define DEBUG

#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
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
		int n, k;
		scanf("%d%d", &n, &k);
		if(k > (n-1)/2) 
		{
			printf("-1\n");
			continue;
		}
		for(int i=0, x=1; i<n; i+=2, x++)
			a[i] = x;
		for(int i=(n/2)*2-1, x=n; i>=0; i-=2, x--)
			a[i] = x;
		if(k == 0)
			sort(a, a+n);
		else sort(a, a + (((n-1) /2 - k + 1) * 2));
		for(int i=0; i<n; i++)
			printf("%d ", a[i]);
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
