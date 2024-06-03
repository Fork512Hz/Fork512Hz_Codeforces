#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<deque>
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
const long long N = 200100;
#endif
string s[2];
bool vis[N*2];
deque<int> bfs;
void move(int x, int y)
{
	int p, q;
	p = x;
	q = s[x][y] == '<'? y-1: y+1;
	int idx = q*2+p;
	if(!vis[idx]) 
	{
		vis[idx] = 1;
		bfs.push_back(idx);
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
		cin >> s[0] >> s[1];
		memset(vis, 0, 2*(n+5));
		bfs = {0};
		while(!bfs.empty()){
			int cur = bfs.front();
			bfs.pop_front();
			int l = cur % 2;
			int col = cur / 2;
			if(l == 0) move(1, col);
			if(l == 1) move(0, col);
			if(col != 0) if(s[l][col-1] == '<') move(l, col-1);
			if(col != n-1) if(s[l][col+1] == '>')move(l, col+1);
		}
		if(vis[2*n-1]) printf("YES\n");
		else printf("NO\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
