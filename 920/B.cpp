#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
	int z;
	cin >> z;
	while(z--)
	{
		int n;
		string a, b;
		cin >> n;
		cin >> a >> b;
		int diff1=0, diff2=0;
		for(int i=0; i<n; i++)
		{
			if(a[i] - b[i] == -1) diff1++;
			if(a[i] - b[i] == 1) diff2++;
		}
		printf("%d\n", max(diff1, diff2));
	}
 	return 0;
}
