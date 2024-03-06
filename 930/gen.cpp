#include<cstdio>
#include<cmath>
#include<iomanip>
#include<iostream>
typedef long long ll;
using namespace std;

int main()
{
	for(int i=2; i<=30; i++)
	{
		int x = 1<<i;
		for(int j=-1; j<=1; j++)
			cout << fixed << setprecision(0) << pow(2,log2(x)) << ' ';
			cout << endl;
	}
 	return 0;
}
