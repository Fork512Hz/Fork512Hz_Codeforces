#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG
//#define DEBUG2
#define MULTI

#ifdef DEBUG
const ll N = 105;
#endif
#ifndef DEBUG
const ll N = 105;
#endif
const int inf = 0x7f7f7f7f;
int a[N];
int dp[N][N][N];
inline void update(int x, int y, int z, int val)
{
	if(dp[x][y][z] > val) dp[x][y][z] = val;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
	#ifdef DEBUG2
    bool flag=0;
    #endif
    for(int zz=0; zz<z; zz++){
		int n;
		
		scanf("%d", &n);
		#ifdef DEBUG2
		if(z == 100 && zz == 1 && n == 2) 
			flag = 1;
		#endif
			
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		#ifdef DEBUG2
		if(zz == 77 && flag)
		{
			printf("%d\n", n);
			for(int i=1; i<=n; i++)
			{
				printf("%d ", a[i]);
				if(i%10 == 0) printf("\n");
			}
			exit(0);
		}
		#endif
		for(int i=0; i<=n+1; i++) 
			for(int j=0; j<=n+1; j++)
				memset(dp[i][j], 0x7f, sizeof(int) * (n+2));
		dp[0][1][0] = 0;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n+1; j++)
			{
				for(int k=0; k<=n; k++) if(dp[i-1][j][k] != inf)
				{
//					if(i == 2 && j == 1 && k == 0)
//						printf("Attention!\n");
//					if(i == 3 && j == 3 && k == 2)
//						printf("Attention!\n");
//					if(i == 3 && j == 1 && k == 0)
//						printf("Attention!\n");
//					if(i == 4 && j == 4 && k == 3)
//						printf("Attention!\n");
					// no move
					update(i, j, k, dp[i-1][j][k]);
					// left
					if(i+1-a[i] <= j)
						update(i, max(k,i) +1, max(k, i), dp[i-1][j][k]+1);
					// right
					if(i+a[i]-1 > k)
						update(i, j<i? j: min(i+a[i], n+1), min(i+a[i]-1, n), dp[i-1][j][k]+1);
				}
			}
		}
		#ifdef DEBUG2
		if(!flag) 
		#endif
		printf("%d\n", dp[n][n+1][n]); 
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
