#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 200010;
#endif
int a[N];
int order[N], ans[N];
char s[N];
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
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		scanf("%s", s);
		ans[n+1] = 1;
		int k = 1, l = n;
		for(int i=0; i<n; i++) if(s[i] == 'L')
		{
			order[i+1] = a[k];
			k++;
		}
		else
		{
			order[i+1] = a[l];
			l--;
		}
		for(int i=n; i>=1; i--) 
			ans[i] = ans[i+1] * order[i] % m;
		for(int i=1; i<=n; i++) printf("%d ", ans[i]);
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
