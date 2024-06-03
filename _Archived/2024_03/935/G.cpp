#include<cstdio>
#include<iostream>
#include<queue>
#include<deque>
#include<tuple>
#include<vector>
using namespace std;
typedef long long ll;
struct pii{
	ll prior, len, tins;
	pii(){
	}
	pii(ll p, ll q, ll r): prior(p), len(q), tins(r)
	{
	}
};
//#define DEBUG

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 300100;
#endif
pii ogq[N]; // for "Original queue"
ll sfm[N]; // for "Suffix max"
vector<pii> hold[N];
class cmp{
	public:
		bool operator()(const pii& x, const pii& y) 
		{
			if(x.prior != y.prior) return x.prior < y.prior;
			if(x.tins != y.tins) return x.tins > y.tins;
			return x.len > y.len;
		}
};

int main()                       
{
	#ifdef DEBUG
	freopen("1.txt", "r", stdin);
	#endif
    int z;
    cin >> z;
//    bool flag = 1;
//    if(z == 500) flag = 0;
    while(z--)
    {
    	
        int n, T;
        scanf("%d%d", &n, &T);
        for(int i=0; i<=T; i++) hold[i].clear();
        priority_queue<pii, vector<pii>, cmp> prq;
        for(int i=0; i<n; i++) 
        {
            int x, y;
            scanf("%d%d", &x, &y);
            ogq[i] = pii(x, y, i);
        }
//        if(!flag && z == 236)
//        {
//        	printf("%d %d\n", n, T);
//        	for(int i=0; i<n/2; i++) printf("%d %d\n", ogq[i].first, ogq[i].second);
//        	//for(int i=n/2; i<n; i++) printf("%d %d\n", ogq[i].first, ogq[i].second);
//        	return -1000;
//		}
        sfm[n] = -1;
        for(int i=n-1; i>=0; i--)
            sfm[i] = max(ogq[i].prior, sfm[i+1]);
        int k = 0;
        for(int t=0; t<T; t++)
        {
        	
        	if(!prq.empty() && prq.top().prior> sfm[k])
    		{
    			pii cur = prq.top();
    			if(t + cur.len <= T) 
    				hold[t + cur.len].push_back(pii(cur.prior, cur.len, t+cur.len));
    			prq.pop();
			}
			else
			{
				pii cur = ogq[k];
				if(t + cur.len <= T) 
					hold[t + cur.len].push_back(pii(cur.prior, cur.len, t+cur.len));
				k++;
				if(k >= n) 
				{
//					if(flag)
						printf("%d\n", t+1);
					goto fin;
				}
			}
			for(pii x: hold[t]) prq.push(x);
		}
//		if(flag)
			printf("-1\n");
		fin:;
    }
    return 0;
}