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
		string s;
		cin >> s;
		int tot =0 ;
		for(int i=0; i<n; i++) tot += s[i] - 48;
		int ans, mind;
		ans = 0x3f3f3f3f;
		mind = 0x3f3f3f3f;
		if(tot*2 >= n) 
		{
			ans = 0;
			mind = n;
		}
		int cnt =0 ;
		for(int i=1; i<=n; i++)
		{
			cnt += s[i-1] - 48;
			if((tot-cnt) * 2 >= n-i && (i-cnt)*2 >= i)
			{
				if(abs(n - i*2) < mind)
				{
					mind = abs(n - i*2);
					ans = i; 
				}
			}
		}
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
