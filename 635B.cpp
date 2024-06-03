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


int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int x, n, m;
		scanf("%d%d%d", &x, &n, &m);
		if(x > 20)
			for(int i=0; i<n; i++)
				x = (x>>1) + 10;
		if(m * 10 >= x)
			printf("YES\n");
		else
			printf("NO\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
