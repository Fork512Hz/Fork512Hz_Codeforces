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
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a<b && b<c) printf("STAIR");
		else if(a<b && b>c) printf("PEAK");
		else printf("NONE");
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
