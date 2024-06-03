#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<functional>
#include<deque>
#include<map>
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
const long long N = 200100;
#endif
// const ll M = 998244353;
map<int, set<int>> mp;
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
		int n, q;
		scanf("%d%d", &n, &q);
		a[0] = 0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &a[i]);
			a[i] = a[i-1] ^ a[i];
		}
		mp.clear();
		for(int i=0; i<=n; i++)
		{
			auto it = mp.find(a[i]);
			if(it == mp.end())
			{
				set<int> x = {i};
				mp[a[i]] = x;
			}
			else mp[a[i]].insert(i);
		}
		for(int y=0; y<q; y++)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			l--;
			if(a[l] == a[r])
				printf("YES\n");
			else
			{
				auto itl = mp[a[l]].upper_bound(r);
				itl --;
				auto itr = mp[a[r]].upper_bound(l);
				if(*itr < *itl)
					printf("YES\n");
				else printf("NO\n");
			}
		}
		printf("\n");
    }
 	return 0;
}
