#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<deque>
typedef long long ll;
using namespace std;
const int INF = 0x7fffffff;
//#define DEBUG
//#define DEBUG2
#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 200100;
#endif

struct TreeEdge{
	int id, target;
	
	TreeEdge(){
	}
	TreeEdge(int x, int y):
	id(x), target(y)
	{
	}
};

struct Node{
	int id, dsu, dfn, low, parent, parentEdgeId;
	int vis;
	vector<TreeEdge> conn;
	
	Node()
	{
	}
	
	int find();
	int tarjan(int, int);
};

struct Edge{
	int id, x, y, wt;
	bool tag;
	
	Edge(){
	}
	Edge(int a, int b, int c, int d):
	id(a), x(b), y(c), wt(d), tag(0)
	{
	}
	
};

Edge edges[N];
Node nodes[N];
ll cnt;

int Node::find()
{
	if(dsu == -1) return id;
	int tmp = nodes[dsu].find();
	dsu = tmp;
	return tmp;
}

void dsuMerge(int x, int y)
{
	int find1 = nodes[x].find();
	int find2 = nodes[y].find();
	if(find1 != find2) nodes[find2].dsu = find1;
}

int Node::tarjan(int _parent, int _parentEdgeId)
{
	if(vis >= 1) 
	{
		#ifdef DEBUG2
		printf("Tarjan %d: low = %d(Visited)\n", id, low);
		#endif
		return dfn;
	}
	
	cnt++;
	dfn = cnt;
	parent = _parent;
	parentEdgeId = _parentEdgeId;
	vis = 1;
	low = dfn;
	#ifdef DEBUG2
	printf("Tarjan %d: parent=%d, dfn=%d\n", id, parent, dfn);
	#endif
	for(TreeEdge i: conn) if(i.target != parent)
	{
		low = min(low, nodes[i.target].tarjan(id, i.id));
	}
	#ifdef DEBUG2
	printf("Tarjan %d: low = %d\n", id, low);
	#endif
	if(low == dfn && dsu != -1) 
	{
		#ifdef DEBUG2
		printf("Bridge(%d, %d)\n", id, parent);
		#endif
		edges[_parentEdgeId].tag = 1; 
	}
	
	return low;
}


int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    cin >> z;
    while(z--){
    	//build graph
		int v, e;
		scanf("%d%d", &v, &e);
		for(int i=1; i<=v; i++) 
		{
			Node &t = nodes[i];
			t.id = i;
			t.dsu = -1;
			t.conn.clear();
			t.dfn = INF;
			t.low = INF;
			t.vis = 0;
		}
		for(int i=1; i<=e; i++)
		{
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			edges[i] = Edge(i, x, y, w);
			nodes[x].conn.push_back(TreeEdge(i, y));
			nodes[y].conn.push_back(TreeEdge(i, x));
			dsuMerge(x, y);
		}
		for(int i=1; i<=v; i++) if(nodes[i].dsu == -1){
			#ifdef DEBUG2
			printf("Root %d\n", i);
			#endif
			cnt = 0;
			nodes[i].tarjan(0, 0);
		}
		int last = -1;
		int minw = INF;
		for(int i=1; i<=e; i++) if(!edges[i].tag && edges[i].wt < minw)
		{
			last = i;
			minw = edges[i].wt;
		}
		Edge &ans = edges[last];
		printf("%d ", ans.wt);
		int source = ans.x;
		int target = ans.y;
		nodes[source].parent = target;
		nodes[source].vis = 2;
		deque<int> bfs = {source, -1};
		int depth = 0;
		while(1)
		{
			int cur = bfs.front();
			bfs.pop_front();
			if(cur < 0)
			{
				bfs.push_back(cur-1);
				depth = -cur;
				continue;
			}
			for(TreeEdge i: nodes[cur].conn) if(nodes[i.target].vis <= 1 && i.target != nodes[cur].parent)
			{
				nodes[i.target].parent = cur;
				nodes[i.target].vis = 2;
				bfs.push_back(i.target);
				if(i.target == target) goto output;
			}
		}
		output:
		printf("%d\n%d", depth+2, source);
		int k = target;
		while(k != source)
		{
			printf(" %d", k);
			k = nodes[k].parent;
		}
		printf("\n");
    }
 	return 0;
}
