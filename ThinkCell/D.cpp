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
const ll N = 1000010;
#endif
char a[N];
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
		scanf("%s", a);
		ll ans=0;
		for(int i=0; i<n; i++)
		{
			int t = -1;
			int s = 0;
			for(int j=i; j<n; j++)
			{
				if(j > t && a[j] == '1')
				{
					t = j+2;
					s++;
				}
				ans += s;
			}
		}
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
