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
		int x = a[0];
		int l, ans;
		l = 0;
		ans = 0x7fffffff;
		for(int i=0; i<n; i++) if(a[i] != x)
		{
			ans = min(l, ans);
			l = 0;
			
		}
		else l++;
		ans = min(l, ans);
		if(ans == n) ans = -1;
		printf("%d\n",  ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
