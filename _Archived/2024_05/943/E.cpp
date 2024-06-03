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
		int n;
		scanf("%d", &n);
		switch(n)
		{
			case 2:
				printf("1 1\n2 1\n");
				break;
			case 3:
				printf("1 1\n2 1\n2 3\n");
				break;
			default:
				printf("1 1\n1 2\n4 2\n");
				for(int i=4; i<=n; i++) printf("%d %d\n", i, i);
		}
		printf("\n");
    }
 	return 0;
}
