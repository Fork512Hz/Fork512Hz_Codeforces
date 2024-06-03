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
const long long N = 200100;
#endif
int a[N];
bool h[N];
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
		a[0] = 0;
		for(int i=1; i<=n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n+1);
		auto t = unique(a, a+n+1);
		n = t-a-1;
		h[n] = 0;
		for(int i=n-1; i>=0; i--)
			switch(a[i] - a[i-1])
			{
				case 0: h[i] = h[i+1]; break;
				case 1: h[i] = !h[i+1]; break;
				default: h[i] = 0;
			}
		if(h[1]) printf("Bob\n");
		else printf("Alice\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
