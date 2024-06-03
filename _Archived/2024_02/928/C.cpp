#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;


#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 200100;
#endif
int ans[N];

int f(int x)
{
	int t = x;
	int r = 0;
	while(t)
	{
		r += t%10;
		t /= 10;
	}
	return r;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    ans[0] = 0;
    for(int i=1; i<=200000; i++)
    {
    	ans[i] = ans[i-1] + f(i);
	}
    int z;
    cin >> z;
    while(z--){
		int n;
		scanf("%d", &n);
		printf("%d\n", ans[n]);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
