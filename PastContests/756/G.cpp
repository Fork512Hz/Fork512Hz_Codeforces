#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<set>
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
const long long N = 1000100;
#endif
char* a[N];
vector<pii> candies[2];
int solve(vector<pii>& vec)
{
	//Blocking missiles Part2 NOIP1999
	set<int> robots = {};
	for(pii i: vec)
	{
		auto it = robots.upper_bound(i.first - i.second);
		
		if(it == robots.begin())
			robots.insert(i.first - i.second);
		else
		{
			it--;
			robots.erase(it);
			robots.insert(i.first - i.second);
		}
	}
	return (int) robots.size();
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++)
		{
			a[i] = (char*)calloc(m+3, sizeof(char));
		}
		candies[0].clear();
		candies[1].clear();
		for(int i=0; i<n; i++)
			scanf("%s", a[i]);
		for(int diag=0; diag<=(n+m-2); diag++)
		{
			int maxi = min(n-1, diag);
			int mini = max(0, diag-m-1);
			for(int i=mini; i<=maxi; i++) if(a[i][diag-i] == '1')
				candies[diag%2].push_back(pii(i, diag/2));
		}
		int ans = solve(candies[0]);
		ans += solve(candies[1]);
		printf("%d\n", ans);
		
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
