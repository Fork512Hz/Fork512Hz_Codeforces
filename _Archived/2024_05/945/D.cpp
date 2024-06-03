#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<functional>
#include<deque>
#include<set>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vll;
typedef long long ll;
typedef long long i64;

//#define DEBUG

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif
// const ll M = 998244353;
void query(int l, int x)
{
	printf("? %d %d\n", l, x);
	fflush(stdout);
}
int rd()
{
	int t;
	scanf("%d", &t);
	if(t == -1) exit(10);
	return t;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		int n,k;
		scanf("%d%d", &n, &k);
		int mx;
		for(mx=1; mx<=n; mx++)
		{
			query(1, mx*n);
			int q = rd();
			if(q == n) break;
		}
		for(int i=1; i<=n/k; i++)
		{
			int t=1;
			for(int j=1; j<=k; j++)
			{
				query(t, mx * i);
				int q = rd();
				if(q == n && j == k) break;
				if(q >= n || j == k) goto nexti;
				
				t = q + 1;	
			}	
			printf("! %d\n", mx*i);
			fflush(stdout);
			goto fin;
			nexti:;
		}	
		printf("! -1\n");
		fflush(stdout);
		fin:;
		rd();
    }
 	return 0;
}
