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
const long long N = 1000;
#endif
ll a[N];
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
		for(int i=0; i<n; i++) scanf("%d" ,&a[i]);
		for(int i=n-2; i>=0; i--) if(a[i] > a[i+1])
		{
			if(a[i] <= 9) goto fail;
			if(a[i] /10 > a[i] % 10) goto fail;
			if(a[i] % 10 > a[i+1]) goto fail;
			a[i] /= 10;
		}
		printf("YES\n");
		continue;
		fail:
			printf("NO\n");
			
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
