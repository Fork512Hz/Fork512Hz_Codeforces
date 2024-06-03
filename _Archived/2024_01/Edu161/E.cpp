#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll n;

void solve(ll x)
{
	int i=0;
	bool a[64];
	while(x)
	{
		a[i] = x & 0x1;
		x >>= 1;
		i++;
	}
	i--;
	int sum=i;
	for(int j=i-1; j>=0; j--) sum+=a[j];
	printf("%d\n", sum);
	for(int j=0; j<i; j++) printf("%d ", j);
	for(i--; i>=0; i--) if(a[i]) printf("%d ", i);
	printf("\n");
}
int main()
{
	int z;
	cin >> z;
	while(z--)
	{
		ll x;
		scanf("%lld", &x);
		solve(x);
	}
 	return 0;
}
