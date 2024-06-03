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
		if(n & 1) printf("NO\n");
		else{
			printf("YES\n");
			for(int i=0; i<n/2; i++)
				if(i&1) printf("AA");
				else printf("BB");
			printf("\n");
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
