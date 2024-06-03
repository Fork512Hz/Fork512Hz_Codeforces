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

//#define MULTI

#ifdef DEBUG
const long long N = 55;
#endif
#ifndef DEBUG
const long long N = 55;
#endif
struct cube{
	int x, y, z, c;
	cube(){
	}
	cube(int p, int q, int r, int s):
		x(p), y(q), z(r), c(s){
		}
	void print()
	{
		printf("%d %d %d %d\n", x, y, z, c);
	}
};
int grid[N][N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		
    }
    #endif
	#ifndef MULTI
	int c, n, m;
	scanf("%d%d%d", &n, &m, &c);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d", &grid[i][j]);
	vector<cube> ans;
	for(int i=1; i<=n; i++)
	{
		int pos = n+1-i;
		int height = pos + (pos/2);
		for(int j=1; j<=m; j++)
		{
			for(int k=2; k<=height; k++)
				ans.push_back(cube(i, j, k, grid[i][j]));
			for(int k=i+1; k<=n+grid[i][j]; k++)
				ans.push_back(cube(k, j, height, grid[i][j]));
		}
	}
	int glue = (n+1)/2 * 3 - 1;
	for(int i=1; i<=c; i++)
	{
		for(int j=1; j<=m; j++)
			for(int k=2; k<=glue; k+=3)
				ans.push_back(cube(n+i, j, k, i));
		for(int k=2; k<=glue;k++)
			ans.push_back(cube(n+i, m+1, k, i));
	}
	printf("%d\n", ans.size());
	for(cube i: ans) i.print();
	#endif
 	return 0;
}
