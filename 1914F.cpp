#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<queue>
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
const long long N = 200100;
#endif
vector<int> tree[N];
int subsize[N];

class cmp{
public:
	bool operator()(int x, int y)
	{
		return subsize[x] < subsize[y];
	}
};
priority_queue<int, vector<int>, cmp> pq;
int dfs(int x)
{
	int _size = 1;
	for(int i: tree[x]) _size += dfs(i);
	subsize[x] = _size;
	return _size;
}
inline void disassemble(int x)
{
	for(int i: tree[x]) pq.push(i);
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
		for(int i=1; i<=n; i++) tree[i].clear();
		for(int i=2; i<=n; i++)
		{
			int x;
			scanf("%d", &x);
			tree[x].push_back(i);
		}
		dfs(1);
		pq.push(1);
		int ans = 0;
		while(!pq.empty())
		{
			if(pq.size() >= 2)
			{
				ans++;
				int t1 = pq.top();
				pq.pop();
				int t2 = pq.top();
				pq.pop();
				disassemble(t1);
				disassemble(t2);
			}
			else
			{
				int t = pq.top();
				pq.pop();
				disassemble(t);
			}
		}
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
