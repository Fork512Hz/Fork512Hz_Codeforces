#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<chrono>
#include<utility>
#include<ctime>
#include<cstdlib>
#include<random>
#include<deque>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long ll;
//#define DEBUG

#define MULTI

#ifdef DEBUG
const long long N = 16;
#endif
#ifndef DEBUG
const long long N = 16;
#endif
const long long modulos[30] =
{
201950224459,	201950224517,	201950224543,	201950224561,	201950224571,	201950224573,	201950224661,	201950224669,	201950224703,	201950224727,
201950224733,	201950224741,	201950224783,	201950224789,	201950224823,	201950224829,	201950224843,	201950224871,	201950224891,	201950224907,
201950224909,	201950224943,	201950224967,	201950224999,	201950225033,	201950225093,	201950225111,	201950225149,	201950225159,	201950225167
};
/*const long long bases[29] =
{
	59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197
};*/
string s1, s2;
ll g[N+1], w[N+1];
ll B, M;
bool vis[(1<<N) + 100][N+1];
bool graph[N+1][N+1]; //Adjacency matrix
ll myHash(string s)
{
	ll tmp = 0;
	ll t = s.size();
	for(int i=0; i<t; i++)
	{
		tmp *= B;
		tmp += (ll)(s[i] - 96);
		tmp %= M;
	}
	return tmp;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    std::mt19937 myRand(__builtin_ia32_rdtsc());
    int z;
    cin >> z;
    //bool fl = 0;
    while(z--){
        B = 30 + myRand() % 4000;
    	M = modulos[myRand() % 30];
		int n;
		scanf("%d", &n);
		//if(z == 999 &&n == 3 ) fl = 1;
		//if(z == 406 && fl) printf("%d\n", n);
		for(int i=0; i<n; i++)
		{
			cin >> s1 >> s2;
			//if(z == 406 && fl) cout << s1 << ' ' << s2 << '\n';
			g[i] = myHash(s1);
			w[i] = myHash(s2);
		}
		//if(z == 406 && fl) return -1000;
		memset(graph, 0, sizeof(graph));
		for(int i=0; i<n-1; i++)
			for(int j=i+1; j<n; j++)
				if(g[i] == g[j] || w[i] == w[j]) 
				{
					graph[i][j] = 1;
					graph[j][i] = 1;
				}
		for(int i=0; i<(1<<n); i++)
			memset(vis[i], 0, n);
		deque<pii> bfs = {pii(-1, -1)};
		int depth = 0;
		for(int i=0; i<n; i++)
		{
			bfs.push_back(pii(1<<i, i));
			vis[1<<i] [i] = 1;
		}
			
		while(bfs.size() > 1)
		{
			pii cur = bfs.front();
			bfs.pop_front();
			if(cur.first == -1)
			{
				depth++;
				bfs.push_back(cur);
				continue;
			}
			int tip = cur.second;
			for(int i=0; i<n; i++) 
				if( ( graph[tip][i] ) && 
				( (cur.first & (1<<i)) == 0) && 
				( !vis [cur.first + (1<<i)][i] )  )
				{
					bfs.push_back( pii(cur.first + (1<<i), i));
					vis[cur.first + (1<<i)][i] = 1;
				}
		}
		printf("%d\n", n-depth);
	}  
    
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
