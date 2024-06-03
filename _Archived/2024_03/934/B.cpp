#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
typedef long long ll;
using namespace std;
const int N = 100010;
int a[N];
int vis[N];
vector<int> dup0, dup1, nodup;
int main()
{
    int z;
    scanf("%d", &z);
    while(z--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        memset(vis, 0, sizeof(int) * (n+3));
        dup0.clear();
        nodup.clear();
        dup1.clear();
        for(int i=0; i<2*n; i++) scanf("%d", &a[i]);
        for(int i=0; i<n; i++) vis[a[i]] ++;
        for(int i=1; i<=n; i++)
        {   
            if(vis[i] == 0) dup1.push_back(i);
            if(vis[i] == 2) dup0.push_back(i);
            if(vis[i] == 1) nodup.push_back(i);
        }
        int nd = dup1.size();
		int ndup = min(nd, k);
        for(int i=0; i<ndup; i++)
            printf("%d %d ", dup0[i], dup0[i]);
        for(int i=2*ndup; i<2*k; i++)
            printf("%d ", nodup[i-2*ndup]);
        printf("\n");
        for(int i=0; i<ndup; i++)
            printf("%d %d ", dup1[i], dup1[i]);
        for(int i=2*ndup; i<2*k; i++)
            printf("%d ", nodup[i-2*ndup]);
        printf("\n");
    }
    return 0;
}