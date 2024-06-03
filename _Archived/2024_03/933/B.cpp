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
		for(int i=0; i<n-2; i++)
		{
			if(a[i] < 0)
			{
				printf("NO\n");
				goto fin;
			}
			a[i+1] -= 2*a[i];
			a[i+2] -= a[i];
		}
		if(a[n-2] == 0 && a[n-1] == 0) printf("YES\n");
		else printf("NO\n");
		fin:;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
