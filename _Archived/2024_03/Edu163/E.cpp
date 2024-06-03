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
		int n, q;
		scanf("%d%d", &n, &q);
		int div = n/q;
		int r = n%q;
		for(int i=0; i<div; i++)
		{
			for(int j = q/2; j>=1; j--) printf("%d ", j + q*i);
			for(int j = q; j>q/2; j--) printf("%d ", j+q*i);
			
		}
		for(int j = r/2; j>=1; j--) printf("%d ", j + q*div);
		for(int j = r; j>r/2; j--) printf("%d ", j+q*div);
		printf("\n%d\n", n/q + (n%q? 1: 0));
		for(int i=0; i<n; i++) printf("%d ", i/q+1);
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
