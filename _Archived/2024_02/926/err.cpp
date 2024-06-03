#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,k;
vector<int > vec[N];
int num[1<<20|1],f[1<<20|1];
bool vis[1<<20|1];
void dfs(int u,int fa){
	for(int v:vec[u]){
		if(v==fa) continue;
		dfs(v,u);
		num[u]^=num[v];
	}
	if(u>1) vis[num[u]]=1;
}
void solve(){
	
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		num[a]|=(1<<i-1);
		num[b]|=(1<<i-1);
	}
	for(int i=1;i<(1<<k);i++) f[i]=1e9;
	f[0]=0;
	dfs(1,0);
	for(int i=1;i<(1<<k);i++){
		if(vis[i]==0) continue;
		for(int j=(1<<k)-1;j>=0;j--)
			f[j|i]=min(f[j|i],f[j]+1);
	}
	printf("%d\n",f[(1<<k)-1]);
	for(int i=1;i<=n;i++) vec[i].clear();
	for(int i=1;i<=n;i++) num[i]=0;
	for(int i=0;i<(1<<k);i++) vis[i]=0;
}
int main(){
	int t;
	freopen("1.txt",  "r", stdin);
	scanf("%d",&t);
	while(t--) solve();
} 