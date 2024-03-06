#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int N = 200020;
const int INF = 0x7f7f7f7f;
ll z;
int a[N], b[N], mn[N/2];
vector<int> factor;
int gcd(int a, int b)
{
	int x=a, y=b;
	int t;
	if(x>y)
	{
		
		t=x; x=y; y=t;
	}
	while(a)
	{
		t = b%a;
		b = a;
		a = t;
	}
	return b;
}
int main()
{
	
	cin >> z;
	while(z--)
	{
		factor = {1};
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		if(n == 1)
		{
			printf("1\n");
			continue;
		}
		int ans=1;
		for(int i=2; i*i<=n; i++) if(n % i == 0)
		{
			factor.push_back(i);
			if(i*i != n) factor.push_back(n/i);
		}
		for(int x: factor)
		{
			int mina = INF;
			memset(mn, 0x7f, sizeof(int) * x);
			for(int i=0; i<n; i++)
			{
				int r = i%x;
				if(a[i] < mn[r]) mn[r] = a[i];
			}
			for(int i=0; i<n; i++)
			{
				int r = i%x;
				b[i] = a[i] - mn[r];
				if(b[i] < mina && b[i] != 0) mina = b[i];
			}
			for(int i=0; i<n; i++) if(b[i] != 0)
			{
				mina = gcd(mina, b[i]);
				if(mina == 1) break;
			}
			if(mina > 1) ans++;
		}
		printf("%d\n", ans);
	}
 	return 0;
}
