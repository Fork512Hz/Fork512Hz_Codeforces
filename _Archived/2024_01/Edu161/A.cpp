#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll n;
int main()
{
	int z;
	cin >> z;
	while(z--)
	{
		scanf("%d", &n);
		string a, b, c;
		cin >> a >> b >> c;
		for(int i=0; i<n; i++)
		{
			if(a[i] != b[i])
			{
				if(c[i] != a[i] && c[i] != b[i])  {
				printf("YES\n");
				goto ff;
				}
			}
			else
			{
				if(c[i] != a[i]) 
				{
					printf("YES\n");
					goto ff;
				}
			}
		}
		printf("NO\n");
		ff: ;
	}
 	return 0;
}
