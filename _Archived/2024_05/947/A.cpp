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
		int cnt = 0;
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
		for(int i=1; i<n; i++)
			if(a[i]<a[i-1]) cnt++;
		switch(cnt)
		{
			case 0:
				printf("Yes\n");
				break;
			case 1:
				if(a[n-1] <= a[0])
					printf("Yes\n");
				else printf("No\n");
				break;
			default:
				printf("No\n");
		}
    }
 	return 0;
}
