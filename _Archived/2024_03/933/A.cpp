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
const long long N = 10100;
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
		int n, m, k;
		int ans=0;
		scanf("%d%d%d", &n, &m, &k);
		for(int i=0; i<n; i++)scanf("%d", &a[i]);
		for(int i=0; i<m; i++)
		{
			int x;
			scanf("%d", &x);
			for(int j=0; j<n; j++) if(x + a[j] <= k)
				ans++;
		}
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
