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
const ll N = 400100;
#endif
char s[N];
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
		scanf("%s", s);
		for(int i=0; i<n; i++) a[i] = s[i] - 48;
		for(int i=1; i<n; i++) a[i] += a[i-1];
		int carry = 0;
		for(int i=n-1; i>=0; i--)
		{
			a[i] += carry;
			carry = a[i]/10;
			a[i]%=10;
		}
		bool flag = true;;
		if(carry > 0)
		{
			flag = false;
			printf("%d", carry);
		}
		for(int i=0; i<n; i++)
		{
			if(a[i] != 0) flag = false;
			if(flag && a[i] == 0) ;
			else printf("%d", a[i]);
		}
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
