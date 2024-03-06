#include<cstdio>
int main()
{
	freopen("1.txt", "w", stdout);
	printf("1000 999\n");
	for(int i=1; i<=999; i++) 
		printf("%d %d 100000\n", i, i+1);
	for(int i=1; i<=1000; i++) 
		printf("1000 ");
	printf("\n");
	return 0;
}