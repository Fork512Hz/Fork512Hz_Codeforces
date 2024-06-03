#include<bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "E:/OI/normal/templates/debug.h"
#else
#define dbg(...) (void)0
#define msg(...) (void)0
#endif
#define ll long long
#define PB emplace_back
#define PPB pop_back
#define MP make_pair
#define ALL(Name) Name.begin(),Name.end()
#define PII pair<int,int>
#define VI vector<int>
#define GI greater<int>
#define fi first
#define se second

const int N=500005;
int n,a[N];
struct evt
{
	int ti,id;
	bool come;
	bool operator<(const evt &rhs)const
	{
		return ti!=rhs.ti?ti<rhs.ti:come>rhs.come;
	}
}b[N<<1];
struct cmp{bool operator()(int x,int y)const
{return a[x]==a[y]?x<y:a[x]<a[y];}};
set<int,cmp>st;
struct E
{
	int u,v,w;
	bool operator<(const E &rhs)const
	{
		return w<rhs.w;
	}
}e[N<<1];int tot;
void add(int u,int v,int w){e[++tot]={u,v,w};}
int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int _;cin>>_;while(_--)
{
	cin>>n;
	for(int i=1,l,r;i<=n;i++)cin>>l>>r>>a[i],b[2*i-1]={l,i,1},b[2*i]={r,i,0};
	sort(b+1,b+(n<<1)+1);
	tot=0;st.clear();
	for(int i=1;i<=n<<1;i++)
		if(b[i].come)
		{
			auto it=st.insert(b[i].id).fi;
			if(it!=st.begin())add(b[i].id,*prev(it),a[b[i].id]-a[*prev(it)]);
			if(next(it)!=st.end())add(b[i].id,*next(it),-a[b[i].id]+a[*next(it)]);
		}
		else st.erase(b[i].id);
	iota(fa+1,fa+n+1,1);
	ll ans=0;int cnt=0;
	sort(e+1,e+tot+1);
	for(int i=1;i<=tot;i++)
	{
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v)ans+=e[i].w,fa[u]=v,++cnt;
	}
	cout<<(cnt+1==n?ans:-1)<<endl;
}

	return 0;
}