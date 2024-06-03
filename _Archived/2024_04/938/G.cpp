#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
#include<deque>
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
int a[N][N];
bool dp[N][N];
int gcd(int x, int y)
{
	int p = x, q = y;
	if(p > q) swap(p, q);
	int t;
	while(p)
	{
		t = q%p;
		q=p; p=t;
	}
	return q;
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
		int n, m;
		scanf("%d%d", &n ,&m);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++) scanf("%d", &a[i][j]);
		int t = gcd(a[1][1], a[n][m]);
		deque<int> f = {};
		int rt = floor(sqrt(t) + 0.5);
		if(rt * rt == t) 
		{
			f.push_back(rt);
			rt--;
		}
		for(int i=rt; i>=1; i--)
			if(t % i == 0)
			{
				f.push_back(i);
				f.push_front(t/i);
			}
		for(int k: f)
		{
			dp[1][1] = 1;
			for(int s = 3; s <= n+m; s++)
			{
				bool flag = 0;
				for(int i = max(1, s-m); i <= min(n, s-1); i++)
				{
					dp[i][s-i] = (a[i][s-i] % k == 0) && (dp[i-1][s-i] || dp[i][s-i-1]);
					flag |= dp[i][s-i];
				}
				if(!flag) goto nextk;
			}
			printf("%d\n", k);
			break;
			nextk:;
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
