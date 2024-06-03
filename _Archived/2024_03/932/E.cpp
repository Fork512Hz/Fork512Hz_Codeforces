#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
typedef vector<long long> vll;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif
ll x[N], y[N];
ll w[N][32], pfs[N][32];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    //int cntg = 0;
    //bool flag = (z == 20000);
    while(z--){
		ll n;
		scanf("%lld", &n);
		for(int i=0; i<=n; i++)
			for(int j=0; j<=30; j++)
			{
				w[i][j] = 0;
				pfs[i][j] = 0;
			}
		for(int i=1; i<=n; i++) 
		{
			scanf("%lld%lld", &x[i], &y[i]);
			for(int j=30; j>=0; j--)
			{
				w[i][j] = w[i-1][j];
				pfs[i][j] = pfs[i-1][j];
			}
			bool pf = 0;
			ll t = 0;
			for(int j=30; j>=0; j--)
			{
				bool p = (x[i]>>j) & 1ll;
				bool q = (y[i]>>j) & 1ll;
				if(p||q) pf = 1;
				if(p&&q) 
				{
					w[i][j] ++;
					t += 1ll<<j;
				}
				if(! ( (p&&q) || (!p && !q && !pf) ) ) break;
			}
			t = y[i] - t;
			for(int j=30; j>=0; j--)
			{
				bool q = (t>>j) % 2 == 1;
				if(q) pfs[i][j] ++;
			}
		}
		int Q;
		scanf("%d", &Q);
		for(int i=1; i<=Q; i++)
		{
			ll l, r;
			scanf("%lld%lld", &l, &r);
			ll ans1 = 0;
			for(int j=30; j>=0; j--) 
				if(w[r][j] > w[l-1][j])
					ans1 |= 1ll<<j;
			ll ans2 = 0;
			for(int j=30; j>=0; j--) 
				switch(pfs[r][j] - pfs[l-1][j])
				{
					case 0: break;
					case 1: 
						if(ans1 >> j & 1)
						{
							ans2 |= (1ll<<j) - 1;
							goto fin;
						}
						else ans2 |= 1ll << j; 
						break;
					case 2: 
						ans2 |= 1ll << j;
						ans2 |= (1ll << j) -1;
						goto fin;
				}
			fin:
			//cntg ++;
			printf("%lld ", ans1|ans2);
			/*printf("%lld\n", ans1 | ans2);
			printf("%lld %lld\n", ans1, ans2);
			for(int j=0; j<n; j++) printf("%lld ", x[j]);
			printf("\n");
			for(int j=0; j<n; j++) printf("%lld ", y[j]);
			printf("\n");
			printf("%lld %lld\n", l, r);
			for(int j=0; j<=3; j++)
			    for(int k=0; k<=3; k++)
			        printf("%d ", w[j][k]);
			printf("\n");
			for(int j=0; j<=3; j++)
			    for(int k=0; k<=3; k++)
			        printf("%d ", pfs[j][k]);*/
			
		}
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
