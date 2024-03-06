#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll a[200020];
int main()
{
	int z;
	cin >> z;
	while(z--)
	{
		ll n, res, grad, cost;
		scanf("%lld%lld%lld%lld", &n, &res, &grad, &cost);
		for(ll i=0; i<n; i++)
			scanf("%lld", &a[i]);
		sort(a, a+n);
		ll t=0;
		for(ll i=0; i<n; i++)
		{
			ll cost1 = (a[i]-t) * grad;
			res -= min(cost, cost1);
			t = a[i];
			if(res <= 0) 
			{
				printf("no\n");
				goto out;
			}
		}
		printf("yes\n");
		out: ;
	}
 	return 0;
}
