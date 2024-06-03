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
int mid(int x, int y, int z)
{
	if(x > y) swap(x, y);
	if(x > z) swap(x, z);
	if(y > z) swap(y, z);
	return y;
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
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
		int ans = -1;
		for(int i=0; i<n-1; i++)
			ans = max(ans, min(a[i], a[i+1]));
		for(int i=0; i<n-2; i++)
			ans = max(ans, mid(a[i], a[i+1], a[i+2]));
		printf("%d\n", ans);
    }
 	return 0;
}
