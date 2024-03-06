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
const ll N =200100;
#endif
int a[N];
inline bool cmp(int x, int y)
{
	return x>y;
}
int trail(int x)
{
	int t=x;
	int d = 0;
	while(t)
	{
		if(t%10 == 0)
		{
			t/=10;
			d++;
		}
		else break;
	}
	return d;
}
int dig(int x)
{
	int t=x;
	int d = 0;
	while(t)
	{
		t/=10;
		d++;
	}
	return d;
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
		int n, crit, sum, m;
		sum = 0;
		scanf("%d%d", &n, &m);
		m++;
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%d", &x);
			a[i] = trail(x);
			sum += dig(x);
		}
		sort(a, a+n, cmp);
		for(int i=0; i<n; i+=2) sum -= a[i];
		if(sum >= m) printf("Sasha\n");
		else printf("Anna\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
