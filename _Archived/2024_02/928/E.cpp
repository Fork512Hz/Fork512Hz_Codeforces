#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 1000;
#endif
int cnt[40];
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
		int top = 0;
		while(n)
		{
			cnt[top] = (n+1) /2;
			n -= cnt[top];
			top++;
			
		}
		top = 0;
		while(k > cnt[top])
		{
			k -= cnt[top];
			top++;
		}
		printf("%d\n",(1<<top) * (2*k-1) );
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
