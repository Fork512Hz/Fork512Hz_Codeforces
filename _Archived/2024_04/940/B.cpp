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
int highbit(int x)
{
	int f = 0;
	int r = x;
	while(r)
	{
		f++;
		r >>= 1;
	}
	f--;
	return f;
}
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
		if(n == 1)
		{
			printf("%d\n", k);
			continue;
		}
		int t = highbit(k+1);
		printf("%d %d ", (1 << t) - 1, k - (1<< t) + 1);
		for(int i=3; i<=n; i++) printf("0 ");
		printf("\n");
		
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
