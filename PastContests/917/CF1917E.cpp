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
const ll N = 1010;
#endif
bool a[N][N];
int n, m;
void out()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++) printf("%d ", a[i][j]);
		printf("\n");
	}
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
		scanf("%d%d", &n, &m);
		if(m%2)
		{
			printf("No\n");
			continue;
		}
		if(m % 4 == 0)
		{
			printf("Yes\n");
			int t = m/4;
			for(int i=0; i<n*n/4; i++)
			{
				int x = i/(n/2);
				int y = i%(n/2);
				bool f = i<t;
				a[x*2][y*2] = f;
				a[x*2][y*2+1] = f;
				a[x*2+1][y*2] = f;
				a[x*2+1][y*2+1] = f;
			}
			out();
		}
		else
		{
			if(m == 2 || m == n*n-2)
			{
				if(n == 2) printf("Yes\n1 0 \n0 1 \n");
				else printf("No\n");
			}
			else if(m == 6)
			{
				printf("Yes\n");
				for(int i=0; i<n; i++)
					for(int j=0; j<n; j++) a[i][j] = 0;
				a[0][0] = 1;
				a[0][1] = 1;
				a[1][0] = 1;
				a[1][2] = 1;
				a[2][1] = 1;
				a[2][2] = 1;
				out();
			}
			else
			{
				printf("Yes\n");
				a[0][0] = 0;
				a[0][1] = 0;
				a[0][2] = 1;
				a[0][3] = 1;
				a[1][0] = 0;
				a[1][1] = 1;
				a[1][2] = 0;
				a[1][3] = 1;
				a[2][0] = 1;
				a[2][1] = 0;
				a[2][2] = 0;
				a[2][3] = 1;
				a[3][0] = 1;
				a[3][1] = 1;
				a[3][2] = 1;
				a[3][3] = 1;
				int t = (m-10) / 4;
				for(int i=0; i<n*(n-4)/4; i++)
				{
					int x = i/(n/2) + 2;
					int y = i%(n/2);
					bool f = i<t;
					a[x*2][y*2] = f;
					a[x*2][y*2+1] = f;
					a[x*2+1][y*2] = f;
					a[x*2+1][y*2+1] = f;
				}
				for(int i=n*(n-4)/4; i<n*n/4 - 4; i++)
				{
					int j = i-(n*(n-4)/4);
					int x = j/(n/2-2);
					int y = j%(n/2-2) + 2;
					bool f = i<t;
					a[x*2][y*2] = f;
					a[x*2][y*2+1] = f;
					a[x*2+1][y*2] = f;
					a[x*2+1][y*2+1] = f;
				}
				out();
			}
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
