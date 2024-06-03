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
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		if(m == 1)
			printf("NO\n");
		else
		{
			int maxseg = (n-1) / m + 1;
			if(k >= n-maxseg)
				printf("NO\n");
			else printf("YES\n");
		}
		
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
