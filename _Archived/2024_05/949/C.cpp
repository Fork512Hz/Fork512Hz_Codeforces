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
const long long N = 500100;
#endif
// const ll M = 998244353;
inline ll highbit(ll x)
{
	return 64 - __builtin_clzll(x);
}
ll a[N], ans[N];
ll n;
int solve(ll l, ll r)
{
	if(l == -1)
	{
		ll t = a[r];
		for(ll i=0; i<r; i++)
		{
			if((i+r) % 2)
				ans[i] = 2*t;
			else ans[i] = t;
		}
		
	}
	else if(r == n)
	{
		ll t = a[l];
		for(ll i=l+1; i<n; i++)
		{
			if((i-l) % 2) ans[i] =  2*t;
			else ans[i] = t;
		}
	}
	else
	{
		ll lv = a[l], rv = a[r];
		if(l + 1 == r)
		{
			if((lv == rv/2) || (rv == lv/2)) return 0;
			else return -1;
		}
		
		ll bitdiff = abs(highbit(lv)  - highbit(rv));
		if((bitdiff + (r-l)) % 2) return -1;
		if(bitdiff > r-l) return -1;
		int i = l+1, j = r-1;
		while(lv != rv)
		{
			
			if(lv > rv)
			{
				lv >>= 1;
				ans[i] = lv;
				i++;
			}
			else
			{
				rv >>= 1;
				ans[j] = rv;
				j--;
			}
			
		}
		
		i--; j++; if(i > j) return -1;
		int t = ans[i];
		for(int k=i; k<=j; k++)
		{
			if((k-i) % 2) ans[k] = 2*t;
			else ans[k] = t;
		}
	}
	return 0;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    ll z;
    //z = 1;
    cin >> z;
    while(z--){
		
		scanf("%lld", &n);
		for(ll i=0; i<n; i++)
			scanf("%lld", &a[i]);
		vector<ll> posts;
		posts.push_back(-1);
		for(ll i=0; i<n; i++)
		{
			if(a[i] != -1)
				posts.push_back(i);
		}
		posts.push_back(n);
		ll m = posts.size();
		if(m == 2)
		{
			for(ll i=0; i<n; i++)
				printf("%d ", i%2 + 1);
			printf("\n");
			continue;
		}
		for(ll i=0; i<m-1; i++)
		{
			if(posts[i] != -1 && posts[i] != n)
				ans[posts[i]] = a[posts[i]];
			int tmp = solve(posts[i], posts[i+1]);
			if(tmp == -1)
			{
				printf("-1\n");
				goto fin;
			}
		}
		for(ll i=0; i<n; i++)
			printf("%d ", ans[i]);
		printf("\n");
		fin:;
    }
 	return 0;
}
