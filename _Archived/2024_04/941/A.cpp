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
const long long N = 110;
#endif
#ifndef DEBUG
const long long N = 110;
#endif
int a[N];
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
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		sort(a, a+n);
		for(int i=k-1; i<n; i++)
			if(a[i] == a[i-k+1])
			{
				printf("%d\n", k-1);
				goto fin;
			}
		printf("%d\n", n);
		fin: ;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
