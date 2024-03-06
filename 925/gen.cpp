#include<cstdio>

int main()
{
	freopen("1.txt", "w", stdout);
    printf("1\n200000 6 6\n");
    for(int i=0; i<200000; i++) printf("%d ", 200000-i);
    
 	return 0;
}
