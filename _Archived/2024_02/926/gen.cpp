#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 40000;
#endif

int main()
{
    #ifdef DEBUG
    freopen("1.txt",  "w", stdout);
    #endif
    printf("1\n%d\n", N);
    for(int i=1; i<=N-1; i++) printf("%d %d\n", i, i+1);
    printf("0\n");
    //for(int i=1; i<=20; i++) printf("%d %d\n", i*1000-999, i*1000+80000);
 	return 0;
}
