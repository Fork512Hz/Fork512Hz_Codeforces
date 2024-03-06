#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 200100;
#endif
int d[N];
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
		string a, b;
		scanf("%d", &n);
		cin >> a >> b;
		for(int i=0; i<n-1; i++) d[i] = b[i] - a[i+1];
		int down = -1;
		int up = n-1;
		printf("%c", a[0]);
		for(int i=0; i<n-1; i++)
		{
			if(d[i] == -1)
			{
				up = i;
				printf("0");
				for(int j=i+1; j<n-1; j++) printf("%c", b[j]);
				break;
			}
			else if(d[i] == 1)
			{
				down = i;
				printf("0");
			}
			else printf("%c", b[i]);
		}
		printf("%c\n%d\n", b[n-1], up-down);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
