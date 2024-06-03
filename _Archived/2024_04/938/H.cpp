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
const long long N = 55;
const int R = 5;
#endif
#ifndef DEBUG
const long long N = 55;
const int R = 12;
#endif


struct tower
{
	int x, y, p;
	int d[R+3] = {};
	tower(){
		
	}
	tower(int a, int b, int c):
		x(a), y(b), p(c)
		{
		}
};
int pow3[R+3];
int enemy[(1<<(R+1)) + 100];
char grid[N][N];
tower towers[N*N];
int disttable[2*R+1][2*R+1];
int dp[N*N][(1<<(R+1)) + 100];

int dist(int x1, int y1, int x2, int y2)
{
	int t = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
	int q = floor(sqrt(t) + 0.5);
	if(q * q == t) return q; //Avoid floating point error, necessary?
	else return ceil(sqrt(t));
}

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    
    pow3[0] = 1;
    for(int i=1; i<R+3; i++) pow3[i] = pow3[i-1] * 3;
    for(int i=0; i<=R; i++) 
    	for(int j = 1<<i; j < 1<<(i+1); j++)
    		enemy[j] = pow3[i] + enemy[j - (1<<i)];
    for(int i=0; i<2*R+1; i++)
    	for(int j=0; j<2*R+1; j++)
    		disttable[i][j] = dist(i, j, R, R);
    
    int z;
    cin >> z;
    while(z--){
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for(int i=0; i<n; i++) scanf("%s", grid[i]);
		for(int i=0; i<k; i++)
		{
			int x, y, p;
			scanf("%d%d%d", &x, &y, &p);
			x--; y--;
			towers[i] = tower(x, y, p);
			tower &cur = towers[i];
			
			for(int j=max(-R, -cur.x); j<=min(R, n-1-cur.x); j++)
				for(int l=max(-R, -cur.y); l<=min(R, m-1-cur.y); l++)
					if(grid[cur.x + j][cur.y + l] == '#') 
						cur.d[disttable[j+R][l+R]] ++;
			for(int j=1; j<=R; j++) cur.d[j] += cur.d[j-1];
		}
		for(int i=0; i<n; i++)
			memset(dp[i], 0, sizeof(int) * ( (1<<(R+1)) + 50) );
		int ans = 0;
		for(int i=1; i<=R; i++) 
		{
			dp[0][1<<i] = towers[0].p * towers[0].d[i];
			ans = max(ans, dp[0][1<<i] - enemy[1<<i]);
		}
		for(int i=1; i<k; i++)
			for(int j=0; j<1<<(R+1); j++)
			{
				dp[i][j] = dp[i-1][j];
				for(int l=1; l<=R; l++) if(j & (1<<l))
					dp[i][j] = max(dp[i][j], dp[i-1][j-(1<<l)] + towers[i].p * towers[i].d[l]);
				ans = max(ans, dp[i][j] - enemy[j]);
			}
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
