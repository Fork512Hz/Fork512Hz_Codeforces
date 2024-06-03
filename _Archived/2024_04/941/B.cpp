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
const long long N = 510;
#endif
char a[N][N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++) scanf("%s", a[i]);
		int b = 0, w = 0;
		for(int i=0; i<n; i++) 
		{
			if(a[i][0] == 'B') b |= 1;
			else w |= 1;
			if(a[i][m-1] == 'B') b |= 2;
			else w |= 2;
		}
		for(int i=0; i<m; i++)
		{
			if(a[0][i] == 'B') b |= 4;
			else w |= 4;
			if(a[n-1][i] == 'B') b |= 8;
			else w |= 8;
		}
		if(b == 15 || w == 15) printf("YES\n");
		else printf("NO\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
