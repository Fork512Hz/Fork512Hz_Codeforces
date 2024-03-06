#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int dp[1<<20];
int n,m,a[100005];
vector<int>g[100005];
void dfs(int u,int fa) {
	for(int v:g[u]) {
		if(v==fa)continue;
		dfs(v,u);
		a[u]^=a[v];
	}
}
int main() {
	freopen("1.txt",  "r", stdin);
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			g[i].clear();
			a[i]=0;
		}
		for(int i=1; i<n; i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		scanf("%d",&m);
		for(int i=0; i<m; i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			a[u]^=(1<<i),a[v]^=(1<<i);
		}
		dfs(1,0);
		sort(a+1,a+1+n);
		n=unique(a+1,a+n+1)-a-1;
		for(int i=0; i<(1<<m); i++) {
			dp[i]=(i==0?0:0x3f3f3f3f);
		}
		for(int i=0; i<(1<<m); i++) {
			for(int j=1; j<=n; j++) {
				dp[i|a[j]]=min(dp[i|a[j]],dp[i]+1);
			}
		}
		printf("%d\n",dp[(1<<m)-1]);
	}
	return 0;
}