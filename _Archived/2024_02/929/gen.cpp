#include<cstdio>
using namespace std;

int main()
{
    freopen("1.txt", "w", stdout);
    printf("1\n1000 1000\n");
    for(int i=0; i<1000000; i++) 
    {
    	printf("0 ");
    	if((i+1) % 1000 == 0) printf("\n");
	}
 	return 0;
}
