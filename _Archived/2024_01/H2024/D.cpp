#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long ll;
//#define DEBUG

#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif
const int inf = 0x3f3f3f3f;
int pr[N], su[N];
pii a[N], b[N];
bool cmp(pii x, pii y)
{
	return x.first > y.first;
}
void rem(int x)
{
	su[pr[x]] = su[x];
	pr[su[x]] = pr[x];
	pr[x] = inf;
	su[x] = inf;
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
		int m, n;
		n = 0;
		scanf("%d", &m);
		su[0] = 1; pr[0] = inf;
		a[0] = pii(-1, 0);
		int cnt0 = 0;
		for(int i=1; i<=m; i++)
		{
			int x;
			scanf("%d", &x);
			if(x == 0) cnt0++;
			if(x != a[n].first)
			{
				n++;
				a[n] = pii(x, n);
				b[n] = a[n];
			}
		}
		if(cnt0 != 1)
		{
			printf("NO\n");
			continue;
		}
		sort(b+1, b+n+1, cmp);
		for(int i=1; i<=n; i++)
		{
			pr[i] = i-1;
			su[i] = i+1;
		}
		
		pr[n+1] = n; su[n+1] = n+2;
		pr[n+2] = n+1; su[n+2] = inf;
		a[n+1] = pii(-1, n+1);
		a[n+2] = pii(-2, n+2);
		for(int i=1; i<=n; i++)
		{
			int t = b[i].second;
			if(pr[t] == inf) continue;
			if(a[t].first == a[pr[t]].first + 1 || a[t].first == a[su[t]].first + 1)
			{
				if(a[pr[t]].first == a[su[t]].first)
					rem(su[t]);
				rem(t);
			}
			else 
			{
				printf("NO\n");
				goto fin;
			}
		}
		printf("YES\n");
		fin:
			;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
