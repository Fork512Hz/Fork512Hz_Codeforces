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

#define DEBUG

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif
// const ll M = 998244353;
ll ans[N];
ll a[N];
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
		for(int i=1; i<n; i++)
			scanf("%lld", &a[i]);
		ans[1] = (a[2]+2)*a[1] + a[1];
		ans[0] = ans[1] - a[1];
		a[n] = 0;
		for(int i=2; i<n; i++)
		{
			int diff = a[i] - (a[i+1] % ans[i-1]);
			ans[i] = a[i+1] + diff;
			if(diff <= 0) ans[i] += ans[i-1];
		}
		for(int i=0; i<n; i++)
			printf("%d ", ans[i]);
		printf("\n");
    }
 	return 0;
}
