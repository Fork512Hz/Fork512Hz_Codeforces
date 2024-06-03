#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
#include<ctime>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long ll;


int main()
{
	srand(time(NULL));
	freopen("1.txt", "w", stdout);
	printf("%d\n", 100);
	for(int i=0; i<100; i++)
	{
		printf("5\n");
		for(int j=1; j<=5; j++)
			printf("%d ", rand() % 15 + 1);
		printf("\n");
	}
 	return 0;
}
