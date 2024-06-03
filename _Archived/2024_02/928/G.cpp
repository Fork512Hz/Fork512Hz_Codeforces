#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 100100;
#endif
int parent[N], type[N];
vector<int> conn[N];
int ans;
void dfs(int x, int par)
{
	int k1, k2;
	k1 = 0;
	k2 =0;
	for(int i: conn[x]) if(i != par)
	{
		dfs(i, x);
		if(type[i] == 1) k1++;
		if(type[i]==2) k2++;
	}
	switch(type[x])
	{
		case 1: ans += k2; break;
		case 2: ans += k1; break;
		case 0: 
			ans += min(k1, k2);
			if(k1 > k2) type[x] = 1;
			if(k1 < k2) type[x] = 2;
			break;
	}
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
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
		{
			conn[i].clear();
		}
		parent[1] = 0;
		type[0] = 100;
		for(int i=2; i<=n; i++) 
		{
			scanf("%d", &parent[i]);
			conn[parent[i]].push_back(i);
		} 
		string s;
		cin >> s;
		for(int i=1; i<=n; i++) switch(s[i-1])
		{
			case 'C': type[i] = 0; break;
			case 'S': type[i] = 1; break;
			default: type[i] = 2;
		}
		ans = 0;
		dfs(1, -1);
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
