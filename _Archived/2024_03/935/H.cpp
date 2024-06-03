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
const long long N = 400100;

#endif
const int M = 19;
int n;
int a[N], pfs[N], sfs[N], cnt[N];
bool vis[N];
vector<int> zerobit[M];
int gcd(int p, int q)
{
	int t, x, y;
	x=p; y=q;
	if(x>y) 
	{
		t=x; x=y; y=t;
	}
	while(x)
	{
		t=y; y=x; x=t%y;
	}
	return y;
}
void output(int p, int q)
{
	printf("YES\n2 %d %d\n%d ", a[p], a[q], n-2);
	for(int i=1; i<=n; i++) if(i!=p && i!=q)
		printf("%d ", a[i]);
	printf("\n");
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    //bool flag = 1;
    while(z--){
    	//if(z == 4999) flag = 0;
    	for(int i=0; i<M; i++) zerobit[i] .clear();
    	int w, maxa, blue;
		scanf("%d%d", &n, &w);
		memset(vis, 0, n+5);
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		/*if(!flag && z == 4962)
		{
			printf("%d %d\n", n, w);
			for(int i=1; i<=n; i++) printf("%d ", a[i]);
			return -1000;
		}*/
		pfs[0] = 0x7fffffff;
		sfs[n+1] = 0x7fffffff;
		maxa = 0;
		for(int i=n; i>=1; i--) sfs[i] = sfs[i+1] & a[i];
		for(int i=1; i<=n; i++)
		{
			pfs[i] = pfs[i-1] & a[i];
			maxa = max(a[i], maxa);
			for(int j=0; j<M; j++) if(! (a[i] & (1<<j)))
				zerobit[j].push_back(i);
		}	
		for(int i=0; i<M; i++) if(zerobit[i].size() <= 2)
			for(int j: zerobit[i])
			{
				vis[j] = 1;
				int ans = pfs[j-1];
				for(int k = j+1; k<=n; k++)
				{
					blue = (ans & sfs[k+1]) + w;
					if(gcd(a[j], a[k]) > blue)
					{
						//0if(flag) 
							output(j, k);
						goto fin;
					}
					ans &= a[k];
				}
				ans = sfs[j+1];
				for(int k = j-1; k>=1; k--)
				{
					blue = (ans & pfs[k-1]) + w;
					if(gcd(a[j], a[k]) > blue)
					{
						//if(flag) 
							output(j, k);
						goto fin;
					}
					ans &= a[k];
				}
			}
		memset(cnt, 0, sizeof(int) * (maxa+5));
		for(int i=1; i<=n; i++) if(!vis[i])
			cnt[a[i]] ++;
		blue = pfs[n] + w;
		for(int i = maxa; i > blue; i--)
		{
			int factorcnt = 0;
			for(int j=i; j<=maxa; j+=i) factorcnt += cnt[j];
			if(factorcnt >= 2)
			{
				int out1, out2, tmp;
				tmp = 0;
				for(int k=1; k<=n; k++) if(!vis[k] && a[k]%i == 0)
				{	
					if(tmp == 0)
					{
						tmp = 1;
						out1 = k;
					}
					else
					{
						out2 = k;
						//if(flag) 
							output(out1, out2);
						goto fin;
					}
				}	
			}
		}
		//if(flag) 
			printf("NO\n");
		fin:;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
