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
const long long N = 200100;
#endif
int a[N], ans[N];

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
		int mex = n;
		for(int i = n-1; i>=0; i--)
		{
			ans[i] = mex - a[i];
			mex = min(ans[i], mex);
		}
		for(int i=0; i<n; i++) printf("%d ", ans[i]);
		printf("\n");
		
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
