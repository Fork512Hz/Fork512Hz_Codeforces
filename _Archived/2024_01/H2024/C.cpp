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
		int n, x, y, ans;
		x = -1; y = -1;
		ans = -2;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
		for(int i=0; i<n; i++)
		{
			if(x >= a[i] && y >= a[i])
			{
				if(x <= y) x = a[i];
				else y = a[i];
			}
			else if(x >= a[i] && y < a[i]) 
				x = a[i];
			else if(x < a[i] && y >= a[i])
				y = a[i];
			else
			{
				ans++;
				if(x <= y) x = a[i];
				else y = a[i];
			}
		}
		if(y == -1) ans ++;
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
