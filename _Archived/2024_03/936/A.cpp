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
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
		sort(a, a+n);
		a[n] = 0x7fffffff;
		int cnt = 0;
		for(int i=(n-1) / 2; i<n; i++)
		{
			a[i] ++;
			cnt ++;
			if(a[i] <= a[i+1]) break;
		}
		printf("%d\n", cnt);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
