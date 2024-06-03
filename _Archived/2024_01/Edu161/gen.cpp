#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
typedef long long ll;
ll n;
int main()
{
	freopen("1.txt", "w", stdout);
	srand(time(NULL));
	printf("100\n");
	for(int i=0; i<100;i++)
	{
		int t = rand() % 10 + 1;
		printf("%d\n", t);
		for(int j=0; j<t; j++) printf("%d ", rand() % 1024 + 1);
		printf("\n");
		for(int j=0; j<t; j++) printf("%d ", rand() % 1024 + 1);
		printf("\n");
	}
 	return 0;
}
