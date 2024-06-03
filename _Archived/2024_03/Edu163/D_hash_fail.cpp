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
const ll X = 322122557;
const ll M = 998244353;
const long long tb[30] = 
{201864497,	201864503,	201864589,	201864631,	201864667,	201864697,	201864701,	201864703,	201864709,	201864779,
201864811,	201864823,	201864889,	201864893,	201864917,	201864941,	201864959,	201864977,	201864983,	201865049,
201865073,	201865093,	201865109,	201865117,	201865127,	201865133};
//All the above are primes
#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 5200;
#endif
ll his[N];

ll pw[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    ll z;
    cin >> z;
    pw[0] = 1;
    for(ll i=1; i<N; i++) pw[i] = pw[i-1] * X % M;
    while(z--){
    	
    	string s;
    	cin >> s;
    	ll n = s.size();
    	for(ll i=n/2; i>=1; i--)
    	{
    		string t = s;
    		ll hsh = 0;
    		ll j;
    		//Rolling hash
    		for(j=0; j<i; j++)
    		{
    			hsh *= X;
    			if(s[j] != '?')
    				hsh = (hsh + tb[s[j] - 97]) % M;
    			else 
    			{
    				hsh = (hsh +tb[0] ) % M;
    				t[j] = 'a'; //Temporary assignment
				}
				hsh %= M;
			}
			his[j-1] = hsh;
			ll cng = 0;
			ll prev = i;
			for(; j<n; j++)
			{
				if(s[j] != '?' && s[j-i] == '?')
				//Current character is ? but previous matching is not
				{
					cng = cng * pw[j-prev] % M;
					cng = (cng + tb[s[j] - 97] - tb[t[j-i] - 97]) % M;
					prev = j;
					hsh = hsh * X  % M;
				}
				else if(s[j] == '?') t[j] = t[j-i];//Temporary assignment
				
				hsh = hsh * X  % M;
				hsh = (hsh + M - (tb[t[j-i] - 97] * pw[i] % M)) % M;
				hsh = (hsh + tb[t[j] - 97]) % M;
				his[j] = hsh;
				if(j >= 2*i-1)
				{
					ll tocomp = his[j-i];
					if(j-i <= prev)
						tocomp = (tocomp + M + cng * pw[j-prev] % M) % M; 
					tocomp = (tocomp + M) % M; 
					if(hsh == tocomp)
					{
						printf("%d\n", i*2);
						goto fin;
					}
				}
			}
		}
		printf("0\n");
		fin:;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
