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
		int n, r, b;
		scanf("%d%d%d", &n, &r, &b);
		int d = r/(b+1);
		int rem = r%(b+1);
		for(int i=1; i<=b+1; i++)
		{
			for(int j=0; j<d; j++)
				printf("R");
			if(i <= rem) printf("R");
			if(i != b+1) printf("B");
		}
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
