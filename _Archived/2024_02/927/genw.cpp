#include<cstdio>
#include<cstdlib>
#include<ctime>
int main()
{
	printf("10000\n");
	srand(261177777);
	for(int i=0; i<9999; i++)
	{
		printf("%d\n%d\n", 1, rand() % 9 + 1);
	}
	printf("390001\n");
	for(int i=0; i<390001; i++) printf("%d", i%10);
	printf("\n");
}
