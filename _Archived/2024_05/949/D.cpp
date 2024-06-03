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
const long long N = 300100;
#endif
// const ll M = 998244353;
vector<ll> minp, primes;
void sieve(ll n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (ll i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}
ll edgecnt[N];
bool vis[3100][3100];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    //freopen("2.txt", "w", stdout);
    ll z;
    //z = 1;
    cin >> z;
    //primes.push_back(1);
    sieve(300000);
    ll PRIME_SIZE = primes.size();
    edgecnt[0] = 0;
    edgecnt[1] = 1;
    edgecnt[2] = 3;
    for(ll i=3; i<PRIME_SIZE; i++)
    	edgecnt[i] = i * (i+1)/2 - (i%2? 0: (i/2-1));
    while(z--){
		ll n;
		scanf("%lld", &n);
		n--;
		ll *it = lower_bound(edgecnt, edgecnt+PRIME_SIZE, n);
		vector<ll> eulerroad;
		ll v = it - edgecnt;
		ll steps = 0;
		ll p = 0;
		for(ll i=0; i<v; i++) 
			memset(vis[i], 0, v);
		eulerroad.push_back(0);
		
		for(ll p=0; p<v; p++)
		{
			eulerroad.push_back(p);
			steps++;
			if(steps >= n) goto fin;
			for(ll i=2; i*2<v; i++) if(!vis[p][i])
			{
				ll k = p;
				do
				{
					ll k1 = (k+i) % v;
					vis[k][i] = 1;
					eulerroad.push_back(k1);
					steps++;
					if(steps >= n) goto fin;
					k = k1;
					
				}
				while(k != p);
			}
			eulerroad.push_back((p+1) % v);
			steps++;
			if(steps >= n) goto fin;
		}
	
		
		if(v % 2 == 0) 
			eulerroad.push_back(v/2);
		
		fin:
		for(ll i: eulerroad)
			printf("%d ", primes[i]);
		printf("\n");
    }
 	return 0;
}
