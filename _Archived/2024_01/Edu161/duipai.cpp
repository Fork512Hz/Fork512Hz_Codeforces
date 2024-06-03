#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
ll n;
const int inf = 0x7fffffff;
const ll N = 300100;
int atk[N], def[N], previous[N], succ[N], dmg[N];
int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int z;
	cin >> z;
	while(z--)
	{
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) scanf("%d", &atk[i]);
		for(int i=1; i<=n; i++) scanf("%d", &def[i]);
		for(int i=1; i<=n; i++) 
		{
			previous[i] = i-1;
			succ[i] = i+1;
		}
		atk[0] = 0;
		def[0] = inf;
		atk[n+1] = 0; 
		def[n+1] = inf;
		bool flag = 0;
		for(int i=1; i<=n; i++)
		{
			int ans=0; 
			if(flag) goto skip;
			for(int x=1; x<=n; x++)if(previous[x] != -1)
			{
				dmg[x] = atk[previous[x]] + atk[succ[x]];
			}
			for(int x=1; x<=n; x++) if(dmg[x] > def[x] && previous[x] != -1)
			{
				ans++;
				previous[succ[x]] = previous[x];
				
				succ[previous[x]] = succ[x];
				
				previous[x] = -1;
				succ[x] = -1;
			}
			skip:
			printf("%d ", ans);
			if(ans == 0) flag = 1;
		}
		printf("\n");
	}
 	return 0;
}
