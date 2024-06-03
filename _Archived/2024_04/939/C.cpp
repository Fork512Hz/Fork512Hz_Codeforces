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
///
#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif
int n;
void pr()
{
	for(int i=1; i<=n; i++)
		printf("%d ", i);
	printf("\n");
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
		
		scanf("%d", &n);
		int ans = n*n*n;
		for(int i=n-1; i>=1; i--)
			ans -= i*i;
		printf("%d %d\n", ans, 2*n);
		for(int i=n; i>=1; i--)
		{
			printf("1 %d ", i);
			pr();
			printf("2 %d ", i);
			pr();
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
