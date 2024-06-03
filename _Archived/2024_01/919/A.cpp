#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
ll n;
vector<int> out;
int main()
{
	int z;
	cin >> z;
	
	while(z--)
	{
		out.clear();
		cin >> n;
		int lb, rb;
		lb = -100000;
		rb = 0x7fffffff;
		for(int i=0; i<n; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			if(a == 1) lb = max(lb, b);
			else if(a == 2) rb = min(rb, b);
			else out.push_back(b);
		}
		int ans = rb - lb + 1;
		if(ans <= 0)
		{
			printf("0\n");
			continue;
		}
		for(int x: out) if(x>=lb && x<=rb) ans--;
		printf("%d\n", ans);
	}
 	return 0;
}
