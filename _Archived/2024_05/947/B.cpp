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
int a[N];
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
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n);
		vector<int> v2;
		for(int i=1; i<n; i++) if(a[i] % a[0])
			v2.push_back(a[i]);
		if(v2.size() >= 2)
		{
			int m = v2.size();
			for(int j=1; j<m; j++) if(v2[j] % v2[0])
			{
				printf("No\n");
				goto fin;
			}
			printf("Yes\n");
		}
		else printf("Yes\n");
		fin:;
    }
 	return 0;
}
