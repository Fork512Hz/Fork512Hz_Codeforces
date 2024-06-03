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
		int n, x, t;
		scanf("%d%d", &n, &x);
		
		for(int i=0; i<n; i++) 
		{
			scanf("%d", &a[i]);
			if(a[i] == x) t = i;
		}
		int l = 0;
		int r = n;
		while(r-l > 1)
		{
			int m = (l+r) >> 1;
			if(a[m] <= x) l=m;
			else r=m;
		}
		if(l == t) printf("0\n");
		else printf("1\n%d %d\n", t+1, l+1);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
