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
const long long N = 100100;
#endif
ll a[N];
ll bitpfs[N][32];
ll highpfs[N][32];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    freopen("3.txt", "w", stdout);
    #endif
    #ifdef MULTI
    ll z;
    cin >> z;
    while(z--){
		ll n;
		scanf("%lld", &n);
		for(ll i=1; i<=n; i++)
			scanf("%lld", &a[i]);
		for(ll i=0; i<32; i++)
		{
			bitpfs[0][i] =0;
			highpfs[0][i] = 0;
		}
		ll ans = 0;
		for(ll i=1; i<=n; i++)
		{
			ll hb = -1;
			for(ll j=0; j<=30; j++) if(a[i] & (1<<j))
			{
				hb = j;
				bitpfs[i][j] = bitpfs[i-1][j] + 1;
			}
			else
			{
				bitpfs[i][j] = bitpfs[i-1][j];
			}
			for(ll j=0; j<=30; j++)
				highpfs[i][j] = highpfs[i-1][j] + (hb == j);
		}
		for(ll j=0; j<=30; j++)
		{
			ll oddprev = -1; 
			ll evenprev = 0;
			ll oddsum = 0;
			ll evensum = 0;
			ll oddcnt = 0;
			ll evencnt = 1;
			for(ll i=1; i<=n; i++)
			{
				bool flag = 0;
				if(bitpfs[i][j] > bitpfs[i-1][j])
				{
					
					if(bitpfs[i][j] & 1)
					{
						
						if(bitpfs[i][j] > 1) 
						{
							oddsum += (highpfs[i][j] - highpfs[oddprev][j]) * oddcnt; 
						}
						oddprev = i;
						oddcnt ++ ;
					}
					else
					{
						
						evensum += (highpfs[i][j] - highpfs[evenprev][j]) *  evencnt;
						evenprev = i;
						evencnt ++;
					}
					
				}
				else 
				{
					if(bitpfs[i][j] & 1) oddcnt ++;
					else evencnt ++;
 				}
				if(bitpfs[i][j] & 1)
					ans += oddsum;
				else
					ans += evensum;
				
			}
		}
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
