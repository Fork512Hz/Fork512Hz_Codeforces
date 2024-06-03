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
const ll N = 200010;
#endif
int a[N], b[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n, m;
		bool ans = 1;
		scanf("%d%d", &n, &m);
		if(m == 1)
		{
			int t;
			for(int i=0; i<m; i++) for(int j=0; j<n; j++) scanf("%d", &t);
			printf("yes\n");
			continue;
		}
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		for(int i=0; i<n; i++) scanf("%d", &b[i]);
		int auth1 = a[0]; 
		int auth2 = b[0];
		a[n] = -1;
		b[n] = -1;
		bool flag;
		int i = 1;
		int j = 1;
		int pos1, pos2;
		while(i < n || j < n)
		{
			if(a[i] == b[0])
			{
				pos2 = i;
				i++;
			}
			if(b[j] == a[0]) 
			{
				pos1 = j;
				j++;
			}
			if(a[i] == b[j]) 
			{
				i++; j++;
			}
			else
			{
				ans = 0;
				break;
			}
		}
		a[0] = 99999999;
		b[0] = 99999999;
		i = n-1;
		for(; ; i--)
		{
			if(a[i] == b[pos1-1]) break;
			a[i+1] = a[i];
			
			
		}
		a[i+1] = auth1;
		if(pos1 == pos2) flag = 1;
		else flag = 0;
		for( i=3; i<=m; i++)
		{
			int k=1, x, auth;
			scanf("%d", &auth);
			for(int j=1; j<n; j++) 
			{
				if(a[k] == auth) k++;
				scanf("%d", &x);
				if(flag && (a[k] == auth1 || a[k] == auth2) && (x == auth1 || x == auth2))
				{
					flag = 0;
					if(a[k] != x)
					{
						int t;
						t = a[k];
						a[k] = a[k+1];
						a[k+1] = t;
					}
				}
				if(x != a[k])
				{
					ans = 0;
				}
				else k++;
				
			}
		} 
		if(ans) printf("yes");
		else printf("no");
		printf("\n");
		end:;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
