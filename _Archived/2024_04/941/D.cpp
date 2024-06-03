#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long ll;
//#define DEBUG

#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n, k;
		scanf("%d%d", &n, &k);
		vector<int> ans;
		int s = 0;
		while(((s << 1) | 1) < k)
		{
			ans.push_back(s+1);
			s = ((s << 1) | 1);
		}
		if(k-1 > s) ans.push_back(k-1-s);
		if(k <= n)ans.push_back(k+1);
		if(2*k + 1 <= n) ans.push_back(2*k + 1);
		s = 3*k + 1;
		while(s <= n)
		{
			ans.push_back(s);
			s <<= 1;
		}
		printf("%d\n", ans.size());
		for(int i: ans) printf("%d ", i);
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
