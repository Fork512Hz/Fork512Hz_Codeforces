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
		for(int i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
		}
		k--;
		int t = a[k];
		int i;
		for(i=0; i<n; i++) if(a[i] > t) break;
		int j = i;
		
		a[k] = a[0];
		a[0] = t;
		for(i=1; i<n; i++) if(a[i] > a[0]) break;
		int ans = i-1;
		t = a[0];
		a[0] = a[k];
		a[k] = t;
		
		if(j < k)
		{
			int cnt = j!=0;
			swap(a[k], a[j]);
			for(int i=j+1; i<n; i++) 
			{
				if(a[i] < t) cnt++;
				if(a[i] > t) break;
			}
			ans = max(ans, cnt);
		}
		printf("%d\n", ans);
	}
	#endif
	#ifndef MULTI

	#endif
 	return 0;
}
