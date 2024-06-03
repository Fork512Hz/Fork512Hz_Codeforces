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
int a[40];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		int x;
		scanf("%d", &x);
		for(int i=0; i<31; i++) a[i] = (x >> i) & 1;
		a[31] = 0;
		a[32] = 0;
		int l = 0, r = 0;
		while(r < 31)
		{
			while(r < 31 && a[r]) r++;
			if(r - l >= 2)
			{
				a[l] = -1;
				for(int i = l+1; i < r; i++) a[i] = 0;
				a[r] = 1;
				l = r;
			}
			else
			{
				r++; l=r;
			}
		}
		printf("32\n");
		for(int i=0; i<32; i++)
			printf("%d ", a[i]);
		printf("\n");
    }
 	return 0;
}
