#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
ll a[100010];
vector<ll> elements[70], loops, loops_nor;
int main()
{
	//freopen("1.txt", "r", stdin);
	ll z;
	cin >> z;
	while(z--)
	{
		ll k, q;
		ll loop = 0;
		ll layer = 0;
		loops.clear();
		loops_nor = {0};
		scanf("%lld%lld", &k, &q);
		bool flag=false;
		for(ll i=0; i<k; i++)
		{
			ll op, x;
			scanf("%lld%lld", &op, &x);
			if(flag) continue;
			if(op == 1)
			{
				elements[layer].push_back(x);
				loop ++;
			}	
			else
			{
				loops.push_back(loop);
				layer++;
				if(log(loop) + log(x+1) >= 18.1 * log(10))
				{
					flag = true;
					loop = 1e18 + 10;
					loops_nor.push_back(1e18+10);
				}
				else 
				{
					loop *= x+1;
					loops_nor.push_back(loop);
				}
			}
		}
		loops.push_back(loop);
//		for(ll i=0; i<=layer; i++)
//		{
//			printf("%lld ", loops[i]);
//			printf("Elements[%d]: ", i);
//			for(ll x: elements[i]) printf("%d ", x);
//			printf("\n");
//		}
		ll ans;
		for(ll i=0; i<q; i++)
		{
			ll x;
			scanf("%lld", &x);
			x--;
			ll r = x % loops[layer];
			for(ll j=layer; j>=0; j--)
			{
				if(r >= loops_nor[j])
				{
					ans = elements[j][r - loops_nor[j]];
					break;
				}
				else r = r % loops[j-1];
			}
			printf("%lld ", ans);
		}
		printf("\n");
		for(ll i=0; i<=layer; i++) elements[i].clear();
	}
 	return 0;
}
