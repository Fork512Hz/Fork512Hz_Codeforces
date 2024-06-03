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
const long long N = 100;
#endif
#ifndef DEBUG
const long long N = 500;
#endif
int f[N];
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
		for(int i=1; i<=n; i++)
			scanf("%d", &f[i]);
		for(int i=1; i<=n; i++) if(f[f[i]] == i)
		{
			printf("2\n");
			goto fin;
		}
		printf("3\n");
		fin:;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
