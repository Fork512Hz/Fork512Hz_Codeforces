#include<cstdio>
#include<cstdlib>
#include<ctime>
int main()
{
	printf("1\n200000 9941\n6176");
	srand(220049317);
	for(int i=2; i<=200000; i++) printf(" %d", rand()%9940+1);
	printf("\n");
	for(int i=1; i<=200000; i++) printf("L");
	printf("\n");
}
