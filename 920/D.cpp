#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll N = 200020;
ll n;
ll a[N], b[N];
bool cmp(int x, int y)
{
	return x>y;
}
int main()
{
	ll z;
	cin >> z;
	while(z--)
	{
		ll n,m;
		scanf("%lld%lld", &n, &m);
		for(ll i=0; i<n; i++) scanf("%lld", &a[i]);
		for(ll i=0; i<m; i++) scanf("%lld", &b[i]);
		sort(a, a+n);
		sort(b, b+m, cmp);
		ll left = n-1;
		ll right = m-1;
		ll ans = 0;
		for(ll i=0; i<n; i++)
		{
			ans += abs(a[i] - b[i]);
		}
		ll tmp = ans;
		for(; left>=0; left--, right--)
		{
			tmp -= abs(a[left] - b[left]);
			tmp += abs(a[left] - b[right]);
			if(tmp > ans) ans = tmp;
		}
		printf("%lld\n", ans);
	}
 	return 0;
}
