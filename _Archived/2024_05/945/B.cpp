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
const long long N = 100100;
#endif
// const ll M = 998244353;
int pfs[22][N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
		{
			int x;
			scanf("%d", &x);
			for(int j=0; j<20; j++)
				pfs[j][i] = pfs[j][i-1] + ((x >> j) & 1);
		}
		int l = 1, r = n;
		while(l <= r)
		{
			bool check = 1;
			int m = (l+r) /2;
			int pivot = 0;
			for(int j=0; j<20; j++)
				if(pfs[j][m]) pivot |= (1<<j);
			for(int i=m+1; i<=n; i++)
			{
				int v = 0;
				for(int j=0; j<20; j++)
					if(pfs[j][i] - pfs[j][i-m]) 
						v |= (1<<j);
				if(v != pivot)
				{
					check = 0;
					break;
				}
			}
			if(check) r = m - 1;
			else l = m + 1;
			
		}
		printf("%d\n", l);
		
    }
 	return 0;
}
