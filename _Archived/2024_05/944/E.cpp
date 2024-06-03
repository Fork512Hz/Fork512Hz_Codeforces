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
vector<ll> s, t;
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		ll n, k, q;
		scanf("%lld%lld%lld", &k, &n,&q);
		s = {0};
		t = {0};
		for(int i=0; i<n; i++)
		{
			ll x;
			scanf("%lld", &x);
			s.push_back(x);
		}
		for(int i=0; i<n; i++)
		{
			ll x;
			scanf("%lld", &x);
			t.push_back(x);
		}
		for(int p=0; p<q; p++)
		{
			ll pos;
			scanf("%lld", &pos);
			int l = 0, r = n;
			while(r-l > 1)
			{
				int m = (l+r) / 2;
				if(pos < s[m]) r = m;
				else l = m;
				
			}
			ll interpol = (t[r] - t[l]) * (pos - s[l]) / (s[r] - s[l]);
			printf("%lld ", t[l] + interpol);
		}
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
