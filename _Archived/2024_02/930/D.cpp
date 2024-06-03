#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
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
const long long N = 500100;
#endif
string s;
ll ronl[N], lonr[N];
vector<ll> lidx, ridx, pfs, sfs;

inline ll lsolve(ll x, ll lb, ll rb)
{
	return x * (rb-lb) - (pfs[rb] - pfs[lb]);	
}

inline ll rsolve(ll x, ll lb, ll rb)
{
	return sfs[rb] - sfs[lb] - x * (rb-lb);
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    ll z;
    cin >> z;
    while(z--){
		ll n;
		scanf("%lld", &n);
		cin >> s;
		lidx = {-1};
		ridx = {n};
		pfs = {0};
		sfs = {0};
		ll t1, t2;
		t1 = 0;
		t2 = 0;
		for(ll i=0; i<n; i++)
		{
			ronl[i] = t1;
			if(s[i] == '>')
			{
				t1++;
				t2 += i;
				lidx.push_back(i);
				pfs.push_back(t2);
			}
		}
		
		t1 = 0;
		t2 = 0;
		for(ll i=n-1; i>=0; i--)
		{
			lonr[i] = t1;
			if(s[i] == '<')
			{
				t1++;
				t2 += i;
				ridx.push_back(i);
				sfs.push_back(t2);
			}
		}
		
		for(ll i=0; i<n; i++) if(s[i] == '<')
		{
			ll ans;
			if(lonr[i] >= ronl[i])
			{
				ans = i+1;
				ans += 2*lsolve(i, 0, ronl[i]);
				ans += 2*rsolve(i, lonr[i] - ronl[i], lonr[i]);
			}
			else 
			{
				ans = n-i;
				ans += 2*rsolve(i, 0, lonr[i]);
				ans += 2*lsolve(i, ronl[i] - lonr[i] - 1, ronl[i]);
			}
			printf("%lld ", ans);
		}
		else
		{
			ll ans;
			if(lonr[i] > ronl[i])
			{
				ans = i+1;
				ans += 2*lsolve(i, 0, ronl[i]);
				ans += 2*rsolve(i, lonr[i] - ronl[i] - 1, lonr[i]);
			}
			else 
			{
				ans = n-i;
				ans += 2*rsolve(i, 0, lonr[i]);
				ans += 2*lsolve(i, ronl[i] - lonr[i], ronl[i]);
			}
			printf("%lld ", ans);
		}
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
