#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll n;
int a[200200];
int main()
{
	//freopen("1.txt", "r", stdin);
	int z;
	cin >> z;
	while(z--)
	{
		int n, k, x;
		scanf("%d%d%d", &n, &k, &x);
		for(int i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		int rb = n-1;
		int profit = 0, maxprofit = 0;
		for(int i=n-1; i>=n-k && i>=0; i--)
		{
			if(i-x >= 0)
				profit += a[i] - 2*a[i-x];
			else profit += a[i];
			if(profit > maxprofit)
			{
				maxprofit = profit;
				rb = i-1;
			}
		}
		for(int i=rb; i>rb-x && i>=0; i--) 
		{
			a[i] = -a[i];
		}
		int ans=0;
		for(int i=0;i<=rb; i++) ans += a[i];
		printf("%d\n", ans);
	}
 	return 0;
}
