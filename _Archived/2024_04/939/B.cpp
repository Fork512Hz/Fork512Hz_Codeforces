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
int app[N];
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
		memset(app, 0, sizeof(int) *(n+5));
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%d", &x);
			app[x] ++;
		}
		int ans =0;
		for(int i=1; i<=n; i++) if(app[i] == 2) ans++;
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
