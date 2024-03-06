#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll z;
int main()
{
	cin >> z;
	while(z--)
	{
		int x[4], y[4];
		for(int i=0; i<4; i++)
		{
			scanf("%d %d", &x[i], &y[i]);
		}
		int ans = 0;
		for(int i=1; i<=3; i++) if(x[i]-x[0])
		{
			ans = x[i]- x[0];
			break;
		}
		printf("%d\n", ans * ans);
	}
 	return 0;
}
