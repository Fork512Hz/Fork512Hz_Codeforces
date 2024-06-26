#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<deque>
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
const int M = 200;
ll a[N];
ll ans[N]; 
deque<pii> monoque;
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int m, n, k, d;
		scanf("%d%d%d%d", &m, &n, &k, &d);
		for(int y=0; y<m; y++)
		{
			for(int i=0; i<n; i++) 
			{
				ll x;
				scanf("%lld", &x);
				a[i] = x+1;
			}
			monoque = {pii(0, 1)};
			for(int i=1; i<n; i++)
			{
				if(!monoque.empty())
					if(i - monoque.front().first > d+1)
						monoque.pop_front();
				ll cost = a[i] + monoque.front().second;
				while(!monoque.empty() && cost <= monoque.back().second)
					monoque.pop_back();
				monoque.push_back(pii(i, cost));
			}
			ans[y] = monoque.back().second;
		}
		ll res, sum;
		sum = 0;
		for(int i=0; i<k; i++) sum += ans[i];
		res = sum;
		for(int i=k; i<m; i++)
		{
			sum += ans[i] - ans[i-k];
			res = min(res, sum);
		}
		printf("%lld\n", res);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
