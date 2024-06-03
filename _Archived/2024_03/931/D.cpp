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
const ll N = 100000;
#endif
bool sw, r1, r2;
void out(int a, int b)
{
	if(sw) printf("? %d %d\n", b, a);
	else printf("? %d %d\n", a, b);
	fflush(stdout);
}
void ans(int a, int b)
{
	if(sw) printf("! %d %d\n", b, a);
	else printf("! %d %d\n", a, b);
	fflush(stdout);
}
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
		scanf("%d%d", &n, &m);
		if(n>m) 
		{
			sw = 1;
			int t=n; n=m; m=t;
		}
		else sw = 0;
		int dist1, dist2;
		out(1, 1);
		scanf("%d", &dist1);
		out(1, m);
		scanf("%d", &dist2);
		int p3x, p3y;
		if(1+dist1 < m-dist2)
		{
			
			if(1+dist1 <= n)
			{
				p3x = 1+dist1;
				p3y = 1;
			}
			else
			{
				p3x = n;
				p3y = dist1+2 - n;
			}
			out(p3x, p3y);
			int fin;
			scanf("%d", &fin);
			ans(p3x-fin/2, p3y+fin/2);
		}
		else
		{
			int douby = dist1+2+m-1-dist2;
			int doubx = dist1+2-m+1+dist2;
			p3x = doubx / 2;
			p3y = douby / 2;
			out(p3x, p3y);
			int dist3;
			scanf("%d", &dist3);
			if(douby & 1)
			{
				if(dist3 & 1) ans(p3x+dist3/2+1, p3y-dist3/2);
				else ans(p3x+dist3/2, p3y+dist3/2);
			} 
			else
			{
				if(dist3 == 0)
					ans(p3x, p3y);
				else 
				{
					out(p3x+dist3/2, p3y+dist3/2);
				int fin;
				scanf("%d", &fin);
				if(fin == 0)
					ans(p3x+dist3/2, p3y+dist3/2);
				else
					ans(p3x+dist3/2, p3y-dist3/2);
				}
			}
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
