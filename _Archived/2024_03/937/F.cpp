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
		int n2, n1, n0;
		scanf("%d%d%d", &n2, &n1, &n0);
		if(n2 + 1 != n0) 
		{
			printf("-1\n");
			continue;
		}
		int digits = 0;
		while(n2)
		{
			digits++;
			n2 >>= 1;
		}
		n1 -= (1 << digits) - n0;
		if(n1 > 0)
			digits += ((n1-1) / n0 + 1);
		printf("%d\n", digits);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
