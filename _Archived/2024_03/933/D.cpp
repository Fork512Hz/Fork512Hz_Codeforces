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
const long long N = 2010;
#endif
vector<int> un;
bool vis[2][N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		un = {-1};
		for(int i=0; i<m; i++)
		{
			int x; char c;
			scanf("%d %c\n", &x, &c);
			switch(c)
			{
				case '0' : k += x; break;
				case '1' : k -= x; break;
				case '?' :
					un.push_back(x);
			}
			
		}
		k %= n;
		k = (k+n) %n;
		int mm = un.size() - 1;
		memset(vis[0], 0, sizeof(bool) * (n+5));
		vis[0][k] = 1;
		for(int i = 1; i<= mm; i++)
		{
			memset(vis[i&1], 0, sizeof(bool) * (n+5));
			for(int j=0; j<n; j++) if(vis[(i^1) & 1][j])
			{
				vis[i&1][(j+un[i]) % n] = 1;
				vis[i&1][(j+n-un[i]) % n] = 1;
			}
		}
		int cnt = 0;
		for(int i=0; i<n; i++) if(vis[mm & 1][i]) 
			cnt++;
		printf("%d\n", cnt);
		for(int i=1; i<n; i++) if(vis[mm & 1][i]) 
			printf("%d ", i);
		if(vis[mm & 1][0]) printf("%d ", n);
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
