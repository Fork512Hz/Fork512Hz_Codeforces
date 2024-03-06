#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;


#define MULTI


int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    char s[1010];
    while(z--){
		int n;
		scanf("%d", &n);
		scanf("%s", s);
		int t = 0;
		int ans=0;
		for(int i=0; i<n; i++)
		{
			if(s[i] == '*')
			{
				t++;
				if(t >= 2) break;
			}
			else
			{
				 t=0;
				 if(s[i] == '@') ans++;
			}
			
		}
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
