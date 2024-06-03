#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N =1000010;
#endif
int a[N], b[N];
int occ[N];
int main()
{
    #ifdef DEBUG
    //freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		for(int i=0; i<m;i++) scanf("%d",&b[i]);
		for(int i=0; i<n; i++) if(a[i] <= k)
		{
			if (occ[a[i]] % 2 == 0)
			{
				occ[a[i]] ++;
			}
		}
		for(int i=0; i<m; i++) if(b[i] <= k)
		{
			if (occ[b[i]] <= 1)
			{
				occ[b[i]] += 2;
			}
		}
		int side1 = 0;
		int side2 = 0;
		for(int i=1; i<=k; i++)
		{
			if(occ[i] == 0)
			{
				printf("No\n");
				goto end;
			}
			if(occ[i] == 1) side1++;
			if(occ[i] == 2) side2++;
		}
		if(side1 > k/2 || side2 > k/2) printf("No\n");
		else printf("Yes\n");
		end:;
		memset(occ, 0, sizeof(int) * (k+1));
		
	}
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
