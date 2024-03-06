#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
typedef long long ll;
#define DEBUG
#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = //TODO
#endif
bool occ[27];
using namespace std;

int main()
{
    #ifdef DEBUG
   // freopen("1.txt", "r", stdin);
    #endif
	int z;
	cin >> z;
	while(z--)
	{
		int n, k, m;
		char s[1010];
		char ans[1010];
		scanf("%d%d%d",&n, &k, &m);
		for(int j=0; j<k; j++) occ[j] = 0;
		scanf("%s", s);
		int cnt = 0, p = 0;
		for(int i=0; i<m; i++) if(!occ[s[i]-'a'])
		{
			occ[s[i]-'a'] = 1;
			cnt ++;
			if(cnt == k)
			{
				ans[p] = s[i];
				p++;
				cnt = 0;
				for(int j=0; j<k; j++) occ[j] = 0;
			} 
		}
		if(p >= n)
		{
			printf("Yes\n");
		}
		else
		{
			int j;
			for(j=0; j<k; j++) if(!occ[j]) break;
			char ch = 'a' + j;
			for(; p<n; p++) ans[p] = ch;
			ans[n] = '\0';
			printf("No\n%s\n", ans);
		}
	}
    
 	return 0;
}
