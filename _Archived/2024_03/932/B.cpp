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
const ll N = 100010;
#endif
int a[N];
int fi[N], la[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n;
		scanf("%d", &n);
		memset(fi, 0xff, sizeof(fi));
		memset(la, 0xff, sizeof(la));
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		for(int i=0; i<n; i++) if(fi[a[i]] == -1)
			fi[a[i]] = i;
		for(int i=n-1; i>=0; i--) if(la[a[i]] == -1)
			la[a[i]] = i;
		int x, y;
		x = 0;
		y = n-1;
		for(int i=0; i<n; i++) if(fi[i] >= 0)
			x = max(x, fi[i]);
			else break;
		for(int i=0; i<n; i++) if(la[i] >= 0)
			y = min(y, la[i]);
			else break;
		if(x < y)
		{
			printf("2\n1 %d\n%d %d\n", x+1, x+2, n);
		}
		else printf("-1\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
