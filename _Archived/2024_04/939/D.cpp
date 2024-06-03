#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<int, int> pii;
typedef vector<long long> vint;
typedef long long ll;
//#define DEBUG
///

#ifdef DEBUG
const long long N = 20;
#endif
#ifndef DEBUG
const long long N = 20;
#endif
int dp[N][N];
int split[N][N];
int a[N];
vector<pii> ans;

void move(int l, int r)
{
	for(int i=l; i<=r-1; i++)
	{
		move(i, r-1);
		for(int j=i+1; j<=r-1; j++) ans.push_back(pii(j, j));	
	}	
	
	ans.push_back(pii(l, r));
}

void output(int l, int r)
{
	if(split[l][r] == 0) 
	{
		for(int i=l; i<=r; i++)
			if(a[i] != 0) ans.push_back(pii(i, i));
		move(l, r);
	}
	else if(split[l][r] > 0)
	{
		output(l, split[l][r]);
		output(split[l][r]+1, r);
	}
}
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
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for(int i=1; i<=n; i++)
	{
		dp[i][i] = max(1, a[i]);
		split[i][i] = (a[i] == 0? 0: -1);
	}
	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=n-i+1; j++)
		{
			int &cur = dp[j][j+i-1];
			cur = i*i;
			for(int k=j; k<=j+i-2; k++)
				if(cur < dp[j][k] + dp[k+1][j+i-1])
				{
					cur = dp[j][k] + dp[k+1][j+i-1];
					split[j][j+i-1] = k;
				}
		}
	}
	printf("%d ", dp[1][n]);
	ans.clear();
	output(1, n);
	printf("%d\n", ans.size());
	for(pii i: ans) printf("%d %d\n", i.first, i.second);
	#endif
 	return 0;
}
