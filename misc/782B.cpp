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
int ans[N];
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
		string s;
		cin >> s;
		bool t = k&1;
		for(int i=0; i<n; i++) s[i] ^= t;
		memset(ans, 0, sizeof(int) * (n+5));
		for(int i=0; i<n; i++)
		{
			if(k == 0) break;
			if(s[i] == '0')
			{
				ans[i] ++;
				s[i] = '1';
				k--;
				
			}
		}
		t = k&1;
		s[n-1] ^= t;
		ans[n-1] += k;
		cout << s << '\n';
		for(int i=0; i<n; i++)
			printf("%d ", ans[i]);
		printf("\n");	
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
