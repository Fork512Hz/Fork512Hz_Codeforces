#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<functional>
#include<map>
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
const long long N = 300100;
#endif
// const ll M = 998244353;
string grid[N];
const ll M = 834654572229097;
const ll M2 = 10000000;
map<ll, ll> valuetable, postable;
ll pow2[N];
inline ll decode(char x)
{
	return x-48;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    pow2[0] = 1;
    for(int i=1; i<=N-10; i++)
    	pow2[i] = (pow2[i-1] << 1) % M;
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++)
			cin >> grid[i];
		valuetable.clear();
		postable.clear();
		for(int j=0; j<m; j++)
		{
			ll basehash = 0;
			for(int i=0; i<n; i++)
			{
				basehash += decode(grid[i][j]) * pow2[i];
				basehash %= M;
			}
			for(int i=0; i<n; i++)
			{
				ll hashvalue = basehash;
				if(grid[i][j] == '0')
					hashvalue = (hashvalue + pow2[i]) % M;
				else
					hashvalue = (hashvalue + M - pow2[i]) % M;
				valuetable[hashvalue] ++;
				postable[hashvalue] = i*M2 + j;
			}
		}
		pair<ll, ll> maxa = {-1, -1};
		for(pair<ll, ll> i: valuetable) if(i.second > maxa.second)
			maxa = i;
		printf("%lld\n", maxa.second);
		ll im = postable[maxa.first] / M2;
		ll j = postable[maxa.first] % M2;
		for(int i=0; i<n; i++)
		{
			if(i != im) printf("%c", grid[i][j]);
			else printf("%c", 97 - grid[i][j]);
		}
		printf("\n");
    }
 	return 0;
}
