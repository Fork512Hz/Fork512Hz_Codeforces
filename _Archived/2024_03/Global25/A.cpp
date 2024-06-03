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
		int cnt = 0;
		cin >> s;
		for(int i=0; i<n; i++)
		{
			if(s[i] == '1') cnt++;
		}
		if(cnt % 2) printf("NO\n");
		else if(cnt != 2) printf("YES\n");
		else
		{
			int j=0;
			for(; j<n; j++) if(s[j] == '1') break;
			if(j != n-1 && s[j+1] == '1')
				printf("NO\n");
				else printf("YES\n");
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
