#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
int n, m, k, z, ans;
const int N = 100020;
bool _grid[4][N];
int pfs[2][N];
inline bool *grid(int id, int x, int y)
{
	
return &(_grid[id][x*m+y]);
}

inline bool *grid2(int id, int x, int y)
{
	return &(_grid[id][x*n+y]);
}
inline int getpfs(int id, int x, int y)
{
	if(x<0 || y<0) return 0;
	else if(x>=n && y>=m) return pfs[id][n*m-1];
	else if(x>=n) return pfs[id][(n-1)*m+y];
	else if(y>=m) return pfs[id][x*m+m-1];
	else return pfs[id][x*m+y];
}
inline void setpfs(int id, int x, int y, int val)
{
	if(x<0 || y<0) return ;
	else if(x>=n || y>=m) return;
	else  pfs[id][x*m+y] = val;
}
void solve(int id)
{
	
	for(int i=0; i<n; i++)
	{
		setpfs(0, i, 0, *grid(id, i, 0));
		for(int j=1; j<m; j++)
			setpfs(0,i,j, getpfs(0,i,j-1) + *grid(id, i, j));
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(i == 0) setpfs(1, i, j, *grid(id, i, j));
			else setpfs(1,i,j, getpfs(1,i-1,j) + *grid(id, i, j));
 		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++) 
		{
			int tg = 0;
			if(m >= n)
				for (int w=0; w<=k && i+w<n; w++)
					tg += getpfs(0, i+w, j+k-w) - getpfs(0, i+w, j-1);
			else
				for (int w=0; w<=k && j+w<m; w++)
					tg += getpfs(1, i+k-w, j+w) - getpfs(1, i-1, j+w);
			if(tg > ans) ans=tg;
		}
	}
}
int main()
{
	//freopen("1.txt", "r", stdin);

	cin >> z;
	while(z--)
	{
		
		scanf("%d%d%d", &n, &m, &k);
		for(int i=0; i<n; i++)
		{
			string s;
			cin >> s;
			for(int j=0; j<m; j++)
			{
				bool t = s[j] == '#';
				*grid(0, i, j) = t;
				*grid(2, n-1-i, m-1-j) = t;
				*grid2(1, j, n-1-i) = t;
				*grid2(3, m-1-j, i) = t;
			}
			
		}
		ans = 0;
		solve(0);
		solve(2);
		int t;
		t=m; m=n; n=t;
		solve(1);
		solve(3);
		printf("%d\n", ans);
	}
 	return 0;
}
