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
const ll N = 200010;
#endif

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
		scanf("%d" ,&n);
		char s[N];
		scanf("%s", s);
		for(int i=2; i<n; i++)
		{
			if(s[i] == 'a' || s[i] == 'e')
				s[i-1] -= 32;
		}
		for(int i=0; i<n; i++)
		{
			if(s[i] < 94) printf(".%c", s[i]+32);
			else printf("%c", s[i]);
		}
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
