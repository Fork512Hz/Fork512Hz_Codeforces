#include<cstdio>
using namespace std;
int main()
{
    freopen("2.txt", "r", stdin);
    freopen("1.txt", "w", stdout);
    int a[101], b[101];
    for(int i=0; i<100; i++) scanf("%d", &a[i]);
    for(int i=0; i<100; i++) scanf("%d", &b[i]);
    printf("1\n100 300\n");
    for(int i=0; i<100; i++) 
    	printf("%d %d\n", a[i], b[i]);
 	return 0;
}
