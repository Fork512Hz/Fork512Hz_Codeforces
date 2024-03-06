#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll n;
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
	printf("%d %d %d", gcd(1001,182), gcd(222,303), gcd(0, 6));
 	return 0;
}
