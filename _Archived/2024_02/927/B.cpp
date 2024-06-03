#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;


#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 1000;
#endif
int a[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n;
		scanf("%d", &n);
		for(int i=0;i<n; i++)
		{
			scanf("%d", &a[i]);
		}
		int sum = a[0];
		for(int i=1; i<n; i++)
		{
			int r = sum%a[i];
			if(r == 0) sum += a[i];
			else sum += a[i]-r;
		}
		printf("%d\n", sum);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
