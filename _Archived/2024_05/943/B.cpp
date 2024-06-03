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

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		int n, m;
		scanf("%d%d", &n, &m);
		string a, b;
		cin >> a >> b;
		int i=0, j=0;
		for(; i<n; i++)
		{
			for(; j<m; j++)
				if(b[j] == a[i])
				{
					j++;
					goto nextcont;
				}
			if(j >= m) break;
			nextcont:;
		}
		printf("%d\n", i);
    }
 	return 0;
}
