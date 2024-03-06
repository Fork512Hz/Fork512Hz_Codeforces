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
bool dirty[N];
vector<int> todo[2];
int main()
{
	//freopen("1.txt", "r", stdin);
	//freopen("bad.txt", "w", stdout);
	int z;
	cin >> z;
	while(z--)
	{
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) scanf("%d", &atk[i]);
		for(int i=1; i<=n; i++) scanf("%d", &def[i]);
		todo[1].clear();
		for(int i=1; i<=n; i++) 
		{
			todo[1].push_back(i);
			previous[i] = i-1;
			succ[i] = i+1;
			dirty[i] = 0;
		}
		atk[0] = 0;
		def[0] = inf;
		atk[n+1] = 0; 
		def[n+1] = inf;
		previous[0] = -1;
		succ[0] = 1;
		previous[n+1] = n;
		succ[n+1] = -1;
		bool flag = 0;
		for(int i=1; i<=n; i++)
		{
			int ans=0; 
			if(flag) goto skip;
			todo[(i+1)%2].clear();
			for(int x: todo[i%2])
			{
				dirty[x] = 0;
				dmg[x] = atk[previous[x]] + atk[succ[x]];
			}
			for(int x: todo[i%2]) if(dmg[x] > def[x])
			{
				ans++;
				previous[succ[x]] = previous[x];
				
				succ[previous[x]] = succ[x];
				
				if(!dirty[previous[x]] && previous[x] != 0)
				{
					todo[(i+1)%2].push_back(previous[x]);
					dirty[previous[x]] = 1;
				}
				if(!dirty[succ[x]] && succ[x] != n+1)
				{
					todo[(i+1)%2].push_back(succ[x]);
					dirty[succ[x]] = 1;
				}
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
